#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }
#define bound(x) max(0, x)

using namespace std;
const int MM = 1e7+1;

int a, b, c, d, Q, dp[MM];

int go(int n){
    if(n < MM)
        return dp[n];
    return go(bound(n/a-b)) + go(bound(n/c-d));
}

int main(){
    
    scan(a, b, c, d, Q);
    
    dp[0] = 1;
    
    for(int i = 1; i < MM; i++){
        dp[i] = dp[bound(i/a-b)] + dp[bound(i/c-d)];
    }
    
    for(int i = 0,n; i < Q; i++){
        scan(n);
        print(go(n));
    }
    
    return 0;
}