import sys
S = sys.stdin.readline()
k = int(input())
cnt = 1
ans = 0
if(k == 1):
	ans = 1
	
for i in range(1, len(S)-1):
	if (S[i] != S[i-1]):
		cnt += 1
	if(i >= k and S[i-k] != S[i-k+1]):
		cnt -= 1
	if(i+1 >= k and cnt == 1):
		ans += 1

print(ans)