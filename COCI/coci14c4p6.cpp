#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 302;

int N, M, K;
ll dp[MM][MM][3][3];

ll go(int a, int b, int x, int y){
    ll &ret = dp[a][b][x][y];
    if(~ret)
        return ret;
    
    if(x+y)
        ret = (1LL*a*b-K)*(1LL*a*b-K);
    else
        return ret = 1e17;
    
    
    for(int i = 1; i < a; i++)
        ret = min(ret, go(i, b, min(x, 1), y) + go(a-i, b, x - min(x, 1), y));
    for(int i = 1; i < b; i++)
        ret = min(ret, go(a, i, x, min(y, 1)) + go(a, b-i, x, y - min(y, 1)));
    
    return ret;
}

int main(){
    
    memset(dp, -1, sizeof dp);
    
    scan(N, M, K);
    
    print(go(N, M, 2, 2));
    
    return 0;
}