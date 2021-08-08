import sys
N = int(sys.stdin.readline())
A = sys.stdin.readline()
B = sys.stdin.readline()

dp = [None] * 1000010
a = [None] * 1000010
b = [None] * 1000010
psa = [None] * 1000010
psb = [None] * 1000010
dp[0] = dp[1] = dp[2] = dp[3] = 1000000000
psa[4] = psb[4] = dp[4] = 0

for i in range(5, N+5):
	dp[i] = 1000000000
	if A[i-5] == '1':
		a[i] = 1
	else:
		a[i] = 0
	if B[i-5] == '1':
		b[i] = 1
	else:
		b[i] = 0
	
	psa[i] = psa[i-1] + a[i]
	psb[i] = psb[i-1] + b[i]

	if a[i] == b[i]:
		dp[i] = dp[i-1]
	if a[i] == False and b[i] == True:
		dp[i] = dp[i-1] + 1
	
	if i > 6:
		dp[i] = min(dp[i], dp[i-3] + 3-(psa[i] - psa[i-3]) + 1 + (psb[i] - psb[i-3]))
	if i > 7:
		dp[i] = min(dp[i], dp[i-4] + 4-(psa[i] - psa[i-4]) + 1 + (psb[i] - psb[i-4]))

print(dp[N+4])