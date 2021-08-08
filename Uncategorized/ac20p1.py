import sys
input = sys.stdin.readline
for i in range(int(input())):
	l = sorted(x*x for x in list(map(int, input().split())))
	if l[0]+l[1] == l[2]: print('R')
	else: print('A' if l[0]+l[1] > l[2] else 'O')