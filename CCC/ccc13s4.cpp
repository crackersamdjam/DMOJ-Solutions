#include <bits/stdc++.h>
#define MM 1000002
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
vector<int> adj[MM];
int N,M,a,b,st,ed;
bool vis[MM];
inline bool go(int cur){
    if(cur == ed)
        return 1;
    for(int &u: adj[cur]){
        if(!vis[u]){
            vis[u] = 1;
            if(go(u))
                return 1;
        }
    }
    return 0;
}
int main(){
    sc(N); sc(M);
    while(M--){
        sc(a); sc(b);
        adj[a].push_back(b);
    }
    sc(st); sc(ed);
    vis[st] = 1;
    if(go(st))
        printf("yes\n");
    else{
        st += ed; ed = st-ed; st -= ed;
        memset(vis,0,sizeof(vis));
        vis[st] = 1;
        if(go(st))
            printf("no\n");
        else
            printf("unknown\n");
    }
    return 0;
}