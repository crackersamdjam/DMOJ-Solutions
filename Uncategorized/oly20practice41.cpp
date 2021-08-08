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
constexpr int MM = 1e5+5;

int n, m, rt;
int dfn[MM], low[MM], t, path[MM], id[MM], ptr, sz[MM];
bool ins[MM], lead[MM];
vector<int> adj[MM];
set<int> nadj[MM], sadj[MM];

void tarjan(int cur){
    
    ins[cur] = 1;
    path[++ptr] = cur;
    dfn[cur] = low[cur] = ++t;
    
    for(int u: adj[cur]){
        if(!dfn[u]){
            tarjan(u);
            low[cur] = min(low[cur], low[u]);
        }
        else if(ins[u])
            low[cur] = min(low[cur], dfn[u]);
    }
    
    if(dfn[cur] == low[cur]){
        int u = -1;
        lead[cur] = 1;
        while(u != cur){
            u = path[ptr--];
            id[u] = cur;
            ins[u] = 0;
            sz[cur]++;
        }
    }
}

bool need[MM], done[MM];

int cnt;
int dfs(int cur){
    
    if(sadj[cur].size())
        done[cur] = 1;
    if(nadj[cur].size())
        need[cur] = 1;
    
    for(int u: sadj[cur]){
        sz[cur] += dfs(u);
    }
    for(int u: nadj[cur]){
        sz[cur] += dfs(u);
    }
    if(nadj[cur].empty()){
        need[cur] = 1;
        cnt++;
//        printerr("add", cur);
    }
    //add backedge to rt
    return sz[cur];
}

int main(){
    scan(n, m, rt);
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        adj[a].emplace_back(b);
    }
    tarjan(rt);
    
//    for(int i = 1; i <= n; i++)
//        printf("%d ", id[i]);
//    pc(10);
//    for(int i = 1; i <= n; i++)
//        printf("%d ", lead[i]);
//    pc(10);
    
    for(int i = 1; i <= n; i++){
        for(int j: adj[i]){
            int u = id[i], v = id[j];
            if(u != v){
                if(lead[i])
                    sadj[u].insert(v);
                else
                    nadj[u].insert(v);
            }
        }
    }
    
    dfs(id[rt]);
    
    for(int i = 1; i <= n; i++)
        printf("%d ", sz[id[i]]);
    pc(10);
    
    cnt = 0;
    for(int i = 1; i <= n; i++){
        if(need[i] and !done[i])
            cnt++;
    }
    
    print(cnt);
    
    return 0;
}