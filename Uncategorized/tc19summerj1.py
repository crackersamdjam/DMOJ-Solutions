import sys
n, m = map(int, sys.stdin.readline().split())
v = 0
d = int(1e9)
while n:
    if abs(n-m) < d:
        d = abs(n-m)
        v = n
    n >>= 1

print(v)