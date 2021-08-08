import sys
input = sys.stdin.readline
a = list()
a.append(int(input()))
a.append(int(input()))
while 1:
	b = a[-2] - a[-1]
	if b < 0:
		break;
	a.append(b)

print(len(a))