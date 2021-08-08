#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}
const int MM = 2e4+2;
int n, m, k, ca, cb, cc, par[MM];
int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}
void merge(int a, int b){
    a = find(a), b = find(b);
    par[a] = b;
}
struct edge{
    int a, b, c, d;
    bool operator<(const edge &o) const{
        return c < o.c;
    }
};
vector<edge> edges;

bool test(int v){
    ca = cb = cc = 0;
    for(int i = 1; i <= n; i++)
        par[i] = i;
    for(auto e: edges){
        int a = find(e.a), b = find(e.b);
        if(a == b) continue;
        if(e.c <= v)
            ca++, par[a] = b;
        else if(e.d <= v)
            cb++, par[a] = b;
    }
    int id = find(1);
    for(int i = 1; i <= n; i++)
        if(find(i) != id)
            return 0;
    return ca >= k;
}

int main(){
    init();
    scan(n, k, m);
    edges.resize(m);
    for(int i = 0; i < m; i++)
        scan(edges[i].a, edges[i].b, edges[i].c, edges[i].d);
    sort(edges.begin(), edges.end());

    int l = 0, mid, r = 3e4+1;
    while(l <= r){
        mid = (l+r)/2;
        if(test(mid))
            r = mid-1;
        else
            l = mid+1;
    }
    print(l);
    
    return 0;
}