#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

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
using T = pii;
const int MM = 3e5+5;
int adj = 1e5+5;

struct node{
    T val;
    set<T> st;
};

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
    node tree[MM*4];
    T DEF = {INT_MAX, 0};
    //default value
    
    T merge(T va, T vb){
        return max(va, vb);
    }
    
    void push_up(int rt){
        tree[rt].val = merge(tree[lc].val, tree[rc].val);
    }
    
    void build(int l = 0, int r = MM-1, int rt = 1){
        int nl = l, nr = r;
        if(l == r){
            tree[rt].val = DEF;
            return;
        }
        build(l, nm, lc);
        build(nm+1, r, rc);
        push_up(rt);
    }
    
    void update(int l, int r, T val, int nl = 0, int nr = MM-1, int rt = 1){
        if(r < nl || l > nr)
            return;
        
        if(l <= nl && r >= nr){
            tree[rt].st.insert(val);
            return;
        }
        update(l, r, val, nl, nm, lc);
        update(l, r, val, nm+1, nr, rc);
        push_up(rt);
    }
    
    T query(int l, int r, int nl = 0, int nr = MM-1, int rt = 1){
        if(r < nl || l > nr)
            return DEF;
        if(l <= nl && r >= nr)
            return tree[rt].val;
        return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
    }
#undef lc
#undef rc
#undef nm
} ST;

int n, ans;
pii a[MM];
#define x first
#define y second

bool done[MM];
set<int, greater<int>> in;

int main(){
    
    scan(n);
    for(int i = 0,f,s; i < n; i++){
        scan(f, s);
        a[i].x = f+s, a[i].y = s-f;
//        print(a[i].x, a[i].y);
    }
    sort(a, a+n);
    
    for(int i = 0; i < n; i++){
        auto ptr = in.lower_bound(a[i].y);
        if(ptr != in.end()){
//            printerr("rep", *ptr, a[i].y);
            in.erase(ptr);
            in.insert(a[i].y);
        }
        else{
            in.insert(a[i].y);
            ans++;
//            printerr("ins", a[i].y);
        }
    }
    
    print(ans);
    
    return 0;
}

/*

    in.insert(3);
    in.insert(5);
    print(*in.lower_bound(4));
    in.insert(4);
    print(*in.lower_bound(4));
 */