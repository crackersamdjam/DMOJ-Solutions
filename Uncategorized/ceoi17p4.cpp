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
const int MM = 1e5+1, MN = 1048576;

int n;
ll dp[MM], a[MM], w[MM], sum;

struct line{
    ll m, b;
    ll f(ll x){
        return m*x + b;
    }
} tree[MN*2];

void add(line ln, int l = 0, int r = MN-1, int rt = 1){
    int m = (l+r)/2;
    bool bl = ln.f(l) < tree[rt].f(l);
    bool bm = ln.f(m) < tree[rt].f(m);
    if(bm)
        swap(tree[rt], ln);
    if(l == r)
        return;
    if(bl != bm)
        add(ln, l, m, rt<<1);
    else
        add(ln, m+1, r, rt<<1|1);
}

ll get(int x, int l = 0, int r = MN-1, int rt = 1){
    int m = (l+r)/2;
    if(l == r)
        return tree[rt].f(x);
    if(x <= m)
        return min(tree[rt].f(x), get(x, l, m, rt<<1));
    return min(tree[rt].f(x), get(x, m+1, r, rt<<1|1));
}

int main(){
    for(int i = 0; i < MN*2; i++)
        tree[i] = {(ll)1e12, (ll)1e12};
    scan(n);
    for(int i = 1; i <= n; i++)
        scan(a[i]);
    for(int i = 1; i <= n; i++){
        scan(w[i]);
        sum += w[i];
    }
    dp[1] = -w[1];
    add({-2*a[1], dp[1] + a[1]*a[1]});
    
    for(int i = 2; i <= n; i++){
        dp[i] = get(a[i]) + a[i]*a[i] - w[i];
        add({-2*a[i], dp[i] + a[i]*a[i]});
    }
    
    print(dp[n] + sum);
    
    return 0;
}
/*
 dp[i] = max{dp[j] + (a[i]-a[j])^2} - w[i]
 
 y = mx + b
 b = dp[j]
 m = -2a[j]

 */