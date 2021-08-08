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
const int MM = 3000010, adj = 150003;

int n, a[MM], p[MM];
ll ans;
int bit[MM];

void up(int i){
    for(i += adj; i < MM; i += i&-i)
        bit[i]++;
}
int qu(int i){
    int r = 0;
    for(i += adj; i; i -= i&-i)
        r += bit[i];
    return r;
}

int main(){
    
    scan(n);
    up(0);
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        if(a[i] == 2)
            a[i] = -1;
        p[i] = p[i-1] + a[i];
        ans += qu(p[i]-1);
        up(p[i]);
    }
    
    print(ans);
    
    return 0;
}