#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;

int n;
ll a[401], dp[401][401];

ll go(int l, int r){
    if(dp[l][r] != 0x3f3f3f3f3f3f3f3f)
        return dp[l][r];
    for(int i = l; i < r; i++)
        dp[l][r] = min(dp[l][r], go(l, i) + go(i+1, r) + a[r] - a[l-1]);
    return dp[l][r];
}

int main(){
    
    memset(dp, 0x3f, sizeof dp);
    
    scan(n);
    
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        a[i] += a[i-1];
        dp[i][i] = 0;
    }
    
    print(go(1, n));
    
    return 0;
}