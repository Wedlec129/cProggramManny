#!/usr/bin/env python3

import threading
import sys

def func(_from, _to):
    for i in range(_from, _to):
        print("{} ".format(i), end="", file=sys.stderr)

t1 = threading.Thread(target=func, args=(10, 100))
t2 = threading.Thread(target=func, args=(0, 90))
t1.start()
t2.start()
t1.join()
t2.join()
print(file=sys.stderr)
