#include <bits/stdc++.h>
using namespace std;

struct LinkCut {
    struct node{
        int p = 0, ch[2] = {0, 0}, pp = 0, sz = 0, val = 0, dp = 0;
        bool flip = 0;
    };
    vector<node> T;
    
    LinkCut(int n): T(n+1){ }
    
    int dir(int x, int y){ //which ch[?] y is of x
        return T[x].ch[1] == y;
    }
    
    void set(int x, int d, int y){ //set x's ch[d] to y and y's par to x
        if(x) T[x].ch[d] = y, pull(x);
        if(y) T[y].p = x;
    }
    
    void pull(int x){
        if(!x) return;
        int l = T[x].ch[0], r = T[x].ch[1];
        push(l), push(r);
        T[x].dp = T[x].val + T[l].dp + T[r].dp;
        T[x].sz = T[l].sz + T[r].sz + 1;
    }
    
    void push(int x){
        if(!x) return;
        int &l = T[x].ch[0], &r = T[x].ch[1];
        if(T[x].flip){
            swap(l, r);
            T[l].flip ^= 1; T[r].flip ^= 1;
            T[x].flip = 0;
        }
    }
    
    void rotate(int x, int d){ // 0 left, 1 right
        int y = T[x].p, z = T[y].p, w = T[x].ch[d];
        swap(T[x].pp, T[y].pp);
        set(y, !d, w);
        set(x, d, y);
        set(z, dir(z, y), x);
    }
    
    void splay(int x){
        for(push(x); T[x].p;){
            int y = T[x].p, z = T[y].p;
            push(z); push(y); push(x);
            int dx = dir(y, x), dy = dir(z, y);
            if(!z)
                rotate(x, !dx);
            else if(dx == dy)
                rotate(y, !dx), rotate(x, !dx); // zig zag
            else
                rotate(x, dy), rotate(x, dx); // zig zig
        }
    }
    
    // SPLAY TREE OPERATIONS END
    
    void makeroot(int u){
        access(u);
        int l = T[u].ch[0];
        T[l].flip ^= 1;
        swap(T[l].p, T[l].pp);
        set(u, 0, 0);
    }
    
    int access(int _u){
        int v, u;
        for(v = 0, u = _u; u; u = T[v = u].pp){ // jump both up (u is pp of v)
            splay(u); splay(v);
            //remove u's prefered child (r), change to v if it exists
            int r = T[u].ch[1];
            T[v].pp = 0;
            swap(T[r].p, T[r].pp);
            set(u, 1, v);
        }
        splay(_u);
        return v; // last node that pp jumped to (for lca)
    }
    
    void link(int u, int v){ // make v's parent u
        if(connected(u, v))
            return;
        makeroot(v);
        T[v].pp = u;
    }
    
    void cut(int u, int v){
        makeroot(u); access(u); splay(v);
        assert(T[v].pp == u);
        T[v].pp = 0;
    }
    
    void cutup(int u, int root){
        makeroot(root);
        access(u);
        if(!T[u].ch[0])
            return;
        cut(u, T[u].ch[0]);
    }
    
    bool connected(int u, int v){
        if(u == v) return 1;
        makeroot(u); access(v); splay(u);
        return T[v].p == u || T[T[v].p].p == u;
    }
    
    node query(int u, int v){
        makeroot(u); access(v);
        //now v is at top of ALL and only nodes in the splay are on path root(u) -> v
        //so it becomes subtree sum
        return T[v];
    }
    
    void update(int v, int w, int x){
        makeroot(w), access(v);
        T[v].val = x;
    }
    
    int findroot(int u){
        access(u);
        while(T[u].ch[0])
            u = T[u].ch[0];
        splay(u);
        return u;
    }
};

const int MM = 6e5+5;
LinkCut LCT(MM);
int a[MM];
int n, l, ptr;
int root = 2e9+5, base = -2e9;

map<int, int> at, cnt;
//at[i] = nodeid at pos i, cnt = # of eles at pos i

void insert(int i){
    //dummy
    if(!at[i+l+1]){
        at[i+l+1] = ++ptr;
        auto nx = at.upper_bound(i+l+1);
        LCT.link(at[i+l+1], nx->second);
        
        ----nx;
        //only chage previous one if it a dummy node (no eles)
        if(!cnt[nx->first]){
            LCT.cutup(nx->second, at[root]);
            LCT.link(nx->second, at[i+l+1]);
        }
    }
    
    //real
    if(!cnt[i]++){
        if(!at[i]) at[i] = ++ptr;
        else LCT.cutup(at[i], at[root]); //rm old one
        LCT.update(at[i], at[i], 1);
        LCT.link(at[i], at[i+l+1]); //conncect to dummy
    
        auto nx = --at.lower_bound(i);
        //only chage previous one if it a dummy node (no eles)
        if(!cnt[nx->first]){
            LCT.cutup(nx->second, at[root]);
            LCT.link(nx->second, at[i]);
        }
    }
}

void remove(int i){
    //don't worry about dummy node bc it doesn't change
    if(!--cnt[i]){
        LCT.update(at[i], at[i], 0);
        LCT.cutup(at[i], at[root]); //disconnect it from its dummy and go with next node
        auto nx = at.upper_bound(i);
        LCT.link(at[i], nx->second);
    }
}

void init(int N, int L, int* X){
    n = N, l = L;
    
    at[root] = ++ptr;
    at[base] = ++ptr;
    LCT.link(at[base], at[root]);
    
    for(int i = 0; i < n; i++){
        a[i] = X[i];
        insert(a[i]);
    }
}

int update(int i, int y){
    remove(a[i]);
    a[i] = y;
    insert(a[i]);
    
    return LCT.query(at[root], at[base]).dp;
}

#ifndef ONLINE_JUDGE

void print(int X){
    printf("%d\n", X);
}

int main(){
    int X[] = { 10 , 15 , 17 , 20 };
    init(4, 10, X);
    
    print(update(2,16));
    print(update(1,25));
    print(update(3,35));
    print(update(0,38));
    print(update(2,0));
    
    return 0;
}

#endif