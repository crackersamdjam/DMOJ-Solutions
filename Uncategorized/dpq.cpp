#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 2e5+1;

int N;
ll a[MM], h[MM], bit[MM];

inline ll query(int i){
    ll ret = 0;
    for(; i; i -= i&-i)
        ret = max(ret, bit[i]);
    return ret;
}

inline void update(int i, ll v){
    for(; i < MM; i += i&-i)
        bit[i] = max(bit[i], v);
}

int main(){
    
    scan(N);
    
    for(int i = 0; i < N; i++)
        scan(h[i]);
    
    for(int i = 0; i < N; i++){
        scan(a[i]);
        ll dp = query(h[i]-1) + a[i];
        update(h[i], dp);
    }
    
    print(query(N));
    
    return 0;
}