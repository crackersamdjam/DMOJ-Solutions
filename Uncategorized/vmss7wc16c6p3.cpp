#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS
#endif
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 1e5+2;

int N, M, dfn[MM], low[MM], t;
vector<int> adj[MM];
bool vis[MM];
set<int> ans;

void dfs(int cur, int pre){
    for(int &u: adj[cur]){
        if(u != pre){
            if(!vis[u]){
                vis[u] = 1;
                dfn[u] = low[u] = ++t;
                dfs(u, cur);
                
                low[cur] = min(low[cur], low[u]);
                
                if(pre == -1 && low[u] > dfn[cur])
                    ans.insert(cur);
                if(pre != -1 && low[u] >= dfn[cur]){
                    ans.insert(cur);
                }
            }
            else
                low[cur] = min(low[cur], dfn[u]);
        }
    }
}

int main(){
    
    scan(N, M);
    
    for(int i = 0,a,b; i < M; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            vis[1] = 1;
            dfs(1, -1);
        }
    }
    
    print(ans.size());
    
    for(int i: ans)
        print(i);
    
    return 0;
}