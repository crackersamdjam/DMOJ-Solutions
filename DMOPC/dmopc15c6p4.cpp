#include <bits/stdc++.h>
using namespace std;
#define MM 100002
typedef pair<pair<int,int>,int> edg;
vector<edg> edgs;
int parent[MM];
/*struct edg{
    int st,ed,cost;
};*/
bool cmp(edg a, edg b){
    return a.second < b.second;
}
int root(int x){
    while(x!=parent[x]){
        x = parent[x];
        parent[x] = parent[parent[x]];
    } return x;
}
int main() {
    int n,k;
    scanf("%d%d", &n, &k);
    for(int i = 1, v; i < n; i++){
        scanf("%d", &v);
        edgs.push_back({{i,i+1},v});
        if(i+k <= n) edgs.push_back({{i,i+k},0});
        //adj[i].push_back(make_pair(i-1, v));
        //adj[i-1].push_back(make_pair(i, v));
    }
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }
    sort(edgs.begin(), edgs.end(), cmp);
    /*for(edg e: edgs){
        printf("%d %d %d\n", e.first.first, e.first.second, e.second);
    }*/
    //It works
    int sum = 0, E = 0;
    for(edg e: edgs){
        if(root(e.first.first) != root(e.first.second)) {
            //parent[e.first.second] = parent[e.first.first];
            parent[root(e.first.first)] = root(e.first.second);
            //update child nodes
            sum += e.second;
            E++;
            if(E == n-1) break;
        }
    }
    printf("%d\n", sum);
    return 0;
}