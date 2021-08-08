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
const int MM = 2002;

int n, m;
ll a[MM], b[MM], dp[MM][MM];
int dx[MM][MM], dy[MM][MM];

ll v(int i, int j, int k, int l){
    return dp[k][l] + (a[k]-a[i] - (k-i))*(b[l]-b[j] - (l-j));
}

int main(){
    
    scan(n, m);
    
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        a[i] += a[i-1];
    }
    
    for(int i = 1; i <= m; i++){
        scan(b[i]);
        b[i] += b[i-1];
    }
    
    memset(dp, 0x3f, sizeof dp);
    dp[n][m] = 0;
    
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            dx[i][j] = i+1, dy[i][j] = j+1;
            dp[i][j] = v(i, j, i+1, j+1);
            ll t = v(i, j, dx[i+1][j], dy[i+1][j]);
            if(t < dp[i][j]){
                dp[i][j] = t;
                dx[i][j] = dx[i+1][j], dy[i][j] = dy[i+1][j];
            }
            t = v(i, j, dx[i][j+1], dy[i][j+1]);
            if(t < dp[i][j]){
                dp[i][j] = t;
                dx[i][j] = dx[i][j+1], dy[i][j] = dy[i][j+1];
            }
            //printn(dp[i][j]), pc(32);
        }
        //pc(10);
    }
    
    print(dp[0][0]);
    
    return 0;
}