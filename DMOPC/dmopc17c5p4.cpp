#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS
#endif
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef long long ll;
const int MM = 502, mod = 1e9+7;

int N, K;
ll dp[2][MM][MM];
//K intersections considered

int main(){
    
    scan(N, K);
    
    dp[0][0][0] = 1;
    //dp[1][0][0] = dp[1][1][0] = 1;
    //left end or no left end
    
    for(int i = 1; i <= N; i++){
        int cur = i&1;
        int pre = cur^1;
        
        for(int j = 0; j <= N; j++){
            ll sum = 0;
            for(int k = 0; k <= K; k++){
                ll &ret = dp[cur][j][k] = 0;
                sum += dp[pre][j+1][k];
                if(k-j-1 >= 0)
                    sum -= dp[pre][j+1][k-j-1];
                //at most j new intersections
                //can only count on previous j
                sum = (sum + mod)%mod;
                ret += sum;
                ret %= mod;
                
                ret += dp[pre][j][k];
                ret %= mod;
                
                if(j){
                    ret += dp[pre][j-1][k];
                    ret %= mod;
                }
            }
        }
    }
    
    print(dp[N&1][0][K]);
    
    return 0;
}
/*
 * dp[n][m][k]
 * n dots, m ends, k intersections
 * close old end
 * dp[n-1][m+1][0 ... k]
 * add new end
 * dp[n-1][m-1][k]
 * do nothing
 * dp[n-1][m][k]
 */