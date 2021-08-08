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
const int MM = 1e5+2;

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

int n, m, k;

struct node{
    ll val, lp;
} seg[MM*3];

inline void push_up(int rt){
    seg[rt].val = seg[lc].val + seg[rc].val;
}

inline void push_down(int rt, int nl, int nr){
    ll &val = seg[rt].lp;
    if(~val && nl^nr){
        seg[lc].lp = val;
        seg[lc].val = val*(nm-nl+1);
        seg[rc].lp = val;
        seg[rc].val = val*(nr-nm);
    }
    val = -1;
}

void build(int l = 1, int r = m, int rt = 1){
    int nl = l, nr = r;
    if(l == r){
        seg[rt].val = seg[rt].lp = -1;
        return;
    }
    build(l, nm, lc);
    build(nm+1, r, rc);
    push_up(rt);
}

void update(int l, int r, ll val, int nl = 1, int nr = MM-1, int rt = 1){
    if(r < nl || l > nr)
        return;
    if(l <= nl && r >= nr){
        seg[rt].val = val*(nr-nl+1);
        seg[rt].lp = val;
        return;
    }
    push_down(rt, nl, nr);
    update(l, r, val, nl, nm, lc);
    update(l, r, val, nm+1, nr, rc);
    push_up(rt);
}

ll query(int l, int r, int nl = 1, int nr = MM-1, int rt = 1){
    if(r < nl || l > nr)
        return 0;
    if(l <= nl && r >= nr)
        return seg[rt].val;
    push_down(rt, nl, nr);
    return query(l, r, nl, nm, lc) + query(l, r, nm+1, nr, rc);
}

const int MN = 101;
ll x[MN], y[MN], r[MN], ans;

#define sq(x) (x)*(x)

int main(){
    
    scan(n, m, k);
    
    ans = (ll)n*m*k;
    
    for(int i = 0; i < k; i++){
        scan(x[i], y[i], r[i]);
    }
    
    build();
    
    for(int i = 1; i <= n; i++){
        update(1, m, 0);
        for(int j = 0; j < k; j++){
            if(sq(x[j]-i) > sq(r[j]))
                continue;
            ll d = sqrtl(sq(r[j]) - sq(x[j]-i));
            update(max(y[j]-d, 1LL), min((ll)m, y[j]+d), j+1);
        }
        ans -= query(1, m);
    }
    
    print(ans);
    
    return 0;
}