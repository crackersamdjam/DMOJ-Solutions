#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 1002;

int D, I, R, dp[MM][MM];
char a[MM], b[MM];

int main(){
    
    scan(D, I, R);
    
    scanf("%s %s", a+1, b+1);
    int n = strlen(a+1), m = strlen(b+1);
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0)
                dp[i][j] = j*I;
            else if(j == 0)
                dp[i][j] = i*D;
            else if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = min(dp[i-1][j-1] + R, min(dp[i-1][j] + D, dp[i][j-1] + I));
        }
    }
    
    print(dp[n][m]);
    
    return 0;
}