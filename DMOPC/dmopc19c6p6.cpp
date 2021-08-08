#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
constexpr int MM = 2e5+1;

ll suf[MM];
int ptr;

struct line{
    int m; ll b;
    int lc, rc;
    ll f(ll x){
        return m*x + b;
    }
    void add(line ln, int l, int r);
    ll get(int x, int l, int r);
} all[10100000];

void line::add(line ln, int l, int r){
    int mid = (l+r)/2;
    bool bl = ln.f(l) > f(l);
    bool bmid = ln.f(mid) > f(mid);
    if(bmid){
        swap(m, ln.m);
        swap(b, ln.b);
    }
    if(l == r)
        return;
    if(bl != bmid){
        if(!lc) lc = ++ptr;
        all[lc].add(ln, l, mid);
    }
    else{
        if(!rc) rc = ++ptr;
        all[rc].add(ln, mid+1, r);
    }
}
ll line::get(int x, int l, int r){
    int mid = (l+r)/2;
    if(l == r)
        return f(x);
    if(x <= mid){
        if(!lc) return f(x);
        return max(f(x), all[lc].get(x, l, mid));
    }
    if(!rc) return f(x);
    return max(f(x), all[rc].get(x, mid+1, r));
}

int n, m, d, v[MM], tree[MM*3];

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
void update(int l, int r, line val, int nl = 1, int nr = d, int rt = 1){
    if(r < nl || l > nr)
        return;
    if(l <= nl && r >= nr){
        if(!tree[rt])
            tree[rt] = ++ptr;
        all[tree[rt]].add(val, 1, m+1);
        return;
    }
    update(l, r, val, nl, nm, lc);
    update(l, r, val, nm+1, nr, rc);
}

ll query(int l, int r, int x, int nl = 1, int nr = d, int rt = 1){
    if(r < nl || l > nr)
        return 0;
    if(l <= nl && r >= nr){
        return all[tree[rt]].get(x, 1, m+1);
    }
    return max(all[tree[rt]].get(x, 1, m+1), max(query(l, r, x, nl, nm, lc), query(l, r, x, nm+1, nr, rc)));
}

int l[MM], r[MM];
ll pre[MM];

struct event{
    int op, qn, l, r; // q#, l, r
    int m; ll b;
    //0 = update, 1 = query
    bool operator<(const event &o){
       if(qn == o.qn)
           return op < o.op;
       return qn > o.qn;
    }
} qs[MM<<1];
int ed = 0;

int main(){
    scan(n, m, d);
    for(int i = 1; i <= m; i++)
        scan(v[i], l[i], r[i]);
    
    for(int i = m; i; i--){
        suf[i] = suf[i+1] + v[i];
        qs[ed++] = {0, i, l[i], r[i], -v[i], suf[i+1] + (ll)(i+1)*v[i]};
    }
    for(int i = m; i; i--)
        pre[i] = pre[i+1]+suf[i];
    
    for(int i = 1,a,t; i <= n; i++){
        scan(a, t);
        suf[i] = pre[a+1]; //everything after ith (reuse suf as ans)
        qs[ed++] = {1, a+1, t, t, i, 0};
    }
    sort(qs, qs+ed);
    
    for(auto i: qs){
        if(i.op == 0){
            update(i.l, i.r, {i.m, i.b});
        }
        else{
            suf[i.m] -= query(i.l, i.l, i.qn);
        }
    }
    
    for(int i = 1; i <= n; i++)
        print(suf[i]);
    
    return 0;
}