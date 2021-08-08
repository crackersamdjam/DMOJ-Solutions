import sys
input = sys.stdin.readline
n = int(input())
s = input().strip()
s = reversed(s)

ans = 0

for c in s:
	if c == '1' and ans % 2 == 0:
		ans += 1
	elif c == '0' and ans % 2 == 1:
		ans += 1

print(ans)