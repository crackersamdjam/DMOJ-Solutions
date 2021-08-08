import sys
input = sys.stdin.readline
n, k = map(int, input().split())
cnt = [0]*(n+1)
for i in range(k):
	cnt[int(input())+1] += 1

for i in range(1, n+1):
	cnt[i] += cnt[i-1]

q = int(input())
for i in range(q):
	l, r = map(int, input().split())
	print(cnt[r+1] - cnt[l])