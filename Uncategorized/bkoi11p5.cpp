#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 202, MN = 1e4+2;

int n, m, par[MM];
struct edge{
    int a, b, c, d;
} edges[MN];

struct res{
    int cost, sa, sb;
    vector<edge> v;
} ans;

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

void run(int ra, int rb, int &sa, int &sb){
    for(int i = 0; i < n; i++)
        par[i] = i;
    sort(edges, edges+m, [&](const edge &x, const edge &y){
        return x.c*ra+x.d*rb < y.c*ra+y.d*rb;
    });
    res cur;
    sa = sb = 0;
    for(int i = 0; i < m; i++){
        int fa = find(edges[i].a), fb = find(edges[i].b);
        if(fa != fb){
            par[fb] = fa;
            sa += edges[i].c;
            sb += edges[i].d;
            cur.v.push_back(edges[i]);
        }
    }
    cur.cost = sa*sb, cur.sa = sa, cur.sb = sb;
    if(cur.cost < ans.cost)
        ans = cur;
}

int cross(int ax, int ay, int bx, int by) {
    return ax*by - ay*bx;
}

void go(int ax, int ay, int bx, int by){
    int cx, cy;
    run(ay-by, bx-ax, cx, cy);
    
    //if area <= 0, return
    if(cross(cx-ax, cy-ay, bx-cx, by-cy) <= 0)
        return;
    
    go(ax, ay, cx, cy);
    go(cx, cy, bx, by);
}

int main(){
    ans.cost = 1e9;
    scan(n, m);
    for(int i = 0; i < m; i++){
        scan(edges[i].a, edges[i].b, edges[i].c, edges[i].d);
    }
    int sax, say, sbx, sby;
    run(1, 0, sax, say);
    run(0, 1, sbx, sby);
    go(sax, say, sbx, sby);
    
    print(ans.sa, ans.sb);
    
    for(auto i: ans.v)
        print(i.a, i.b);
    
    return 0;
}