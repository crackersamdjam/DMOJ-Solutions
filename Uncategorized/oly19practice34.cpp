#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef pair<int, int> pii;
const int MM = 1002;

int dis[MM], disr[MM], ans;
vector<pii> adj[MM], adjr[MM];
int n, m, t;
priority_queue<pii, vector<pii>, greater<pii>> q;

int main(){
    
    scan(n, m, t);
    
    for(int i = 0,a,b,c; i < m; i++){
        scan(a, b, c);
        adj[a].push_back({b, c});
        adjr[b].push_back({a, c});
    }
    
    memset(dis, 0x3f, sizeof dis);
    
    dis[t] = 0;
    
    q.push({0, t});
    
    while(!q.empty()){
        int cur = q.top().second;
        //if(dis[cur] < q.top().first){
          //  q.pop();
            //continue;
        //}
        q.pop();
        
        for(auto u: adj[cur]){
            if(dis[cur] + u.second < dis[u.first]){
                dis[u.first] = dis[cur] + u.second;
                q.push({dis[u.first], u.first});
            }
        }
    }
    
    memset(disr, 0x3f, sizeof disr);
    disr[t] = 0;
    q.push({0, t});
    while(!q.empty()){
        int cur = q.top().second;
        //if(disr[cur] < q.top().first){
          //  q.pop();
            //continue;
        //}
        q.pop();
        
        for(auto u: adjr[cur]){
            if(disr[cur] + u.second < disr[u.first]){
                disr[u.first] = disr[cur] + u.second;
                q.push({disr[u.first], u.first});
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        ans = max(ans, dis[i] + disr[i]);
        //print(i, dis[i], disr[i]);
    }
    
    print(ans);
    
    return 0;
}