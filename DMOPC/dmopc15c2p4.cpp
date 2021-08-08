#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e5+1;

int N;

struct anime{
    ll l, r, h, dp;
    anime(){};
    anime(ll n): r(n){};
    friend bool operator<(anime x, anime y){
        return x.r < y.r;
    }
} a[MM];

int main(){
    
    
    scan(N);
    
    for(int i = 1; i <= N; i++){
        scan(a[i].l, a[i].r, a[i].h);
        a[i].r += a[i].l;
    }
    
    sort(a, a+N+1);
    
    for(int i = 1; i <= N; i++){
        a[i].dp = a[i].h + (upper_bound(a, a+N+1, anime(a[i].l))-1)->dp;
        a[i].dp = max(a[i].dp, a[i-1].dp);
    }
    
    print(a[N].dp);
    
    return 0;
}
/*
 * dp[end] = dp[start] + value
 */