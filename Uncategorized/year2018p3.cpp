#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 2e5;

int N, M;
ll K, a[MM];
ll dif[MM];

inline bool test(ll val){
    ll cnt = 0;
    ll pass = 0;
    memset(dif, 0, sizeof dif);
    for(int i = 0; i < N; i++){
        cnt += dif[i];
        if(a[i] + cnt < val){
            int sub = (val - a[i] - cnt);
            pass += sub;
            cnt += sub;
            dif[i+M] -= sub;
        }
        if(pass > K)
            return 0;
    }
    return (pass <= K);
}

int main(){
    
    scan(N, M, K);
    for(int i = 0; i < N; i++)
        scan(a[i]);
    
    ll l = *min_element(a, a+N), m, r = 2e9;
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