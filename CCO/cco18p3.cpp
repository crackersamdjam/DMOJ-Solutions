#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

int dp[2][20001], n, e, a[1001], b[1001];

int main(){
    
    scan(n, e);
    
    int c = 1, p = 0;
    
    memset(dp, -0x7f, sizeof dp);
    for(int i = 0; i < e; i++)
        dp[c][i] = i;
    
    for(int i = 2; i <= n; i++){
        std::swap(c, p);
        scan(a[i], b[i]);
        
        int max = 0;
        for(int k = 0; k < a[i]; k++) //comes from lower one
            max = std::max(max, dp[p][k]);
        
        // same as: can not move over, add this side until opens; move over from prev
        for(int j = 0; j < b[i]; j++)
            dp[c][j] = std::max(max+j, dp[p][a[i]+j]);
            
        // hold and move excess
        for(int j = b[i]; j < a[i]+b[i]; j++)
            dp[c][j] = dp[p][j-b[i]]+b[i];
        
        // all flood
        for(int j = a[i]+b[i]; j <= 20000; j++)
            dp[c][j] = std::max(dp[c][j], dp[p][j]);
        
        for(int j = 1; j <= 20000; j++){
            dp[c][j] = std::max(dp[c][j], dp[c][j-1]);
            dp[p][j] = INT_MIN;
        }
    }
    
    int ans = 0;
    for(int i = 0; i <= 20000; i++)
        ans = std::max(ans, dp[c][i]);
    
    print(ans);
    
    return 0;
}