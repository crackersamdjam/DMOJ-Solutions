#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 3e5+2;
const ll mod = 1e9+7;

bool vis[MM], no, odd;
int n, m, k, pt[MM];
ll minv[2][MM], maxv[2][MM], val[MM], ans = 1;
vector<pair<int, ll>> adj[MM];

void dfs(int cur, int id){
    for(auto e: adj[cur]){
        int u = e.first; ll w = e.second;
        if(!vis[u]){
            vis[u] = 1;
            pt[u] = pt[cur]^1;
            val[u] = w-val[cur];
            minv[pt[u]][id] = min(minv[pt[u]][id], val[u]);
            maxv[pt[u]][id] = max(maxv[pt[u]][id], val[u]);
            dfs(u, id);
        }
        else{
            if(pt[u] == pt[cur])
                odd = 1;
        }
    }
}

bool used, vis2[MM], vis3[MM];
int st;
void dfs2(int cur){
    if(used)
        return;
    for(auto e: adj[cur]){
        int u = e.first; ll w = e.second;
        if(!vis2[u]){
            vis2[u] = 1;
            dfs2(u);
        }
        else{
            if(!used && w != val[cur] + val[u]){
                used = 1;
                ll h = w-val[cur]-val[u];
                val[cur] += h/2;
                val[u] += h/2;
                st = cur;
                return;
            }
        }
    }
}
void dfs3(int cur){
    if(val[cur] <= 0 or val[cur] > k)
        no = 1;
    for(auto e: adj[cur]){
        int u = e.first; ll w = e.second;
        if(!vis3[u]){
            vis3[u] = 1;
            val[u] = w-val[cur];
            dfs3(u);
        }
        else{
            if(w != val[cur] + val[u]){
                no = 1;
            }
        }
    }
}

int main(){
    scan(n, m, k);
    for(int i = 0,a,b,c; i < m; i++){
        scan(a, b, c);
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            maxv[1][i] = -1e10;
            minv[1][i] = 1e10;
            //opp. parity
            
            vis[i] = 1;
            odd = 0;
            used = 0;
            st = 0;
            dfs(i, i);
            
            if(odd){
                vis2[i] = 1;
                dfs2(i);
                if(st){
                    //if need to rebalance (st value was set)
                    vis3[st] = 1;
                    dfs3(st);
                }
                //printf("no %d\n", no);
            }
            else{
                ll add = minv[0][i]-1;
                maxv[0][i] -= add;
                minv[0][i] -= add;
                maxv[1][i] += add;
                minv[1][i] += add;
                // now minv[0][i] = 1
                
                //print(maxv[0][i], minv[0][i], maxv[1][i], minv[1][i]);
                
                ll l = max(0LL, maxv[1][i] - k), r = min(k - maxv[0][i], minv[1][i]-1);
                //l, r bound to how much [0]s add and [1]s lose
                if(l > r)
                    no = 1;
                
                ll dif = (r-l+1)%mod;
                //print(k, l, r, dif);
                ans = (ans*dif)%mod;
            }
        }
    }
    
    print(no ? 0 : ans);
    
    return 0;
}
/*
 * each comp
 * if odd cycle, at most 1 sol
 * if none odd, do range by odd/even parity min/max values
 *
 */