n = int(input())
a = list(input().split())
b = list(input().split())
c = 0; d = 0
for i in range(n):
    if a[i] != b[i]:
        if a[i] == 'rock' and b[i] == 'scissors':
            c += 1
        if b[i] == 'rock' and a[i] == 'scissors':
            d += 1
        if a[i] == 'paper' and b[i] == 'rock':
            c += 1
        if b[i] == 'paper' and a[i] == 'rock':
            d += 1
        if a[i] == 'scissors' and b[i] == 'paper':
            c += 1
        if b[i] == 'scissors' and a[i] == 'paper':
            d += 1

print(c, d)