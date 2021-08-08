#include <iostream>
#include <vector>
#define MM 10002
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
std::vector<int> adj[MM];
int N,M,a,b,X,Y;
bool vis[MM];
void dfs(int cur){
    for(int u: adj[cur]){
        if(!vis[u]){
            vis[u] = 1;
            dfs(u);
        }
    }
}
int main(){
    sc(N); sc(M);
    while(M--){
        sc(a); sc(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    sc(X); sc(Y);
    vis[X] = 1;
    dfs(X);
    printf(vis[Y]? "1\n": "0\n");
    return 0;
}