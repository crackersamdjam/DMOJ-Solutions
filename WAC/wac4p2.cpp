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
using ll = long long;
const int MM = 5005;

int n, v[MM], p[MM], sum;
ll dp[MM];

int main(){
    scan(n);
    for(int i = 1; i <= n; i++){
        scan(v[i], p[i]);
        v[i] = v[i]/2+1;
        sum += p[i];
    }
    assert(sum <= 5000);
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = sum; j >= p[i]; j--){
            dp[j] = min(dp[j], dp[j-p[i]] + v[i]);
        }
    }
    
    for(int i = sum-1; i >= 0; i--){
        dp[i] = min(dp[i], dp[i+1]);
    }
    
    print(dp[sum/2+1]);
//    for(int i = 0; i <= sum; i++)
//        printf("%lld ", dp[i]);
    
    
    return 0;
}