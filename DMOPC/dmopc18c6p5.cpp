#include <bits/stdc++.h>
#define lc (rt<<1)
#define rc (rt<<1|1)
#define m ((nl+nr)>>1)
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 4e5+4, MN = 1e5+1;

int N, M, K, Q, cntx = 1, cnty = 1, rnx[MM], rny[MM], T, best[MN];
ll ans;
vector<pair<int, int>> row[MM], col[MM], add[2][MM], rm[2][MM];
map<int, int> mx, my;

struct{
    int a, b;
} in1[MN];

struct{
    int a, b, c, d;
} in2[MN];

struct node{
    int val, lp;
} tree[MM*3];

inline void push_up(int rt){
    tree[rt].val = max(tree[lc].val, tree[rc].val);
}

inline void push_down(int rt, int nl, int nr){
    int &val = tree[rt].lp;
    if(val && nl^nr){
        tree[lc].lp += val;
        tree[lc].val += val;
        tree[rc].lp += val;
        tree[rc].val += val;
    }
    val = 0;
}

void update(int l, int r, int val, int nl = 1, int nr = MM-1, int rt = 1){
    if(r < nl || l > nr)
        return;
    if(l <= nl && r >= nr){
        tree[rt].val += val;
        tree[rt].lp += val;
        return;
    }
    push_down(rt, nl, nr);
    update(l, r, val, nl, m, lc);
    update(l, r, val, m+1, nr, rc);
    push_up(rt);
}

int query(int l, int r, int nl = 1, int nr = MM-1, int rt = 1){
    if(r < nl || l > nr)
        return 0;
    if(l <= nl && r >= nr)
        return tree[rt].val;
    push_down(rt, nl, nr);
    return max(query(l, r, nl, m, lc), query(l, r, m+1, nr, rc));
}

inline int lx(int ind){
    return lower_bound(rnx+1, rnx+cntx, rnx[ind]-T) - rnx;
}
inline int rx(int ind){
    return lower_bound(rnx+1, rnx+cntx, rnx[ind]+T+1)-1 - rnx;
}
inline int ly(int ind){
    return lower_bound(rny+1, rny+cnty, rny[ind]-T) - rny;
}
inline int ry(int ind){
    return lower_bound(rny+1, rny+cnty, rny[ind]+T+1)-1 - rny;
}

int main(){
    
    scan(N, M, K, Q, T);
    
    for(int i = 0,a,b; i < K; i++){
        scan(a, b);
        mx[a] = my[b] = 0;
        in1[i] = {a, b};
    }
    
    for(int i = 0,a,b,c,d; i < Q; i++){
        scan(a, b, c, d);
        mx[a] = mx[c] = my[b] = my[d] = 0;
        in2[i] = {a, b, c, d};
    }
    for(auto &it: mx){
        rnx[cntx] = it.first;
        it.second = cntx++;
    }
    for(auto &it: my){
        rny[cnty] = it.first;
        it.second = cnty++;
    }
    
    for(int i = 0,a,b; i < K; i++){
        a = mx[in1[i].a], b = my[in1[i].b];
        row[a].push_back({b, i});
        col[b].push_back({a, i});
    }
    
    for(int i = 0,a,b,c,d; i < Q; i++){
        a = mx[in2[i].a], b = my[in2[i].b], c = mx[in2[i].c], d = my[in2[i].d];
        add[0][a].push_back({b, d});
        rm[0][c].push_back({b, d});
        add[1][b].push_back({a, c});
        rm[1][d].push_back({a, c});
    }
    
    for(int i = 1; i < cntx; i++){
        for(auto &p: add[0][i])
            update(p.first, p.second, 1);
        
        for(auto &g: row[i])
            best[g.second] = query(ly(g.first), ry(g.first));
        
        for(auto &p: rm[0][i])
            update(p.first, p.second, -1);
    }
    
    memset(tree, 0, sizeof tree);
    
    for(int i = 1; i < cnty; i++){
        for(auto &p: add[1][i])
            update(p.first, p.second, 1);
        
        for(auto &g: col[i])
            best[g.second] = max(best[g.second], query(lx(g.first), rx(g.first)));
        
        for(auto &p: rm[1][i])
            update(p.first, p.second, -1);
    }
    
    for(int i = 0; i < K; i++)
        ans += best[i];
    
    print(ans);
    
    return 0;
}