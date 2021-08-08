s = input()
ans = 0
for r in range(len(s)+1):
	for l in range(0, r):
		sub = s[l:r]
		rev = sub[::-1]
		if sub == rev:
			ans = max(ans, len(sub))
print(ans)