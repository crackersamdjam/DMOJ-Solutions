#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MM 3002
#define f first
#define s second
#define inf 0x7f7f7f7f7f7f7f7fLL
typedef unsigned long long ll;
std::pair<int,int> cord[MM];
int N,X,Q,x,y;
ll adj[MM][MM],dis[MM],qi;
bool vis[MM];
int main(){
    sc(N);
    for(int i = 1; i <= N; i++){
        sc(x); sc(y);
        cord[i] = {x,y};
        for(int j = 1; j < i; j++){
            adj[i][j] = adj[j][i] = (ll)(cord[j].f - cord[i].f)*(cord[j].f - cord[i].f) +
                                    (ll)(cord[j].s - cord[i].s)*(cord[j].s - cord[i].s);
        }
    }
    sc(X); sc(Q);
    memset(dis,0x7f,sizeof(dis));
    //Dijkstra n^2
    dis[X] = 0;
    for(int i = 1; i <= N; i++){
        int u = -1;
        ll nx = inf;
        for(int j = 1; j <= N; j++){
            if(!vis[j] && dis[j] < nx){
                nx = dis[j];
                u = j;
            }
        }
        if(u == -1)
            break;
        vis[u] = 1;
        for(int j = 1; j <= N; j++){
            if(dis[u] + adj[u][j] < dis[j]){
                dis[j] = dis[u] + adj[u][j];
            }
        }
    }
    std::sort(dis+1,dis+1+N);
    while(Q--){
        sc(qi);
        printf("%ld\n",std::upper_bound(dis+1, dis+1+N, qi)-dis-1);
    }
    return 0;
}