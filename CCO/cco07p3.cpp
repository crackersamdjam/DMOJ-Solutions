#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 10202;

int dp[501][MM], a[MM], psa[MM];

int main(){
    
    int t, n, k, w;
    scan(t);
    while(t--){
        
        memset(dp, 0, sizeof dp);
        memset(psa, 0, sizeof psa);
        memset(a, 0, sizeof a);
        
        int ans = 0;
        
        scan(n, k, w);
        
        for(int i = 1; i <= n; i++)
            scan(a[i]);
        
        n += 2*w;
        
        for(int i = 1+w; i <= n; i++)
            psa[i] = psa[i-1] + a[i-w];
        
        for(int i = 1; i <= k; i++){
            for(int j = 1; j <= n; j++){
                
                int &val = dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                
                int l = max(0, j-w);
                
                val = max(val, dp[i-1][l] + psa[j] - psa[l]);
                
                if(i > 1){
                    for(int m = max(0, j-w-w); m <= j-w; m++)
                        val = max(val, dp[i-2][m] + psa[j] - psa[m]);
                }
                ans = max(ans, val);
            }
        }
        
        print(ans);
    }
    
    return 0;
}