import sys

cache = {1: 1}


def collatz(n):
    if n not in cache.keys():
        return collatz(n >> 1 if n % 2 == 0 else 3 * n + 1) + 1
    else:
        return cache[n]


def crange(x, y):
    z = 0
    for i in range(x, y):
        if collatz(i) > z:
            z = collatz(i)
    print("{} {} {}".format(x, y, z))


if __name__ == '__main__':
    for line in sys.stdin:
        x, y = map(int, line.split(' '))
        crange(x, y)
    exit(0)
