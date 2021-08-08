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
const int MM = 1e5+1;

int n, k;
ll a[MM], pre[MM];

bool test(ll m){
    ll best = 1e12;
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + a[i] - m;
        if(i >= k)
            best = min(best, pre[i-k]);
        if(pre[i] - best >= 0)
            return 1;
    }
    return 0;
}

int main(){
    
    scan(n, k);
    
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        a[i] *= 1000;
    }
    
    ll l = 1, m, r = 2000LL*1000*MM;
    while(l <= r){
        m = (l+r)/2;
        if(test(m))
            l = m+1;
        else
            r = m-1;
    }
    
    print(r);
    
    return 0;
}