from random import randint
from sys import argv
from os import path, getcwd

MAX_A = 10 ** 9

def generate(max_n, m, allow_eq = True):
    n = randint(0.9 * max_n, max_n)

    seq = [randint(0, MAX_A)]
    for i in range(n - 1):
        d = 0
        if seq[i] == 0:
            d = randint(0, 1) if allow_eq else 1
        elif seq[i] == MAX_A:
            d = randint(-1, 0) if allow_eq else -1
        else:
            d = randint(-1, 1) if allow_eq else randint(0, 1) * 2 - 1

        seq.append(seq[i] + d)

    outText = ' '.join([str(i) for i in seq]) + '\n'
    inText = '{0} {1}\n{2}'.format(n, m, outText)
    return (inText, outText)

def write(test, path):
    with open(path + '.in', 'w') as f:
        f.write(test[0])
    with open(path + '.sol', 'w') as f:
        f.write(test[1])

outDir = path.join(getcwd(), argv[1])

def gen_subtask(max_n, m, name, test_cnt = 5, allow_eq = True):
    for i in range(5):
        write(generate(max_n, m, allow_eq = allow_eq), path.join(outDir, '{0}-{1}'.format(name, i)))

gen_subtask(1000, 200000, '1')
gen_subtask(100000, 210000, '2')
gen_subtask(100000, 170000, '3', allow_eq = False)
gen_subtask(100000, 170000, '4')
