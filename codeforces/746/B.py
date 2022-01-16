from collections import defaultdict, deque
from heapq import heappush, heappop
from math import inf

ri = lambda : map(int, input().split())

def solve():
    n = int(input())
    s = input()
    q = deque()
    if n & 1:
        on = True
        for i in range(n):
            if on:
                q.append(s[i])
            else:
                q.appendleft(s[i])
            on = not on
    else:
        on = True
        for i in range(n):
            if on:
                q.appendleft(s[i])
            else:
                q.append(s[i])
            on = not on
    print("".join(list(q)))


t = 1
#t = int(input())
while t:
    t -= 1
    solve()

