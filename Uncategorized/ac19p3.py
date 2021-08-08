s = input().replace('(', '').replace(')', '').replace('+', '').split(' ')
v = 0
for i in s:
    if len(i):
        v += int(i)

print(v)