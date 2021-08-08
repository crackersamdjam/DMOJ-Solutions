#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
using T = pair<ll, ll>;
using TT = pair<ll, pii>;
const int MM = 1e5+2;

ll dis[3][MM], dist[MM][3];
vector<pii> adj[MM];
priority_queue<T, vector<T>, greater<T>> q;
priority_queue<TT, vector<TT>, greater<TT>> qq;
int n, m, A, B, C, D;

void run(int id, int rt){
    dis[id][rt] = 0;
    q.emplace(0, rt);
    while(q.size()){
        auto rm = q.top(); q.pop();
        int cur = rm.second; ll d = rm.first;
        if(d > dis[id][cur])
            continue;
        for(auto e: adj[cur]){
            int u = e.first, w = e.second;
            if(d+w < dis[id][u]){
                dis[id][u] = d+w;
                q.emplace(dis[id][u], u);
            }
        }
    }
}

bool sp(int u){
    return dis[0][u] + dis[1][u] == dis[0][B];
}

ll ans = LLONG_MAX;

void run(){
    memset(dis, 0x3f, sizeof dis);
    run(0, A);
    run(1, B);
    run(2, D);
    memset(dist, 0x3f, sizeof dist);
    dist[C][0] = 0;
    qq.push({0, {C, 0}});
    if(sp(C)){
        dist[C][1] = dist[C][2] = 0;
        qq.push({0, {C, 1}});
        qq.push({0, {C, 2}});
    }
    while(qq.size()){
        auto rm = qq.top(); qq.pop();
        ll d = rm.first; int cur = rm.second.first, t = rm.second.second;
        if(d > dist[cur][t])
            continue;
        for(auto e: adj[cur]){
            int u = e.first, w = e.second;
            if(t == 1){
                if(sp(u)){
                    if(dis[0][u] > dis[0][cur]){
                        //going up
                        if(d < dist[u][1]){
                            dist[u][1] = d;
                            qq.push({dist[u][1], {u, 1}});
                        }
                    }
                }
            }
            else if(t == 2){
                if(sp(u)){
                    if(dis[0][u] < dis[0][cur]){
                        //going down
                        if(d < dist[u][2]){
                            dist[u][2] = d;
                            qq.push({dist[u][2], {u, 2}});
                        }
                    }
                }
            }
            else{
                if(sp(cur)){
                    if(sp(u)){
                        int v = 1+(dis[0][u]<dis[0][cur]);
                        //up/down
                        if(d < dist[u][v]){
                            dist[u][v] = d;
                            qq.push({dist[u][v], {u, v}});
                        }
                    }
                }
                else{
                    //just normal to normal/special
                    if(d+w < dist[u][0]){
                        dist[u][0] = d+w;
                        qq.push({dist[u][0], {u, 0}});
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i++){
        ans = min(ans, *min_element(dist[i], dist[i]+3) + dis[2][i]);
        //print(dist[i][0], dist[i][1], dist[i][2], dis[0][i], dis[1][i], dis[2][i]);
    }
}

int main(){
    scan(n, m, A, B, C, D);
    for(int i = 0,a,b,c; i < m; i++){
        scan(a, b, c);
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    run();
    swap(C, D);
    run();
    
    print(ans);
    
    return 0;
}