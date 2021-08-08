sx, sy = map(int, input().split())
ex, ey = map(int, input().split())

dis = [[99 for i in range(9)] for j in range(9)]
dis[sx][sy] = 0
q = []
q.append([sx, sy])

while q:
	x, y = q.pop(0)
	for mx, my in [[2, 1], [2, -1], [1, 2], [1, -2], [-1, 2], [-1, -2], [-2, 1], [-2, -1]]:
		nx, ny = x+mx, y+my
		if 0 < nx <= 8 and 0 < ny <= 8 and dis[x][y]+1 < dis[nx][ny]:
			dis[nx][ny] = dis[x][y]+1;
			q.append([nx, ny])

print(dis[ex][ey])