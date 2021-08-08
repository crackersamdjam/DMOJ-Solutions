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
const int MM = 4002, mod = 1e9+7;

int n, m, tc = 10;
ll dp[21][MM];

struct st{
    ll x, f;
} a[MM];

int main(){
    
    //freopen("DATA41.txt", "r", stdin);
    
    while(tc--){
        
        scan(n, m);
        
        for(int i = 1; i <= n; i++)
            scan(a[i].x, a[i].f);
        
        sort(a+1, a+1+n, [](st x, st y){
            return x.x < y.x;
        });
        
        memset(dp, 0x7f, sizeof dp);
        
        dp[0][0] = 0;
        
        for(int k = 1; k <= m; k++){
            for(int i = 1; i <= n; i++){
                
                int r = i;
                ll v = 0, slope = a[i].f;
                dp[k][i] = dp[k-1][i-1];
                
                for(int j = i-1; j > 0; j--){
                    v += a[j].f*(a[r].x - a[j].x);
                    slope -= a[j].f;
                    
                    while(r > j && (slope <= 0 || a[r].x == a[r-1].x)){
                        ll oldv = v;
                        v += slope*(a[r].x - a[r-1].x);
                        
                        if(v - slope*(a[r].x - a[r-1].x) != oldv){
                            print(oldv, slope*(a[r].x - a[r-1].x), v);
                            fflush(stdout);
                            abort();
                            //reeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
                        }
                        
                        r--;
                        slope += a[r].f*2;
                    }
                    
                    dp[k][i] = min(dp[k][i], ((dp[k-1][j-1] + v)));
                }
            }
        }
        
        print(dp[m][n] % mod);
        
        //assert(dp[m][n] % mod >= 0);
    }
    
    return 0;
}
/*
 * each stand at one person (slope is linear)
 * dp[i] best so far
 * loop through previous backwards <--
 * to calc new cost, r-ptr
 */
/*
10 2
2 18
5 12
6 7
7 4
9 13
11 17
12 15
14 6
16 1
19 1

0 36 61 69 121 212 282 312 319 329
0 0 7 15 55 95 110 128 133 141

0 36 22 34 131 194 224 236 357 549
0 0 7 13 30 60 75 87 138 239
 */