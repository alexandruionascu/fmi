import sys

t = sys.stdin.readline()
t = int(t)

for i in range(1, t+1):
    x = sys.stdin.readline()
    x = int(x)
    power = 1
    i = 1
    while i < x:
        power += 1
        i = i << 1

    sum = x / 2 * (x+1)
    two_pow = 1 << power
    two_pow -= 1
    two_pow *= 2

    result = sum - two_pow
    print(result)
