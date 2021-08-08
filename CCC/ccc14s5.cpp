#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2001;

int N, x[MM], y[MM], dp[MM], pre[MM];
ll dis[MM];
struct edge{
    int a, b;
    ll d;
    edge(int aa, int bb, ll dd): a(aa), b(bb), d(dd){}
    
    friend bool operator<(edge x, edge y){
        return x.d < y.d;
    }
};
vector<edge> edges;

int main(){
    
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++){
        scanf("%d%d", x+i, y+i);
        for(int j = 0; j < i; j++){
            ll dis = ll(x[i] - x[j]) * ll(x[i] - x[j]) + ll(y[i] - y[j]) * ll(y[i] - y[j]);
            edges.push_back(edge(i, j, dis));
        }
    }
    
    sort(edges.begin(), edges.end());
    
    for(edge &e: edges){
        
        //update when edge w changes
        if(e.d > dis[e.a]){
            dis[e.a] = e.d;
            pre[e.a] = dp[e.a];
        }
        
        if(e.d > dis[e.b]){
            dis[e.b] = e.d;
            pre[e.b] = dp[e.b];
        }
    
        //0 is not valid location
        if(e.b) dp[e.a] = max(dp[e.a], pre[e.b] + 1);
        dp[e.b] = max(dp[e.b], pre[e.a] + 1);
    }
    
    printf("%d\n", dp[0]);
    
    return 0;
}