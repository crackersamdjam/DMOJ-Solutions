#ifndef ONLINE_JUDGE
#define __gcd(x, y) __algo_gcd(x, y)
#endif
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int N = 1e5;

int n, a[N], p[N], s[N], ans;

int main(){
    
    scan(n);
    
    for(int i = 0; i < n; i++)
        scan(a[i]);
    
    p[0] = a[0];
    for(int i = 1; i < n; i++)
        p[i] = __gcd(p[i-1], a[i]);
    
    s[n-1] = a[n-1];
    for(int i = n-2; i >= 0; i--)
        s[i] = __gcd(s[i+1], a[i]);
    
    ans = max(s[1], p[n-2]);
    for(int i = 1; i < n-1; i++)
        ans = max(ans, __gcd(p[i-1], s[i+1]));
    
    print(ans);
    
    return 0;
}