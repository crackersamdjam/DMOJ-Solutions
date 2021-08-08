#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define MM 20002
#define f first
#define s second
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef pair<int,int> pii;
int N,M, dis[MM], dis2[MM];
vector<pii> adj[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;
int main(){
    memset(dis,0x3f,sizeof(dis));
    memset(dis2,0x3f,sizeof(dis2));
    sc(N); sc(M);
    for(int i = 0,a,b,c; i < M; i++){
        sc(a); sc(b); sc(c);
        adj[a].push_back({b,c});
    }
    dis[1] = 0;
    q.push({0,1});
    while(!q.empty()){
        int curd = q.top().f, cur = q.top().s; q.pop();
        for(auto &e: adj[cur]){
            if(curd + e.s < dis[e.f]){
                dis2[e.f] = dis[e.f];
                dis[e.f] = curd + e.s;
                q.push({dis[e.f], e.f});
            }else if(curd + e.s < dis2[e.f] && curd + e.s > dis[e.f]){
                dis2[e.f] = curd + e.s;
                q.push({dis2[e.f], e.f});
            }
        }
    }
    printf("%d\n", (dis2[N] == 0x3f3f3f3f? -1: dis2[N]));
    return 0;
}