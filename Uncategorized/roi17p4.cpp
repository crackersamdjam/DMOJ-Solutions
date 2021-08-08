#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define sq(x) (x)*(x)
#define sz(x) x.size()

#define ll long long
#define pii std::pair<int, int>
constexpr int MM = 1e6+1;

int n, m, ptr = -1, dis[MM], rdis[MM];
std::vector<pii> adj[MM], radj[MM];
std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
std::vector<int> ord, add[MM], qu[MM];
std::vector<std::vector<int>> q;
ll dp[MM];
bool on[MM];

inline double val(int j, int k){
    return ((double)(dp[k] - dp[j] + sq((ll)dis[k]) - sq((ll)dis[j])))/(2.0*(dis[k] - dis[j]));
}
//ll num(int j, int k){
//    return dp[k] - dp[j] + sq(dis[k]) - sq(dis[j]);
//}
//ll den(int j, int k){
//    assert(dis[k] > dis[j]);
//    return 2*(dis[k] - dis[j]);
//}

std::vector<int> k;
std::vector<std::vector<int>> a, b;

int main(){
    scan(n, m);
    k.resize(m);
    a.resize(m);
    b.resize(m);
    for(int l = 0; l < m; l++){
        scan(k[l]);
        a[l].resize(k[l]+1);
        b[l].resize(k[l]+1);
        scan(a[l][0]);
        for(int i = 1; i <= k[l]; i++){
            scan(b[l][i], a[l][i]);
            adj[a[l][i-1]].emplace_back(a[l][i], b[l][i]);
            radj[a[l][i]].emplace_back(a[l][i-1], b[l][i]);
        }
    }
    
    //rdis
    memset(rdis, 0x3f, sizeof rdis);
    rdis[n] = 0;
    pq.emplace(0, n);
    while(pq.size()){
        auto rm = pq.top(); pq.pop();
        int cur = rm.second, d = rm.first;
        if(d > rdis[cur]) continue;
        for(auto e: radj[cur]){
            int u = e.first, w = e.second;
            if(d+w < rdis[u]){
                rdis[u] = d+w;
                pq.emplace(rdis[u], u);
            }
        }
    }
    
    //dis
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    pq.emplace(0, 1);
    while(pq.size()){
        auto rm = pq.top(); pq.pop();
        int cur = rm.second, d = rm.first;
        if(d > dis[cur]) continue;
        
        if(dis[cur] + rdis[cur] == rdis[1]){
            ord.emplace_back(cur);
            on[cur] = 1;
        }
        
        for(auto e: adj[cur]){
            int u = e.first, w = e.second;
            if(d+w < dis[u]){
                dis[u] = d+w;
                pq.emplace(dis[u], u);
            }
        }
    }
    
    for(int i = 0; i < MM; i++){
        adj[i].clear();
        adj[i].shrink_to_fit();
        radj[i].clear();
        radj[i].shrink_to_fit();
    }
    ord.shrink_to_fit();
    
    for(int l = 0; l < m; l++){
        int last = 0;
        for(int i = 1; i <= k[l]; i++){
            if(on[a[l][i]] and on[a[l][i-1]] and dis[a[l][i]] - dis[a[l][i-1]] == b[l][i]){
                if(!last){
                    last = 1;
                    ptr++;
                }
                add[a[l][i-1]].emplace_back(ptr);
                qu[a[l][i]].emplace_back(ptr);
            }
            else{
                last = 0;
            }
        }
    }
    
    a.clear();
    a.shrink_to_fit();
    b.clear();
    b.shrink_to_fit();
    k.clear();
    k.shrink_to_fit();
    
    q.resize(ptr+1);
    
    for(int i: ord){
        
        for(int t: qu[i]){
            while(q[t].size() > 1 and dis[i] > val(q[t][sz(q[t])-2], q[t].back()))
                q[t].pop_back();
            
            ll v = dp[q[t].back()] + sq((ll)dis[i] - dis[q[t].back()]);
            if(v > dp[i])
                dp[i] = v;
        }
        
        for(int t: add[i]){
            while(q[t].size() > 1 and val(q[t][sz(q[t])-2], q[t].back()) <= val(q[t].back(), i))
                q[t].pop_back();
            
            q[t].push_back(i);
        }
    }
    
    print(dis[n], dp[n]);
    
    return 0;
}