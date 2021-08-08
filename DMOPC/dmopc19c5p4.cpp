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
const int MM = 1e5+2;

ll dp[MM], pre[MM];
int n, q, m[MM], v[MM];

int main(){
    scan(n, q);
    for(int i = 1; i <= n; i++){
        scan(dp[i]);
    }
    for(int i = 1; i <= n; i++){
        scan(v[i]);
        dp[i] += dp[v[i]];
    }
    for(int i = 1; i <= n; i++){
        pre[i] = max(dp[i], pre[i-1]);
    }
    for(int i = 0,a,b; i < q; i++){
        scan(b, a);
        a -= b;
        if(a <= 0 or a > pre[n]){
            print(-1);
            continue;
        }
        int l = 1, mid, r = n;
        while(l <= r){
            mid = (l+r)/2;
            if(pre[mid] < a)
                l = mid+1;
            else
                r = mid-1;
        }
        print(l);
    }
    
    return 0;
}