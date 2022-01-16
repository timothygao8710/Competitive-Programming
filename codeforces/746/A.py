from collections import defaultdict, deque
from heapq import heappush, heappop
from math import inf

ri = lambda : map(int, input().split())

def solve():
    a = int(input())
    b = int(input())
    c = int(input())
    b //= 2
    c //= 4
    can = min(a,b,c)
    print(can * 7)

t = 1
#t = int(input())
while t:
    t -= 1
    solve()

