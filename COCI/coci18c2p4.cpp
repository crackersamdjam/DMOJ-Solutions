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
const int MM = 202;

int n, m, a[MM][MM], x, y, b[MM][MM];
ll dp[2][MM][MM], k, ans;
int mx[] = {1, -1, 0, 0}, my[] = {0, 0, 1, -1};

struct st{
    int t, x, y;
};

int main(){
    
    scan(n, m, x, y, k);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scan(a[i][j]);
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int d = 0; d < 4; d++){
                b[i][j] = max(b[i][j], a[i+mx[d]][j+my[d]]);
            }
        }
    }
    
    memset(dp, -0x3f, sizeof dp);
    dp[0][x][y] = 0;
    int c = 0, p = 1;
    for(int t = 1; t <= min((ll)n*m, k/2); t++){
        swap(c, p);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                for(int d = 0; d < 4; d++){
                    dp[c][i][j] = max(dp[c][i][j], dp[p][i+mx[d]][j+my[d]] + a[i][j]);
                }
                ans = max(ans, dp[c][i][j]*2-a[i][j] + (k-2*t)*(a[i][j]+b[i][j])/2);
            }
        }
    }
    
    print(ans);
    
    return 0;
}