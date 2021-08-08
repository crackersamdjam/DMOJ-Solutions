#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using pii = pair<int, int>;
const int MM = 1e5+2;

int n, m, pre[MM], d[MM], dis[MM];
vector<pii> adj[MM];
vector<int> ans;
queue<int> q[10], nx[10];

int main(){
    
    memset(pre, -1, sizeof pre);
    
    scan(n, m);
    
    for(int i = 0,a,b,c; i < m; i++){
        scan(a, b, c);
        adj[a].emplace_back(c, b);
        adj[b].emplace_back(c, a);
    }
    
    for(int i = 0; i < n; i++)
        sort(adj[i].begin(), adj[i].end());
    
    pre[n-1] = -2;
    q[0].push(n-1);
    q[1].push(n-1);
    
    while(!q[0].empty()){
        int cur = q[0].front(); q[0].pop();
        for(auto u: adj[cur]){
            if(!u.first and pre[u.second] == -1){
                pre[u.second] = cur;
                d[u.second] = u.first;
                q[0].push(u.second);
                q[1].push(u.second);
            }
        }
    }
    while(1){
        for(int i = 0; i < 10; i++){
            while(!q[i].empty()){
                int cur = q[i].front(); q[i].pop();
                for(auto u: adj[cur]){
                    if(pre[u.second] == -1 or (u.first < d[u.second] and dis[u.second] == dis[cur]+1 and d[pre[u.second]] == d[cur])){
                        dis[u.second] = dis[cur]+1;
                        pre[u.second] = cur;
                        d[u.second] = u.first;
                        nx[i].push(u.second);
                    }
                }
            }
        }
        
        int cnt = 0;
        for(int i = 0; i < 10; i++){
            cnt += nx[i].size();
            while(nx[i].size()){
                q[i].push(nx[i].front());
                nx[i].pop();
            }
        }
        if(!cnt)
            break;
    }
    
    int cur = 0;
    while(cur != -2){
        ans.push_back(cur);
        cur = pre[cur];
    }
    
    bool one = 0;
    for(int i = ans.size()-2; i >= 0; i--){
        if(!one and !d[ans[i]])
            continue;
        one = 1;
        pc(d[ans[i]]+'0');
    }
    if(!one)
        pc('0');
    
    pc(10);
    print(ans.size());
    for(int i: ans)
        printn(i), pc(32);
    
    return 0;
}