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

int N, L, ps[MM];
char v[MM];
int bit[MM<<1];
ll ans;

void update(int i){
    for(i += MM; i < (MM<<1); i += i&-i)
        bit[i]++;
}

int query(int i){
    int ret = 0;
    for(i += MM; i; i -= i&-i)
        ret += bit[i];
    return ret;
}

int main(){
    
    scan(N, L);
    
    for(int i = 0,a; i < N; i++){
        scan(a);
        v[i] = ((a >= L) ? 1 : -1);
        ps[i] = v[i] + ps[i-1];
    }
    
    update(0);
    
    for(int i = 0; i < N; i++){
        ans += query(ps[i]);
        update(ps[i]);
    }
    
    print(ans);
    
    return 0;
}