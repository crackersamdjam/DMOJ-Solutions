#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1001, NN = 2100;
typedef pair<int, pair<int, int>> pii;

int n, m, ans = 1000, ptr;
set<pii> adj[NN][MM];
bool done[NN][MM];


void go(int k, int t){
    assert(t < NN);
    int mv = 0;
    pair<int, int> id = {0, 0};
    
    for(int i = 1; i <= n; i++){
        if(done[t][i])
            continue;
        while(!adj[t][i].empty() && done[t][adj[t][i].begin()->second.second])
            adj[t][i].erase(adj[t][i].begin());
        if(adj[t][i].empty())
            continue;
        int v = -adj[t][i].begin()->first;
        if(v > mv)
            mv = v, id = {adj[t][i].begin()->second};
    }
    
    ans = min(ans, mv + k*k*10);
    if(!mv || mv < 10*((k+1)*(k+1) - k*k) || k > 10)
        return;
    
    //each end
    ptr++;
    for(int i = 1; i <= n; i++)
        done[ptr][i] = done[t][i];
    done[ptr][id.first] = 1;
    for(int i = 1; i <= n; i++){
        if(done[ptr][i])
            continue;
        for(auto u: adj[t][i]){
            if(!done[ptr][u.second.second]){
                adj[ptr][i].insert(u);
            }
        }
    }
    go(k+1, ptr);
    
    ptr = t;
    done[ptr][id.second] = 1;
    /*
    for(int i = 1; i <= n; i++)
        done[ptr][i] = done[t][i];
    for(int i = 1; i <= n; i++){
        if(done[ptr][i])
            continue;
        for(auto u: adj[t][i]){
            if(!done[ptr][u.second.second]){
                adj[ptr][i].insert(u);
            }
        }
    }
     */
    go(k+1, ptr);
}

int main(){
    
    scan(n, m);
    
    for(int i = 0,a,b,c; i < m; i++){
        scan(a, b, c);
        adj[0][a].insert({-c, {a, b}});
        adj[0][b].insert({-c, {b, a}});
    }
    
    go(0, 0);
    
    print(ans);
    
    return 0;
}