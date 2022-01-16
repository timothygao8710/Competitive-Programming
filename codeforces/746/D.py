from collections import defaultdict, deque
from heapq import heappush, heappop
from math import inf

ri = lambda : map(int, input().split())

def solve():
    n,k,a,b = ri()
    la = 'G'
    lb = 'B'
    # a > b
    if b > a:
        a,b = b,a
        la,lb = lb, la
    if (b+1) * k < a:
        print("NO")
        return
    # valid
    consec = 0
    res = []
    for i in range(n):
        if a > b and consec < k:
            consec += 1
            res.append(la)
            a -= 1
        else:
            res.append(lb)
            b -= 1
            consec = 0
    print("".join(res))

t = 1
#t = int(input())
while t:
    t -= 1
    solve()

