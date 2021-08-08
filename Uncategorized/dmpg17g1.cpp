#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 4098;

#define bound(x) (((x) % p + p) % p)

int n, p, dp[2][MM], a[MM], ans[MM], t;

int main(){
    
    memset(dp, -0x3f, sizeof dp);
    dp[0][0] = 0;
    
    scan(n, p);
    
    int cur = 0, pre = 1;
    for(int i = 0; i < n; i++){
        swap(cur, pre);
        scan(a[i]);
        for(int j = 0; j < p; j++)
            dp[cur][j] = max(dp[pre][j], dp[pre][bound(j - a[i])] + a[i]);
    }
    
    print(dp[cur][0]);
    
    int at = 0;
    
    for(int i = n-1; i >= 0; i--){
        if(dp[cur][at] != dp[pre][at] && dp[cur][at] == dp[pre][bound(at - a[i])] + a[i]){
            ans[++t] = i+1;
            at = bound(at - a[i]);
        }
        for(int k = 0; k < p; k++)
            dp[cur][bound(k - a[i-1])] = dp[pre][k] - a[i-1];
        swap(cur, pre);
    }
    
    print(t);
    for(; t; printn(ans[t--]), pc(32));
    
    return 0;
}