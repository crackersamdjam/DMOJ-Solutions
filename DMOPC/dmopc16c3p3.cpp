#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;

int N, M, dp[5001];
//max magic after defeating i ghosts

int main(){
    
    memset(dp, -1, sizeof dp);
    
    scan(N, M);
    
    dp[0] = M;
    
    for(int i = 1,a,b; i <= N; i++){
        scan(a, b);
        
        for(int j = i; j; j--){
            if(dp[j-1] >= a)
                dp[j] = max(dp[j], dp[j-1] - a + b);
        }
    }
    
    for(int i = N; i >= 0; i--)
        if(dp[i] != -1)
            return 0*printf("%d %d\n", i, dp[i]);
    
    return 0;
}