#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 1e5+5;

#ifndef ONLINE_JUDGE
template<typename T>
void printerr(T a){std::cout<<a<<std::endl;}
template<typename T,typename... Args>
void printerr(T a, Args... args) {std::cout<<a<<' ',printerr(args...);}
#else
template<typename... Args>
void printerr(Args... args){}
#endif

struct LinkCut {
    struct node{
        int p = 0, ch[2] = {0, 0}, pp = 0, sz = 0;
        bool flip = 0;
        ll val = 0, dp = 0;
    };
    vector<node> T;
    int ptr;
    
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
        T[x].dp = T[x].val ^ T[l].dp ^ T[r].dp;
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
    
    void update(int v, int w, ll x){
        makeroot(w), access(v);
        T[v].val ^= x;
    }
    
    int findroot(int u){
        access(u);
        while(T[u].ch[0])
            u = T[u].ch[0];
        splay(u);
        return u;
    }
    
    int lca(int v, int w){
        access(v);
        return access(w);
        //v already on preferred path
        //returning last time w had to jump to join preferred path (with v)
    }
    
    void wtf(int x, int y){
        //change x's par to y, unless y is in x's subtree
        if(lca(x, y) == x) return;
        access(x);
        cut(x, T[x].ch[0]);
        link(x, y);
    }
};

int n, q, ptr;
map<pair<int, int>, int> mp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    LinkCut LCT(n+n+q+5);
    
    ptr = n;
    for(int i = 0,a,b,c; i < n-1; i++){
        cin>>a>>b>>c;
        if(a > b) swap(a, b);
        mp[{a, b}] = ++ptr;
        LCT.link(a, ptr);
        LCT.link(b, ptr);
        LCT.update(ptr, ptr, c);
    }
    for(int i = 0,a,b,c; i < q; i++){
        char op;
        cin>>op>>a>>b;
        if(op == 'A'){
            cin>>c;
            if(a > b) swap(a, b);
            mp[{a, b}] = ++ptr;
            LCT.link(a, ptr);
            LCT.link(b, ptr);
            LCT.update(ptr, ptr, c);
        }
        if(op == 'R'){
            if(a > b) swap(a, b);
            int id = mp[{a, b}];
            LCT.cut(a, id);
            LCT.cut(b, id);
        }
        if(op == 'Q'){
            cout<<(LCT.connected(a, b) ? LCT.query(a, b).dp : -1)<<'\n';
        }
    }
    
    return 0;
}

/*
 notes:
 only push during splay x, x->p, x->p->p or right before pull
 only pull in "set" function
 
 */