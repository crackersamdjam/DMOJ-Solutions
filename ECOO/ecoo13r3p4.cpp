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
const int MM = 1012;

int tc = 10, N, dp[MM][10];

int main(){
    
    while(tc--){
        memset(dp, 0, sizeof(dp));
        
        scan(N);
        
        for(int i = 10,f,s; i < N+10; i++){
            scan(f, s);
            s = f+s; //counts as two cards taken
            f = f-1; //incorrect for s
            
            dp[i][0] = dp[i-1][9];
            // both wrong
            // fst correct, < 9 before
            for(int j = 0; j <= 8; j++){
                dp[i][0] = max(dp[i][0], dp[i-1][j] + f);
            }
            
            dp[i][1] = dp[i-1][0] + f;
            for(int j = 2; j <= 9; j++){
                dp[i][j] = max(dp[i-1][j-1] + f, dp[i-1][j-2] + s);
            }
        }
    
        int ans = 0;
        for(int i = 0; i <= 9; i++)
            ans = max(ans, dp[N+9][i]);
    
        print(ans);
    }
    
    return 0;
}