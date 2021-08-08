#include <bits/stdc++.h>
#define bound(x) max(x, 0)
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 1001;

int n, m, dp[MM][MM];
char a[MM], b[MM];

int main(){
    
    scan(n, m);
    
    scanf("%s %s", a+1, b+1);
    
    for(int i = 1; i < MM; i++){
        dp[0][i] = dp[i][0] = (i+2)/3;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = dp[i-1][j-1] + 1;
                for(int k = 1; k <= 3; k++){
                    dp[i][j] = min(dp[i][j], min(dp[bound(i-k)][j], dp[i][bound(j-k)]) + 1);
                }
            }
        }
    }
    
    print(dp[n][m]);
    
    return 0;
}