n = int(input())
a = [[] for i in range(n+1)]
for i in range(n):
	a[i] = list(map(int, input().split()))

visited = [[False for i in range(n+1)] for j in range(n+1)]
q = list()
q.append([0, 0])
visited[0][0] = True

def ok(x, y):
	return x >= 0 and x < n and y >= 0 and y < n and not a[x][y]

while q:
	x, y = q.pop(0)
	if ok(x, y+1) and not visited[x][y+1]:
		visited[x][y+1] = True
		q.append([x, y+1])

	if ok(x, y-1) and not visited[x][y-1]:
		visited[x][y-1] = True
		q.append([x, y-1])

	if ok(x+1, y) and not visited[x+1][y]:
		visited[x+1][y] = True
		q.append([x+1, y])

	if ok(x-1, y) and not visited[x-1][y]:
		visited[x-1][y] = True
		q.append([x-1, y])

print('yes' if visited[n-1][n-1] else 'no')