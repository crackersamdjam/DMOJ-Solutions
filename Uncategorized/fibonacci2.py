import sys
input = sys.stdin.readline
d = {0:0, 1:1}
def f(n):
    m = 10**9+7
    if n in d:
        return d[n]
    elif n%2 == 0:      
        d[n] = (((2*(f((n//2)-1)%m))%m + f(n//2)%m)%m * (f(n//2)%m))%m
        return d[n]
    else:               
        d[n] = ((f(n//2)%m * f(n//2)%m)%m + (f((n//2)+1)%m * f((n//2)+1)%m)%m)%m
        return d[n]
print f(int(input())%2000000016)