//zeyu
#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

int n, m, ans[250001], par[501], cnt[501];

inline int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}
struct edge{
    int a, b, id;
};
std::vector<edge> edges[100001], good;

int main(){
    
    scan(n, m);
    
    for(int i = 1; i <= n; i++)
        par[i] = i;
    
    for(int i = 0,a,b,c; i < m; i++){
        scan(a, b, c);
        edges[c].push_back({a, b, i});
    }
    
    for(int i = 1; i <= 1e5; i++){
        if(edges[i].empty())
            continue;
        memset(cnt, 0, sizeof(cnt));
        good.clear();
        for(auto &e: edges[i]){
            e.a = find(e.a), e.b = find(e.b);
            if(e.a != e.b){
                good.push_back(e);
                cnt[e.a]++, cnt[e.b]++;
            }
        }
        for(auto e: good){
            if(cnt[e.a] == 1 || cnt[e.b] == 1)
                ans[e.id] = 2;
            else
                ans[e.id] = 1;
            
            int fa = find(e.a), fb = find(e.b);
            if(fa != fb)
                par[fa] = fb;
        }
    }
    
    for(int i = 0; i < m; i++){
        if(ans[i] == 2)
            puts("useful");
        else if(ans[i] == 1)
            puts("so so");
        else
            puts("not useful");
    }
    
    return 0;
}