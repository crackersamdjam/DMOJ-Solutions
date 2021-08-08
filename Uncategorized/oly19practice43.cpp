#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e6+1;

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

int n, m;

struct node{
    int val, lp;
} tree[MM*3];

inline void push_up(int rt){
    tree[rt].val = tree[lc].val & tree[rc].val;
}

inline void push_down(int rt, int nl, int nr){
    int &val = tree[rt].lp;
    if(val && nl != nr)
        tree[lc].lp = tree[lc].val = tree[rc].lp = tree[rc].val = 1;
    val = 0;
}
void update(int l, int r, int val, int nl = 1, int nr = MM-1, int rt = 1){
    if(r < nl || l > nr)
        return;
    if(l <= nl && r >= nr){
        tree[rt].val = val;
        tree[rt].lp = val;
        return;
    }
    push_down(rt, nl, nr);
    update(l, r, val, nl, nm, lc);
    update(l, r, val, nm+1, nr, rc);
    push_up(rt);
}

int query(int l, int r, int nl = 1, int nr = MM-1, int rt = 1){
    if(r < nl || l > nr)
        return 1;
    if(l <= nl && r >= nr)
        return tree[rt].val;
    push_down(rt, nl, nr);
    return query(l, r, nl, nm, lc) & query(l, r, nm+1, nr, rc);
}

struct st{
    int l, r, x, upl, upr;
    bool operator<(const st &o) const{
        return x > o.x;
    }
} q[MM], s[MM];

bool go(int mid){
    
    for(int i = 1; i <= mid; i++){
        s[i] = q[i];
    }
    sort(s+1, s+mid+1);
    
    memset(tree, 0, sizeof tree);
    
    for(int i = 1; i <= mid; i++){
        
        if(s[i].l > s[i].r)
            return 0;
        
        if(i < mid && s[i].x == s[i+1].x){
            s[i+1].l = max(s[i].l, s[i+1].l);
            s[i+1].r = min(s[i].r, s[i+1].r);
    
            s[i+1].upl = min(s[i].upl, s[i+1].upl);
            s[i+1].upr = max(s[i].upr, s[i+1].upr);
            continue;
        }
        
        if(query(s[i].l, s[i].r))
            return 0;
        
        update(s[i].upl, s[i].upr, 1);
    }
    
    return 1;
}

int main(){
    
    scan(n, m);
    
    for(int i = 1; i <= m; i++){
        scan(q[i].l, q[i].r, q[i].x);
        q[i].upl = q[i].l;
        q[i].upr = q[i].r;
    }
    
    int l = 1, mid, r = m;
    while(l <= r){
        mid = (l+r)/2;
        if(go(mid))
            l = mid+1;
        else
            r = mid-1;
    }
    print(l % (m+1));
    
    return 0;
}