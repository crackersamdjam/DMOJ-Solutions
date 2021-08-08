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
const int MM = 1e5+1, mod = 1e9+7;

ll bi[MM][51], ans;
int n, k, a[MM];

int main(){
    
    scan(n, k);
    
    bi[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            bi[i][j] = (bi[i-1][j] + (j ? bi[i-1][j-1] : 0)) % mod;
        }
    }
    
    for(int i = 1; i <= n; i++)
        scan(a[i]);
    
    sort(a+1, a+n+1);
    
    for(int i = k; i <= n; i++){
        ans += a[i]*bi[i-1][k-1]%mod;
        ans %= mod;
    }
    
    print(ans);
    
    return 0;
}