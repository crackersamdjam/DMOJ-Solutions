#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using ll = long long;
const int MM = 2001;

int n, q, qt, a[MM], mod = 1e9+7;
ll dp[MM], sum;

inline void add(int id){
    for(int i = qt; i >= a[id]; i--)
        dp[i] = (dp[i] + dp[i-a[id]]) % mod;
}

inline void rm(int id){
    for(int i = a[id]; i <= qt; i++)
        dp[i] = (dp[i] - dp[i-a[id]] + mod) % mod;
}

int main(){
    
    scan(n, qt, q);
    
    dp[0] = 1;
    
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        add(i);
    }
    
    for(int i = 0,f,s; i < q; i++){
        scan(f, s, qt);
        qt -= a[f] + a[s];
        rm(f); rm(s);
        sum = 0;
        for(int j = 0; j <= qt; j++)
            sum = (sum + dp[j]) % mod;
        print(sum);
        add(f); add(s);
    }
    
    return 0;
}