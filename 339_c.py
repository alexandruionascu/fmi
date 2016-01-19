import sys
import math

n = raw_input()
n = int(n)

x = raw_input()
x = int(x)

y = raw_input()
y = int(y)

minimum = 1 << 60
maximum = 0

for i in range(1, n + 1):
    a = raw_input()
    a = int(a)

    b = raw_input()
    b = int(b)

    xDist = x - a
    xDist *= xDist

    yDist = y - b
    yDist *= yDist

    distance = xDist + yDist
    if maximum < distance:
        maximum = distance
    if minimum > distance:
        minimum = distance

print(math.pi * (maximum - minimum))
