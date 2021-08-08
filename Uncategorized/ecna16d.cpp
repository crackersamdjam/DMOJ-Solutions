#include <bits/stdc++.h>
#define MM 101
#define f first
#define s second
using namespace std;
vector<pair<int,int>> adj[MM];
unordered_map<string,int> mp;
string str,A,B;
queue<int> q;
int dis[MM],path[MM],N,M,a,b,c,sum = 0;
bool inq[MM];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    mp.insert({"English",0});
    for(int i = 1; i <= N; i++){
        cin >> str;
        mp.insert({str,i});
    }
    while(M--){
        cin >> A >> B >> c;
        a = mp[A], b = mp[B];
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    memset(dis,0x3f,sizeof(dis));
    dis[0] = 0, inq[0] = 1;
    q.push(0);
    while(!q.empty()){
        int cur = q.front(); q.pop(); inq[cur] = 0;
        for(const auto &e: adj[cur]){
            if(dis[cur]+1 < dis[e.f]){
                dis[e.f] = dis[cur]+1;
                path[e.f] = e.s;
                if(!inq[e.f]){
                    q.push(e.f);
                    inq[e.f] = 1;
                }
            }else if(dis[cur]+1 == dis[e.f] && e.s < path[e.f]){
                path[e.f] = e.s;
                if(!inq[e.f]){
                    q.push(e.f);
                    inq[e.f] = 1;
                }
            }
        }
    }
    for(int i = 1; i <= N; i++){
        if(!path[i]){
            printf("Impossible\n");
            return 0;
        }
        sum += path[i];
    }
    printf("%d\n",sum);
    return 0;
}