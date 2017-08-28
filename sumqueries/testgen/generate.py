from sys import argv
from random import randint
from os import path, getcwd

MAX_V = 10 ** 9
MIN_V = 10 ** 9

def generate(max_n, max_q):

    n = randint(0.9 * max_n, max_n)
    q = randint(0.9 * max_q, max_q)
    
    nums = [randint(-MAX_V, MAX_V) for i in range(n)]
    sums = [0]
    for i in range(n):
        sums.append(sums[i] + nums[i])

    queries = [sorted([randint(0, n - 1), randint(0, n - 1)]) for i in range(q)]
    ans = []
    for i in queries:
        ans.append(sums[i[1] + 1] - sums[i[0]])

    inText = '{0} {1}\n{2}\n{3}'.format(n, q, ' '.join([str(i) for i in nums]),\
        '\n'.join(str(i[0]) + ' ' + str(i[1]) for i in queries))
    outText = '\n'.join([str(i) for i in ans])

    return (inText, outText)

def write(test, path):
    with open(path + '.in', 'w') as f:
        f.write(test[0])
    with open(path + '.sol', 'w') as f:
        f.write(test[1])

outDir = path.join(getcwd(), argv[1])

def gen_subtask(max_n, max_q, name, test_cnt = 5):
    for i in range(5):
        write(generate(max_n, max_q), path.join(outDir, '{0}-{1}'.format(name, i)))


gen_subtask(1000, 1000, '1')
gen_subtask(100000, 100000, '2')
