n = int(input())
while n:
    n -= 1
    x = input()
    while len(x) > 1:
        m = 0
        for c in x:
            m += int(c)
        x = str(m)
    print(x)