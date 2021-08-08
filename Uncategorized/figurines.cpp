#include <bits/stdc++.h>

using namespace std;
using T = long long;
const int MM = 1e6+2;

int n, q;
T ina[MM], inb[MM];

struct node{
    T maxa, maxb, ans;
    bool upa, upb;
    T la, lb;
    void apply(T va, T vb, bool ua, bool ub){
        if(ua){
            la = va;
            maxa = la;
        }
        if(ub){
            lb = max(lb, vb);
            maxb = max(maxb, lb);
        }
        if(ua){
            ans = la + maxb;
            upa = 1;
        }
        if(ub){
            ans = max(ans, maxa + lb);
            upb = 1;
        }
    }
};

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
    node tree[MM*4];
    T DEF = -1e16;
    //default value
    
    static T merge(T va, T vb){
        return max(va, vb);
    }
    
    void push_up(int rt){
        tree[rt].maxa = merge(tree[lc].maxa, tree[rc].maxa);
        tree[rt].maxb = merge(tree[lc].maxb, tree[rc].maxb);
        tree[rt].ans = merge(tree[lc].ans, tree[rc].ans);
    }
    
    // node with lazy val means yet to push to children (but updated itself)
    void push_down(int rt, int nl, int nr){
        node &nd = tree[rt];
        if(nl != nr){
            tree[lc].apply(nd.la, nd.lb, nd.upa, nd.upb);
            tree[rc].apply(nd.la, nd.lb, nd.upa, nd.upb);
        }
        nd.la = nd.lb = DEF;
        nd.upa = nd.upb = 0;
    }
    
    void build(int l = 1, int r = n, int rt = 1){
        int nl = l, nr = r;
        tree[rt].la = tree[rt].lb = DEF;
        if(l == r){
            tree[rt].maxa = ina[l];
            tree[rt].maxb = inb[l];
            tree[rt].ans = ina[l] + inb[l];
            return;
        }
        build(l, nm, lc);
        build(nm+1, r, rc);
        push_up(rt);
    }
    
    void update(int l, int r, bool op, T v, int nl = 1, int nr = n, int rt = 1){
        if(r < nl || l > nr)
            return;
        if(l <= nl && r >= nr){
            tree[rt].apply(v, v, !op, op);
            return;
        }
        push_down(rt, nl, nr);
        update(l, r, op, v, nl, nm, lc);
        update(l, r, op, v, nm+1, nr, rc);
        push_up(rt);
    }
    
    T query(int l, int r, int nl = 1, int nr = n, int rt = 1){
        if(r < nl || l > nr)
            return DEF;
        if(l <= nl && r >= nr)
            return tree[rt].ans;
        push_down(rt, nl, nr);
        return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
    }
#undef lc
#undef rc
#undef nm
} t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
        cin >> ina[i];
    for(int i = 1; i <= n; i++)
        cin >> inb[i];
    t.build();
    
    for(int i = 0,op,l,r,k; i < q; i++){
        cin >> op >> l >> r;
        if(op == 3){
            cout << t.query(l, r) << '\n';
        }
        else{
            cin >> k;
            t.update(l, r, op-1, k);
        }
    }
    
    return 0;
}
/*
10 8
9 -10 0 -7 -3 10 1 -10 5 -7
-6 9 -10 0 -7 -9 6 9 -6 -1
1 5 8 -8
2 2 9 8
2 1 5 -6
2 5 8 1
1 7 9 -10
2 5 7 7
1 5 5 3
3 4 6
 */