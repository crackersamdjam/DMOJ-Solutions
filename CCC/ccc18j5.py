n = int(input())
# I can go from a to every number in to[a]
to = [list() for i in range(n+1)]
distance = [0 for i in range(n+1)]

for i in range(1, n+1):
	a = list(map(int, input().split()))
	for j in range(1, a[0]+1):
		to[i].append(a[j])

queue = list()
queue.append(1)
distance[1] = 1

shortest = 999999999

while queue:
	current = queue.pop(0)
	if not to[current]:
		shortest = min(shortest, distance[current])
	for nx in to[current]:
		if not distance[nx]:
			queue.append(nx)
			distance[nx] = distance[current]+1

ok = True
for i in range(1, n+1):
	if not distance[i]:
		ok = False

print('Y' if ok else 'N')
print(shortest)