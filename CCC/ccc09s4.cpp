#include <bits/stdc++.h>
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef std::pair<int,int> pii;
#define MM 5002
#define f first
#define s second
std::queue<int> q;
std::vector<pii> adj[MM];
int dis[MM],N,T,k,d,x,y,c,z,p;
bool inq[MM];
int main(){
    memset(dis,0x3f,sizeof(dis));
    scan(N); scan(T);
    while(T--){
        scan(x); scan(y); scan(c);
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }
    scan(k);
    while(k--){
        scan(z); scan(p);
        dis[z] = p;
        q.push(z);
        inq[z] = 1;
    }
    scan(d);
    while(!q.empty()){
        int cur = q.front(); q.pop(); inq[cur] = false;
        for(auto e: adj[cur]){
            if(dis[cur]+e.s < dis[e.f]){
                dis[e.f] = dis[cur]+e.s;
                if(!inq[e.f])
                    q.push(e.f), inq[e.f] = true;
            }
        }
    }
    printf("%d\n",dis[d]);
    return 0;
}