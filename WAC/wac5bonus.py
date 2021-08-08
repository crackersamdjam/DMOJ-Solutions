import sys
input = sys.stdin.readline

N = int(input())
G = [[] for i in range(N)]
for i in range(0, N - 1):
  a, b, c = map(float, input().split())
  a = int(a)
  b = int(b)
  a -= 1
  b -= 1
  G[a].append([b, c])
  G[b].append([a, c])


def dfs(v, prev, mn):
  ret = 0
  if prev != -1:
    ret += mn
  for e in G[v]:
    if e[0] != prev:
      ret += dfs(e[0], v, min(mn, e[1]))
  return ret


ans = float('inf')
for r in range(0, N):
  ans = min(ans, dfs(r, -1, float('inf')))
print(int(ans))