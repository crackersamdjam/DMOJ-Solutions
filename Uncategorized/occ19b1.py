import sys
S = sys.stdin.readline().strip().lower()
if(S == "darcy_liu"):
	print('real')
elif(len(S) < 9):
	print('other user')
elif(S.startswith('darcy') and S.endswith('liu')):
	for i in range(5, len(S)-3):
		if(S[i] != '_'):
			print('other user')
			break
		if(i == len(S)-4):
			print('fake')
else:
	print('other user')