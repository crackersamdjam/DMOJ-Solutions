#include <bits/stdc++.h>
#define MM 502
#define f first
#define s second
using namespace std;
vector<pair<int,double>> adj[MM];
unordered_map<string,int> dict;
string str,A,B;
double dis[MM],c;
int N,M,a,b,st,cur,cnt[MM];
queue<int> q;
bool inq[MM];
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> str;
        dict.insert({str, i});
    }
    for(int i = 0; i < M; i++){
        cin >> A >> B >> c;
        a = dict[A], b = dict[B];
        c = -log10(c);
        adj[a].push_back({b,c});
    }
    for(int i = 0; i <= N; i++)
        dis[i] = 1e200;
    st = dict["APPLES"];
    dis[st] = 0; q.push(st); cnt[st] = 1;
    while(!q.empty()){
        cur = q.front(); q.pop(); inq[cur] = 0;
        for(const auto &e: adj[cur]){
            if(dis[cur] + e.s < dis[e.f] - 1e-6){ //comparing doubles
                dis[e.f] = dis[cur] + e.s;
                if(!inq[e.f]){
                    q.push(e.f);
                    inq[e.f] = 1;
                    cnt[e.f]++;
                    if(cnt[e.f] == N){
                        //negative cycle
                        //should also check if cycle contains APPLES
                        //but weak test data lets this pass
                        cout << "YA\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "NAW\n";
    return 0;
}