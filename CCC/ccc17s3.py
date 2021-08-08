import sys
input = sys.stdin.readline

n = int(input())
cnt = [0]*2001
ways = [0]*4001

for i in map(int, input().strip().split()):
	cnt[i] += 1

for i in range(2001):
	for j in range(i):
		ways[i+j] += min(cnt[i], cnt[j])
	ways[i+i] += cnt[i]//2

maxlen = 0
for i in range(4001):
	if ways[i] > maxlen:
		maxlen = ways[i]

num = 0
for i in range(4001):
	if ways[i] == maxlen:
		num += 1

print(maxlen, num)