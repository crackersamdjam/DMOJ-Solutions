#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define ONLINE_JUDGE

#ifndef ONLINE_JUDGE
template<typename T>
void printerr(T a){std::cout<<a<<std::endl;}
template<typename T,typename... Args>
void printerr(T a, Args... args) {std::cout<<a<<' ',printerr(args...);}
#else
template<typename... Args>
void printerr(Args... args){}
#endif

using namespace std;
using pii = pair<int, int>;

struct LinkCut {
    struct node{
        int p = 0, ch[2] = {0, 0}, pp = 0, sz = 0;
        pii val = {0, 0}, max = {0, 0};
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
        T[x].max = max({T[x].val, T[l].max, T[r].max});
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
    
    void update(int v, int x){
        makeroot(v), access(v);
        T[v].val = {x, v};
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

int n, m, q, ans[MM], ga[MM], gb[MM];
multiset<int> in;

struct st{
    int op, a, b, x, y, id;
} qu[MM];

int main(){
    scan(n, m, q);
    for(int i = 0; i < m; i++){
        scan(qu[i].a, qu[i].b, qu[i].x, qu[i].y);
        ga[i] = qu[i].a, gb[i] = qu[i].b;
        qu[i].id = n+1+i;
    }
    for(int i = m; i < m+q; i++){
        scan(qu[i].x, qu[i].y);
        qu[i].op = 1;
        qu[i].id = i-m;
    }
    sort(qu, qu+m+q, [](st a, st b){
        if(a.x == b.x)
            return a.op < b.op;
        return a.x > b.x;
    });
    
    for(int j = 0; j < m+q; j++){
        auto i = qu[j];
        if(!i.op){
            printerr("cur", i.a, i.b, i.x, i.y);
            if(!LCT.connected(i.a, i.b)){
                printerr("add", i.a, i.b, i.id, i.y);
                LCT.link(i.a, i.id);
                LCT.link(i.b, i.id);
                LCT.update(i.id, i.y);
                in.insert(i.y);
                continue;
            }
            auto res = LCT.query(i.a, i.b).max;
            if(i.y < res.first){
                int id = res.second;
                printerr("rep", id, res.first);
                
                LCT.makeroot(id);
                printerr("ch", id, ga[i.id-1-n], gb[i.id-1-n]);
                LCT.cut(id, ga[i.id-1-n]);
                LCT.makeroot(id);
                LCT.cut(id, gb[i.id-1-n]);
                in.erase(in.lower_bound(res.first));
                
                printerr("rm", i.a, i.b, i.id, i.y);
                LCT.link(i.a, i.id);
                LCT.link(i.b, i.id);
                LCT.update(i.id, i.y);
                in.insert(i.y);
            }
        }
        else{
            ans[i.id] = (in.size() == n-1 and *in.rbegin() <= i.y);
        }
    }
    
    for(int i = 0; i < q; i++)
        puts(ans[i]?"YES":"NO");
    
    return 0;
}