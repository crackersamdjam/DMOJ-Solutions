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
const int MM = 1e6+1;

int n, phi[MM];
bool p[MM], np[MM];
ll ans, mod = 1e9+7;

int main(){
    
    scan(n);
    
    phi[1] = p[1] = 1;
    for(int i = 2; i <= n; i++){
        phi[i] = i;
        for(ll j = (ll)i*i; j <= n; j *= i)
            p[j] = 1;
    }
    
    for(int i = 2; i <= n; i++){
        if(np[i])
            continue;
        for(int j = i; j <= n; j += i){
            np[j] = 1;
            phi[j] -= phi[j]/i;
        }
    }
    
    for(int i = 1; i <= n; i++){
        ans += p[phi[i]]*phi[i];
        ans %= mod;
    }
    
    print(ans);
    
    return 0;
}