h, m = map(int, input().split(':'))
t = h*60+m
for i in range(120):
	if (t >= 7*60 and t < 10*60) or (t >= 15*60 and t < 19*60):
		t += 2
	else:
		t += 1

h = t//60%24
m = t%60

# print(f'{h:02d}:{m:02d}')
print('%02d:%02d' % (h, m))