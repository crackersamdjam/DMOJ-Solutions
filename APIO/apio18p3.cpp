#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int MM = 2e5+5;

int n, m, dfn[MM], low[MM], t, tt;
vector<int> adj[MM], adj2[MM], in[MM];
stack<pii> st;
set<int> art;
int compsz[MM];

void process(int u, int v){
    if(st.empty()) return;
    tt++;
    while(st.size()){
        pii e = st.top(); st.pop();
        in[tt].push_back(e.first);
        in[tt].push_back(e.second);
        compsz[tt]++;
        if(e == pii(u, v))
            break;
    }
}

void dfs(int cur, int pre){
    dfn[cur] = low[cur] = ++t;
    int ch = 0;
    for(int u: adj[cur]){
        if(u == pre) continue;
        if(!dfn[u]){
            ch++;
            st.emplace(cur, u);
            dfs(u, cur);
            
            low[cur] = min(low[cur], low[u]);
            
            if((pre == -1 && ch > 1) or (pre != -1 && low[u] >= dfn[cur])){
                art.insert(cur);
                process(cur, u);
            }
        }
        else
            low[cur] = min(low[cur], dfn[u]);
    }
}

ll ans;
int sz[MM];

int getsz(int cur, int pre){
    dfn[cur] = 1;
    sz[cur] = cur <= n;
    for(int u: adj2[cur])
        if(u != pre)
            sz[cur] += getsz(u, cur);
    return sz[cur];
}

void dfs2(int cur, int pre, int tot){
    for(int u: adj2[cur]){
        if(u != pre)
            dfs2(u, cur, tot);
    }
    if(cur <= n){
        if(pre){
            assert(pre > n);
            ans -= (ll)sz[cur]*(sz[cur]-1)*(compsz[pre]-1);
            // in parcyc but not cur
            // ends in subtree, mid in pre's cyc
        }

        for(int u: adj2[cur]){
            assert(u > n);
            if(u != pre){
                ans -= (ll)(tot-sz[u])*(tot-sz[u]-1)*(compsz[u]-1); // ends above, mid in u's cyc
            }
        }
    }
}

int main(){
    scan(n, m);
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for(int i = 1; i <= n; i++){
        if(!dfn[i]){
            dfs(i, -1);
            process(-1, -1);
        }
    }
    for(int i = 1; i <= tt; i++){
        sort(all(in[i]));
        in[i].erase(unique(all(in[i])), in[i].end());
        compsz[i+n] = (int)in[i].size();
        for(int u: in[i]){
            adj2[n+i].push_back(u);
            adj2[u].push_back(n+i);
        }
    }
    tt += n;

    // cout<<"graph"<<endl;for(int i = 1; i <= tt; i++)for(int u: adj2[i])print(i, u);cout<<"done"<<endl;
    // cout<<"art ";for(int i: art)cout<<i<<' ';cout<<endl;

    memset(dfn, 0, sizeof dfn);
    for(int i = 1; i <= n; i++){
        if(!dfn[i]){
            int tot = getsz(i, -1);
            // pr("i", i, tot);
            ans += (ll)tot*(tot-1)*(tot-2);
            dfs2(i, 0, tot);
        }
    }
    print(ans);
}