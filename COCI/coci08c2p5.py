import sys
S = sys.stdin.readline()

add = 0
mul = 1
for i in range (len(S)-1, -1,-1):
	if(S[i] == 'L'):
		mul *= 2
	if(S[i] == 'R'):
		add += mul
		mul *= 2
	if(S[i] == '*'):
		add = add*3+mul
		mul *= 5

print(add + mul)