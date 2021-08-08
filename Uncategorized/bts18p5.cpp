#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS
#endif
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(32);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef long long ll;
const int MM = 2002, MOD = 998244353;

int N, a[MM];
ll dp[MM][MM];

inline ll mod(ll n){
    return (n % MOD + MOD) % MOD;
}

ll go(int n, int k){
    if(n == N){
        return k == 0;
    }
    if(k < 0)
        return 0;
    
    if(dp[n][k] != -1)
        return dp[n][k];
    
    return dp[n][k] = mod(go(n+1, k) + go(n+1, k-1)*a[n]);
}

int main(){
    
    memset(dp, -1, sizeof(dp));
    
    scan(N);
    
    for(int i = 0; i < N; i++){
        scan(a[i]);
    }
    for(int i = 1; i <= N; i++){
        print(go(0, i));
    }
    return 0;
}