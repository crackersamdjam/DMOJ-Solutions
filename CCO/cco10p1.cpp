#include <bits/stdc++.h>
#define MM 1002
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
vector<pii> adj[MM];
unordered_set<int> bark[MM];
int D,F,a,b,T,arr[MM];
bool waiting[MM];
priority_queue<pii,vector<pii>,greater<pii>> q;
int main(){
    scanf("%d",&D);
    for(int i = 1; i <= D; i++)
        scanf("%d", arr+i);
    scanf("%d",&F);
    while(F--){
        scanf("%d%d",&a,&b);
        adj[a].push_back({b,arr[b]});
    }
    scanf("%d",&T);
    q.push({0,1});
    bark[1].insert(0);
    vector<int> temp;
    for(int i = 0; i <= T; i++){
        while(!q.empty() && q.top().f == i){
            int cur = q.top().s, t = q.top().f; q.pop();
            temp.push_back(cur);
            for(const auto &e: adj[cur]){
                if(t + e.s <= T && !waiting[e.f] &&
                   !bark[e.f].count(t + e.s)){
                    waiting[e.f] = 1;
                    q.push({t + e.s, e.f});
                    bark[e.f].insert(t + e.s);
                }
            }
        }
        for(const int &j: temp)
            waiting[j] = 0;
        temp.clear();
    }
    for(int i = 1; i <= D; i++)
        printf("%d\n", (int)bark[i].size());
    return 0;
}