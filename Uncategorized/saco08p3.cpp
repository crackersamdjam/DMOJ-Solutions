#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using pii = pair<pair<int, int>, int>;
using ll = long long;
const int MM = 705;
const ll mod = 1e6;

void addmod(ll &a, ll b){
    a += b;
    if(a >= mod)
        a -= mod;
}

int n, adj[MM][MM], dis[2][MM], c[MM], m;
ll cnt[2][MM];

int main(){
    scan(n);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scan(adj[i][j]);
        
    scan(m);
    for(int i = 0,a; i < m; i++){
        scan(a);
        c[a] = 1;
    }
    
    
    memset(dis, 0x3f, sizeof dis);
    dis[c[1]][1] = 0;
    cnt[c[1]][1] = 1;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({{0, c[1]}, 1});
    while(q.size()){
        auto rm = q.top(); q.pop();
        int cur = rm.second, t = rm.first.second, nt = t;
        if(c[cur])
            nt = 1;
        for(int u = 1; u <= n; u++){
            if(u == cur)
                continue;
            int nd = dis[t][cur]+adj[cur][u];
            if(nd < dis[nt][u]){
                dis[nt][u] = nd;
                cnt[nt][u] = cnt[t][cur];
                q.push({{nd, nt}, u});
            }
            else if(nd == dis[nt][u]){
                addmod(cnt[nt][u], cnt[t][cur]);
            }
        }
    }
    
    print(dis[1][n], cnt[1][n]);
    
    return 0;
}