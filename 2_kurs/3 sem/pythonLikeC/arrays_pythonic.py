#!/usr/bin/env python3

import random

array_of_ints = [random.randint(0, 99) for i in range(20)]

print(array_of_ints)

random.shuffle(array_of_ints)

print("---")
print(array_of_ints)
