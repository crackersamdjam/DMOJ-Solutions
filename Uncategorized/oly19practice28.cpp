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
const int MM = 1001;

int n, m, l, dis[MM];
vector<pii> adj[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;

bool test(int k){
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    q.push({0, 1});
    
    while(!q.empty()){
        int cur = q.top().second;
        //if(dis[cur] < q.top().first){
        //  q.pop();
        //continue;
        //}
        q.pop();
        
        for(auto u: adj[cur]){
            int v = (u.second > k);
            if(dis[cur] + v < dis[u.first]){
                dis[u.first] = dis[cur] + v;
                q.push({dis[u.first], u.first});
            }
        }
    }
    
    //print(k, dis[n], l);
    
    return dis[n] <= l;
}

int main(){
    
    scan(n, m, l);
    
    for(int i = 0,a,b,c; i < m; i++){
        scan(a, b, c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    int l = 0, m, r = 1e9;
    while(l <= r){
        m = (l+r)/2;
        if(test(m))
            r = m-1;
        else
            l = m+1;
    }
    
    if(l > 1e9)
        return !printf("-1");
    
    print(l);
    
    return 0;
}