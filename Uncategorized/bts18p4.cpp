#include <bits/stdc++.h>
#define MM 100002
using namespace std;
typedef long long ll;
ll y;
vector<int> adj[MM];
int dis[MM],N,root,maxd,ans;
bool boo[MM];
void dfs(int cur, int pre){
    for(int &u: adj[cur]){
        if(u != pre){
            dis[u] = dis[cur] + 1;
            if(dis[u] > maxd){
                maxd = dis[u];
                root = u;
            }
            dfs(u,cur);
        }
    }
}
inline bool check(ll y){
    if(y == 1)
        return 0;
    /*
    ll l = 1,m, r = min(y,1000000000LL),temp;
    while(l <= r){
        m = (l+r)/2;
        //printf("%lld\n",m);
        temp = m*(m+1);
        if(temp == y)
            return 1;
        if(temp > y)
            r = m-1;
        else
            l = m+1;
    }
    l = 1, r = min(y,1000000000LL);
    while(l <= r){
        m = (l+r)/2;
        //printf("%lld\n",m);
        temp = m*(m-1);
        if(temp == y)
            return 1;
        if(temp > y)
            r = m-1;
        else
            l = m+1;
    }
     */
    ll temp = (ll)floor(sqrtl(y));
    for(ll i = temp - 5; i <= temp + 5; i++){
        if(i * (i+1) == y)
            return 1;
    }
    return 0;
    //return floor(sqrtl(y)) * ceil(sqrtl(y)) == y && y != 1;
    //bs
}
int main(){
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        scanf("%lld",&y);
        if(check(y)){
            boo[i] = 1;
            //root = i;
            //printf("%d %d\n", (int)floor(sqrt(y)), y);
        }
    }
    for(int i = 0,a,b; i < N-1; i++){
        scanf("%d%d",&a,&b);
        if(boo[a] && boo[b]){
            //printf("%d %d\n",a,b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    for(int i = 1; i <= N; i++){
        if(!boo[i] || dis[i])
            continue;
        //root
        maxd = 1;
        dis[i] = 1;
        dfs(i, -1);

        //length
        dis[root] = 1;
        dfs(root, -1);
        ans = max(ans,maxd);
    }
    printf("%d\n",ans);
    return 0;
}
//each node can be used at most once
//looking for length of tree
//root the tree and find longest dis from there

//x could be negative too