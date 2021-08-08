#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
constexpr int MM = 1002;

int n, m, dp[52][MM][MM];
int psa[MM][52], mid[MM][MM];
//psa[row][col]
char s[52];

int cnt(int k, int l, int r, int v){
    if(l > r)
        return 0;
    int ret = psa[r][k] - (l ? psa[l-1][k] : 0);
    if(!v)
        ret = (r-l+1)-ret;
    return ret;
}

int val(int k, int l, int r, int j){
    return (j >= l)*(dp[k+1][l][j] + cnt(k, l, j, 1)) + (j+1 <= r)*(dp[k+1][j+1][r] + cnt(k, j+1, r, 0));
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%s", s+1);
        for(int j = 1; j <= m; j++){
            psa[i][j] = psa[i-1][j] + (s[j] == '1');
            //psa[row][col]
        }
    }
    
    memset(dp, 0x3f, sizeof dp);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            dp[m+1][i][j] = 0;
        }
    }
    
    for(int k = m; k > 0; k--){
        for(int len = 0; len <= n; len++){
            for(int l = 1; l+len <= n; l++){
                int r = l+len;
                for(int i = (len? mid[l][r-1] : l-1); i <= (len? mid[l+1][r] : r); i++){
                    int v = val(k, l, r, i);
                    if(v < dp[k][l][r]){
                        dp[k][l][r] = v;
                        mid[l][r] = i;
                    }
                }
            }
        }
    }
    
    print(dp[1][1][n]);
    
    return 0;
}