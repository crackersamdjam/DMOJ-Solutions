#include <bits/stdc++.h>
using namespace std;
const int MM = 3e4+5;

#define l T[x].ch[0]
#define r T[x].ch[1]

int n, q, a[MM];

struct LCTree{
    struct node{
        int ch[2] {0, 0}, p = 0, pp = 0, flip = 0, val = 0, dp = 0;
    } T[MM];
    
    void push(int x){
        if(!x) return;
        if(T[x].flip){
            swap(l, r);
            T[l].flip ^= 1, T[r].flip ^= 1;
            T[x].flip = 0;
        }
    }
    
    void pull(int x){
        if(!x) return;
        push(l), push(r);
        T[x].dp = T[x].val + T[l].dp + T[r].dp;
    }
    
    bool dir(int x, int y){
        return T[x].ch[1] == y;
    }
    
    void set(int x, int d, int y){
        if(x) T[x].ch[d] = y, pull(x);
        if(y) T[y].p = x;
    }
    
    void rotate(int x, int d){
        int y = T[x].p, z = T[y].p, w = T[x].ch[d];
        swap(T[x].pp, T[y].pp); // if y is root
        set(y, !d, w);
        set(x, d, y);
        set(z, dir(z, y), x);
    }
    
    void splay(int x){
        push(x);
        while(T[x].p){
            int y = T[x].p, z = T[y].p;
            push(z); push(y); push(x);
            int dx = dir(y, x), dy = dir(z, y);
            if(!z)
                rotate(x, !dx);
            else if(dx == dy)
                rotate(y, !dy), rotate(x, !dx);
            else
                rotate(x, !dx), rotate(x, !dy);
        }
    }
    
    int access(int u){
        int x = 0, y = u;
        while(y){
            splay(x), splay(y);
            
            int w = T[y].ch[1];
            swap(T[w].p, T[w].pp);
            T[x].pp = 0;
            set(y, 1, x);
            
            x = y, y = T[y].pp;
        }
        splay(u);
        return x;
    }
    
    void root(int x){
        access(x);
        T[l].flip ^= 1;
        swap(T[l].p, T[l].pp);
        set(x, 0, 0);
    }
    
    int lca(int x, int y){
        access(x);
        return access(y);
    }
    
    int query(int x, int y){
        root(x); access(y);
        return T[y].dp;
    }
    
    void update(int x, int v){
        root(x); access(x);
        T[x].val = v;
    }
    
    bool con(int x, int y){
        if(x == y) return 1;
        root(x); access(y); splay(x);
        return T[y].p == x or T[T[y].p].p == x; //check
    }
    
    void link(int x, int y){
        assert(!con(x, y));
        root(y);
        T[y].pp = x;
    }
};

LCTree LCT;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        LCT.update(i, a[i]);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
        string s; int x, y;
        cin >> s >> x >> y;
        if(s[0] == 'b'){
            if(LCT.con(x, y))
                cout << "no\n";
            else{
                LCT.link(x, y);
                cout << "yes\n";
            }
        }
        else if(s[0] == 'p'){
            a[x] = y;
            LCT.update(x, y);
        }
        else{
            if(!LCT.con(x, y))
                cout << "impossible\n";
            else
                cout << LCT.query(x, y) << '\n';
        }
    }
    
    return 0;
}