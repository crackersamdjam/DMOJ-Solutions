#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

struct LinkCut{
    struct node{
        int ch[2] = {0, 0}, p = 0, pp = 0, val = 0, max = 0, lp = INT_MAX;
        bool flip = 0;
    };
    vector<node> T;
    LinkCut(int n) : T(n+1) {}
    
    int dir(int x, int y){
        return T[x].ch[1] == y;
    }
    void set(int x, int d, int y){
        if(x) T[x].ch[d] = y, pull(x);
        if(y) T[y].p = x;
    }
    
    void pull(int x){
        if(!x) return;
        int l = T[x].ch[0], r = T[x].ch[1];
        push(l), push(r);
        T[x].max = max({T[x].val, T[l].max, T[r].max});
    }
    
    void push(int x){
        if(!x) return;
        int &l = T[x].ch[0], &r = T[x].ch[1];
        if(T[x].flip){
            swap(l, r);
            T[l].flip ^= 1;
            T[r].flip ^= 1;
            T[x].flip = 0;
        }
        int &v = T[x].lp;
        T[x].val = min(T[x].val, v);
        T[x].max = min(T[x].max, v);
        T[l].lp = min(T[l].lp, v);
        T[r].lp = min(T[r].lp, v);
        v = INT_MAX;
    }
    
    void rotate(int x, int d){ //0 going left, 1 going right
        int y = T[x].p, z = T[ y].p, w = T[x].ch[d];
        swap(T[x].pp, T[y].pp);
        set(y, !d, w);
        set(x, d, y);
        set(z, dir(z, y), x);
    }
    
    void splay(int x){
        push(x);
        while(T[x].p){
            int y = T[x].p, z = T[y].p;
            push(z), push(y), push(x);
            int dx = dir(y, x), dy = dir(z, y);
            if(!z)
                rotate(x, !dx);
            else if(dx == dy)
                rotate(y, !dy), rotate(x, !dx);
            else
                rotate(x, !dx), rotate(x, !dy);
        }
    }
    
    //return last jump for lca
    int access(int n){
        int x = 0, y = n;
        while(y){
            splay(y), splay(x);
            //replace rc
            int r = T[y].ch[1];
            swap(T[r].p, T[r].pp);
            T[x].pp = 0;
            set(y, 1, x);
            
            x = y;
            y = T[y].pp;
        }
        splay(n);
        return x;
    }
    
    void evert(int x){
        access(x);
        int l = T[x].ch[0];
        swap(T[l].p, T[l].pp);
        T[l].flip ^= 1;
        set(x, 0, 0);
    }
    
    bool connected(int u, int v){
        if(u == v) return 1;
        evert(u); access(v); splay(u);
        return T[v].p == u || T[T[v].p].p == u;
        //evert u puts in on prefered path from root
        //access makes new pp and top of splays
        //splay u, u either direct ch (left ch) or jump once to pp
    }
    
    void link(int u, int v){
        assert(!connected(u, v));
        if(connected(u, v)) return;
        evert(v);
        T[v].pp = u;
    }
    
    void cut(int u, int v){
        evert(u); access(u); splay(v);
        assert(T[v].pp == u);
        T[u].pp = 0;
    }
    
    void cutpar(int u, int root){
        evert(root);
        access(u);
        cut(u, T[u].ch[0]);
    }
    
    node query(int x, int y){
        evert(x); access(y);
        return T[y];
    }
    
    void update(int x, int y, int v){
        evert(x); access(y);
        T[y].lp = min(T[y].lp, v);
    }
};

constexpr int MM = 3e5+9;
LinkCut LCT(MM);

int n, m, q, ptr;

int main(){
    scan(n, m, q);
    ptr = n+5;
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        assert(a >= 0 and a <= n+1);
        assert(b >= 0 and b <= n+1);
        a++, b++;
        if(a == b)
            continue;
        if(!LCT.connected(a, b)){
            ptr++;
            LCT.T[ptr].val = INT_MAX;
            LCT.T[ptr].max = INT_MAX;
            LCT.link(a, ptr);
            LCT.link(b, ptr);
        }
        else{
            LCT.update(a, b, i);
        }
    }
    
    for(int i = 0,a,b; i < q; i++){
        scan(a, b);
        a++, b++;
        assert(a >= 0 and a <= n+1);
        assert(b >= 0 and b <= n+1);
        if(a == b){
            print(0);
            continue;
        }
        if(!LCT.connected(a, b)){
            print(-1);
            continue;
        }
        int v = LCT.query(a, b).max;
        if(v == INT_MAX)
            v = -1;
        
        print(v);
    }
    
    return 0;
}