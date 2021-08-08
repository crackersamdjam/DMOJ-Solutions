#include <bits/stdc++.h>
#define f first
#define s second
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int MM = 1e5+2;
typedef long long ll;
typedef pair<int,int> pii;
vector<pii> adj[MM];
int N, M, Q, ed, cnt, par[MM];
ll dis[MM], len, totlen, rad, maxrad;
bool vis[MM];
void dfs(int cur, int pre){
    if(dis[cur] > len){
        len = dis[cur];
        ed = cur;
    }
    for(auto &e: adj[cur]){
        if(e.f != pre){
            vis[e.f] = 1;
            dis[e.f] = dis[cur] + e.s;
            par[e.f] = cur;
            dfs(e.f, cur);
        }
    }
}
inline void go(int st){
    len = 0, rad = LLONG_MAX, ed = 0;
    
    vis[st] = 1;
    dis[st] = 0;
    par[st] = -1;
    dfs(st, -1);
    
    //printf("1st %d\n", ed);
    dis[ed] = 0;
    par[ed] = -1;
    dfs(ed, -1);
    //printf("2nd %d\n", ed);
    
    if(Q == 1){
        totlen += len + 1;
    }else{
        dis[ed] = 0;
        par[ed] = -1;
        len = 0;
        dfs(ed, -1);
        
        //printf("ed %d par %d\n", ed,par[ed]);
        while(ed != -1){
            if(max(dis[ed], len - dis[ed]) < rad)
                rad = max(dis[ed], len - dis[ed]);
            else break;
            ed = par[ed];
        }
        //printf("rad %d\n", rad);
        if(rad > maxrad){
            maxrad = rad;
            cnt = 1;
        }else if(rad == maxrad){
            cnt++;
        }
    }
}
int main(){
    sc(N); sc(M); sc(Q);
    for(int i = 0,a,b,c; i < M; i++){
        sc(a); sc(b); sc(c);
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            go(i);
        }
    }
    if(Q == 1){
        totlen--; //overcounted 1
        printf("%lld\n", totlen);
    }else{
        if(cnt > 1)
            maxrad++;
        printf("%lld\n", maxrad);
    }
    return 0;
}