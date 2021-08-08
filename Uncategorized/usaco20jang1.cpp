#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

const int MM = 1001;

int n, m, c, v[MM], dis[MM][MM];
std::vector<int> adj[MM];
/*
struct st{
    int u, d, c;
    bool operator<(const st &o) const{
        return c < o.c;
    }
};
 */
//std::priority_queue<st> q;
std::queue<std::pair<int, std::pair<int, int>>> q;
bool inq[MM];

int main(){
    
    //freopen("time.in", "r", stdin); freopen("time.out", "w", stdout);
    
    scan(n, m, c);
    for(int i = 1; i <= n; i++)
        scan(v[i]);
    
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        adj[a].emplace_back(b);
    }
    
    q.push({1, {0, 0}});
    dis[1][0] = 0;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur.second.second > dis[cur.first][cur.second.first])
            continue;
        for(int u: adj[cur.first]){
            int nv = dis[cur.first][cur.second.first]+v[u]-c*(2*cur.second.first+1);
            if(nv > dis[u][cur.second.first+1]){
                q.push({u, {cur.second.first+1, dis[u][cur.second.first+1] = nv}});
            }
        }
    }
    
    print(*std::max_element(dis[1], dis[1]+MM));
    
    return 0;
}