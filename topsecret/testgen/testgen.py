from random import randint 
from math import ceil
from os import path, getcwd
from sys import argv

def gen_test(max_n, q, conseq = False, limit = False):
    if limit:
        n = max_n
    else:
        n = randint(ceil(max_n * 0.9), max_n)

    if conseq:
        ans = randint(0, n)
        perm = [i for i in range(ans)] + [i for i in range(ans + 1, n + 1)]
        perm.append(ans)
    else:
        perm = [i for i in range(n + 1)]
        for i in range(n):
            k = randint(i, n)
            perm[i], perm[k] = perm[k], perm[i]
        ans = perm[n]

    inText = '{0} {1}\n{2}'.format(n, q, ' '.join([str(i) for i in perm]))
    return (inText, '')

def write(test, testname):
    with open(testname + '.in', 'w') as f:
        f.write(test[0])
    with open(testname + '.sol', 'w') as f:
        f.write(test[1])

outDir = path.join(getcwd(), argv[1])

def gen_subtask(max_n, q, name, conseq = False, test_cnt=4):
    not_limit_cnt = test_cnt - ceil(test_cnt / 2)

    for i in range(test_cnt):
        limit = i > not_limit_cnt
        test = gen_test(max_n, q, conseq, limit=limit)
        testname = path.join(outDir, name + '-' + str(i))
        write(test, testname)


gen_subtask(1000, 2000000, 'subtask1')
gen_subtask(100000, 2000000, 'subtask2')
gen_subtask(100000, 250000, 'subtask3', conseq=True)
gen_subtask(100000, 250000, 'subtask4', test_cnt = 8)
