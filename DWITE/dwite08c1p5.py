import sys
input = sys.stdin.readline

for t in range(5):
	n = int(input().strip())
	cnt = 0
	for i in range(n):
		s = input().strip()
		while s != '':
			cnt += s.count('#')
			s = input().strip()
	print((cnt+24)//25)