#!/usr/bin/env python3
"""Check report totals and refusal to report an unverified CI build."""

import json
import subprocess
import tempfile
from pathlib import Path
import unittest
from unittest.mock import patch

import progress


class ProgressTest(unittest.TestCase):
    def test_totals_include_unmatched_code(self):
        units = [
            {"measures": {"total_code": 30, "matched_code": 30, "complete_code": 30,
                          "total_functions": 1, "matched_functions": 1},
             "metadata": {"complete": True}},
            {"measures": {"total_code": 70, "total_functions": 1},
             "metadata": {"complete": False}},
        ]
        report = progress.summarize(units)
        self.assertEqual(report["matched_code_percent"], 30)
        self.assertEqual(report["matched_functions_percent"], 50)
        self.assertEqual(report["complete_units"], 1)
        self.assertEqual(report["total_units"], 2)
        self.assertEqual(progress.summarize([])["matched_code_percent"], 0)

    def test_verified_report_excludes_libraries_and_unmatched_code(self):
        blocks = {
            0x0800020C: ["matched", 30, True],
            0x08000214: ["assembly", 70, False],
            min(progress.LIBRARY_BLOCKS): ["library", 40, True],
        }
        with tempfile.TemporaryDirectory() as tmp, \
             patch.object(progress, "ROOT", Path(tmp)), \
             patch("sys.argv", ["progress.py", "--check-code", "--json"]), \
             patch.object(progress.subprocess, "run"), \
             patch.object(progress, "_selftest"), \
             patch.object(progress, "parse_asm", return_value={}), \
             patch.object(progress, "func_sizes", return_value={}), \
             patch.object(progress, "c_blocks", return_value=blocks), \
             patch.object(progress, "runtime_library", return_value=set()), \
             patch("assets.assets", return_value=[]), \
             patch.object(progress.match, "matches", return_value=True) as matches:
            progress.main()
            report = json.loads((Path(tmp) / "report.json").read_text())
            self.assertEqual(report["measures"]["total_functions"], 2)
            self.assertEqual(report["measures"]["matched_functions"], 1)
            self.assertEqual(report["measures"]["matched_code_percent"], 30)
            self.assertNotIn("assembly", [call.args[0] for call in matches.call_args_list])
            self.assertEqual([u["name"] for u in report["units"]], ["matched", "assembly"])

    def test_failed_code_check_stops_report(self):
        with tempfile.TemporaryDirectory() as tmp, \
             patch.object(progress, "ROOT", Path(tmp)), \
             patch("sys.argv", ["progress.py", "--check-code", "--json"]), \
             patch.object(progress.subprocess, "run", side_effect=subprocess.CalledProcessError(1, "make")) as run, \
             patch.object(progress, "parse_asm") as parse:
            stale = Path(tmp) / "report.json"
            stale.write_text("stale report")
            with self.assertRaises(subprocess.CalledProcessError):
                progress.main()
            run.assert_called_once_with(["make", "PLATFORM=gba", "check-code"],
                                        cwd=progress.ROOT, check=True)
            parse.assert_not_called()
            self.assertFalse(stale.exists())


if __name__ == "__main__":
    unittest.main()
