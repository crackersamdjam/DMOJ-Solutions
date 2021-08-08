n = int(input())
m = int(input())
s = []
for i in range(n):
	ss = input()
	s.append([])
	for c in ss:
		s[-1].append(c)

k = int(input())
q = []
for i in range(k):
	q.append(input())

mv = [[1, 0], [0, 1], [-1, 0], [0, -1]]

def check(i, j, d):
	for c in q:
		if c == 'F':
			i += mv[d][0]
			j += mv[d][1]
		elif c == 'R':
			d -= 1
			d %= 4
		else:
			d += 1
			d %= 4

		if i < 0 or j < 0 or i >= n or j >= m or s[i][j] == 'X':
			return

	s[i][j] = '*'

for i in range(n):
	for j in range(m):
		if s[i][j] != 'X':
			for d in range(4):
				check(i, j, d)

for ss in s:
	print(''.join(ss))