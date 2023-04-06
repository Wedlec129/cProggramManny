#!/usr/bin/env python3

import sys

if len(sys.argv) < 3:
    print("Usage: {} <file_in> <file_out>", file=sys.stderr)
    exit(1)

open(sys.argv[2], "xb").write(open(sys.argv[1], "rb").read())
