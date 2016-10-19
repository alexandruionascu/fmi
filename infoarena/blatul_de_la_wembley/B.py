from array import *


t = int(input())
for test in range(t):
    input()
    b = list(map(int,input().split(' ')))
    a = list(map(int,input().split(' ')))
    n = b[0]
    suma = b[1]
    nr = b[2]
    s = array('i',[i for i in range(0,2*n)])
    for i in range(1,n + 1):
        s[i] = s[i-1] + a[i-1]
    s = s + s;
    steps = nr//n - 1
    answer = 0
    if (steps > 0):
        if s[n] > 0:
            answer += s[n]*steps
        nr -= steps*n
    maxx = 0
    sum = 0
    for i in range(0,nr):
        sum += s[i]
        if(sum  > maxx):
            maxx = sum
    answer += maxx
    answer = suma - answer
    if(answer < 0):
        answer = 0
    print("Case #" + str(test + 1) + ": " + str(answer) + "\n")
