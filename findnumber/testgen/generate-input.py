#!/bin/python
from sys import argv, exit
from random import randint

if len(argv) < 3:
    print('Usage: python generate-input.py MAX_N Q')
    exit()

MAX_NUM = 10 ** 9

MAX_N = int(argv[1])
Q = int(argv[2])

n = randint(1, MAX_N)

print('{0} {1} {2}'.format(n, randint(0, n - 1), Q))

nums = set()
while len(nums) < n:
    a = randint(0, MAX_NUM)
    if not a in nums:
        nums.add(a)

print(' '.join(str(i) for i in sorted(list(nums))))
