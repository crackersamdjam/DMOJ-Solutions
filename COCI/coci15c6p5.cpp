#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;

int n, l, a[101], c[101], tota;
ll dp[101][101][501], totc;
double ans = 1e20;

int main(){
    
    memset(dp, 0x3f, sizeof dp);
    
    dp[0][0][0] = 0;
    
    scan(n, l);
    
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        tota += a[i];
    }
    
    for(int i = 1; i <= n; i++){
        scan(c[i]);
        totc += c[i];
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= tota; j++){
            for(int k = 0; k <= n; k++){
                if(j < a[i] || k == 0)
                    dp[i][k][j] = dp[i-1][k][j];
                else
                    dp[i][k][j] = min(dp[i-1][k][j], dp[i-1][k-1][j-a[i]] + c[i]);
            }
        }
    }
    
    for(int i = 1; i < tota; i++){
        double v = min(dp[n][l][i], dp[n][n-l][i]);
        if(v < 0x3f3f3f3f3f3f3f3f){
            //cout << v << ' ' << totc - v << ' ' << i << ' ' << tota - i << '\n';
            ans = min(ans, v*(totc-v)/(1.0*i*(tota-i)));
        }
    }
    
    printf("%.3lf\n", ans);
    
    return 0;
}
/*
5 2
23 43 12 2 2
9 4 3 21 2
 */