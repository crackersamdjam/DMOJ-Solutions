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
const int M = 2002;

ll a[M];
int n, b, c, dp[M][M];
//reach i using j small cameras, value is large camera

bool test(ll w){
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    
    for(int i = 1; i <= n; i++){
        int l = lower_bound(a, a+i, a[i]-w+1) - a;
        for(int j = 1; j <= b; j++)
            dp[i][j] = min(dp[i][j], dp[l-1][j-1]);
        
        l = lower_bound(a, a+i, a[i]-w-w+1) - a;
        for(int j = 0; j <= b; j++)
            dp[i][j] = min(dp[i][j], dp[l-1][j] + 1);
    }
    for(int i = 0; i <= b; i++){
        if(dp[n][i] <= c)
            return 1;
    }
    return 0;
}

int main(){
    
    scan(n, b, c);
    b = min(b, n), c = min(n, c);
    
    a[0] = INT_MIN;
    
    for(int i = 1; i <= n; i++)
        scan(a[i]);
    
    sort(a+1, a+1+n);
    
    ll l = 1, m, r = 1e9+1;
    while(l <= r){
        m = (l+r)>>1;
        if(test(m))
            r = m-1;
        else
            l = m+1;
    }
    
    print(l);
    
    return 0;
}