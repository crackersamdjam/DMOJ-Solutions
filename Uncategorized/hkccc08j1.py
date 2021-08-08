m1 = 0; m2 = 0; n = int(input())
while n:
    n -= 1
    a, b = map(int, input().split())
    m1 = max(m1, a*b)
m = int(input())
while m:
    m -= 1
    a, b = map(int, input().split())
    m2 = max(m2, a*b)
if m1 == m2:
    print("Tie")
elif m1 > m2:
    print("Casper")
else:
    print("Natalie")