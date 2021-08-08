#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int mod = 1e9+7;

int N, C, dp[2][10001];

int main(){
    
    scan(N, C);
    
    dp[1][0] = 1;
    
    for(int i = 2; i <= N; i++){
        
        int sum = 0, cur = i&1, pre = cur^1;
        for(int j = 0; j <= C; j++){
            sum = (sum + dp[pre][j]) % mod;
            if(j >= i)
                sum = ((sum - dp[pre][j-i]) % mod + mod) % mod;
            
            dp[cur][j] = sum;
        }
    }
    print(dp[N&1][C]);
    
    return 0;
}