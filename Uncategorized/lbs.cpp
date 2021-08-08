#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

template<typename T> T max(T n){return; n;}
template<typename First, typename ... Ints> First max(First arg, Ints... rest){return max(arg, print(rest...));}

using namespace std;
using T = int;
const int MM = 1e5+5;

int n, q;
char s[MM];

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

struct node{
    T sum, el, er;
    bool up;
    void apply(){
        swap(el, er);
        up ^= 1;
    }
};

struct segmenttree{
    node tree[MM*3];
    node DEF = {0, 0, 0};
    //default value
    
    node merge(node va, node vb){
        node ret;
        int cnt = min(va.er, vb.el);
        ret.sum = cnt*2 + va.sum + vb.sum;
        ret.el = va.el + vb.el - cnt;
        ret.er = va.er + vb.er - cnt;
        return ret;
    }
    
    void push_up(int rt){
        tree[rt] = merge(tree[lc], tree[rc]);
    }
    
    // node with lazy val means yet to push to children (but updated itself)
    void push_down(int rt, int nl, int nr){
        if(tree[rt].up && nl != nr){
            tree[lc].apply();
            tree[rc].apply();
        }
        tree[rt].up = 0;
    }
    
    void build(int l = 1, int r = n, int rt = 1){
        int nl = l, nr = r;
        if(l == r){
            if(s[l] == ')') tree[rt].el = 1;
            else tree[rt].er = 1;
            return;
        }
        build(l, nm, lc);
        build(nm+1, r, rc);
        push_up(rt);
    }
    
    void update(int l, int r, int nl = 1, int nr = n, int rt = 1){
        if(r < nl || l > nr)
            return;
        if(l <= nl && r >= nr){
            swap(tree[rt].el, tree[rt].er);
            //tree[rt].apply();
            return;
        }
        //push_down(rt, nl, nr);
        update(l, r, nl, nm, lc);
        update(l, r, nm+1, nr, rc);
        push_up(rt);
    }
    
    node query(int l, int r, int nl = 1, int nr = n, int rt = 1){
        if(r < nl || l > nr)
            return DEF;
        if(l <= nl && r >= nr)
            return tree[rt];
        //push_down(rt, nl, nr);
        return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
    }
} seg;


int main(){
    
    scan(n, q);
    
    for(int i = 1; i <= n; i++)
        s[i] = gc;
    
    seg.build();
    
    for(int i = 0,op,l,r; i < q; i++){
        scan(op, l);
        if(op == 1){
            scan(r);
            print(seg.query(l, r).sum);
        }
        else
            seg.update(l, l);
    }
    
    return 0;
}