#ifdef ONLINE_JUDGE
#define __algo_gcd(x, y) __gcd(x, y)
#endif
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 2e5+2;

int N, K, sz[MM], tot, t;
ll dis[MM], ans[MM], lazy[MM], allp;
bool vis[MM];
vector<pii> adj[MM];
map<ll, ll> cnt;
pair<ll, int> path[MM];
//distance, node

int getsz(int cur, int pre){
    sz[cur] = 1;
    for(auto &e: adj[cur]){
        if(e.first != pre && !vis[e.first])
            sz[cur] += getsz(e.first, cur);
    }
    return sz[cur];
}

int findcent(int cur, int pre){
    for(auto &e: adj[cur]){
        if(!vis[e.first] && e.first != pre && sz[e.first]*2 > tot)
            return findcent(e.first, cur);
    }
    return cur;
}

void dfs(int cur, int pre){
    
    for(auto &e: adj[cur]){
        if(e.first == pre || vis[e.first])
            continue;
        
        dis[e.first] = dis[cur] + e.second;
        dfs(e.first, cur);
    }
    
    path[t++] = {dis[cur], cur};
}

ll prop(int cur, int pre){
    
    for(auto &e: adj[cur]){
        
        if(e.first == pre || vis[e.first])
            continue;
        
        lazy[cur] += prop(e.first, cur);
    }
    
    ll temp = lazy[cur];
    lazy[cur] = 0;
    ans[cur] += temp;
    //add to answer, propagate up
    
    return temp;
}

void go(int root){
    
    getsz(root, -1);
    tot = sz[root];
    if(tot == 1)
        return;
    
    int cent = findcent(root, -1);
    
    cnt.clear();
    cnt[0] = 1;
    //from cent
    
    vis[cent] = 1;
    //block off
    
    ll init = ans[cent];
    
    for(auto &u: adj[cent]){
        if(!vis[u.first]){
            t = 0;
            
            dis[u.first] = u.second;
            dfs(u.first, cent);
            
            for(int k = 0; k < t; k++){
                auto &i = path[k];
                if(i.first > K)
                    continue;
                
                if(i.first == K)
                    ans[cent]++;
                //count again
    
                lazy[i.second] += cnt[K-i.first];
                allp += cnt[K-i.first];
            }
            
            //merge into map
            for(int k = 0; k < t; k++){
                auto &i = path[k];
                if(i.first <= K)
                    cnt[i.first]++;
            }
            
            ans[cent] += prop(u.first, cent);
            //here, propagate centroid separately from subtree
        }
    }
    
    cnt.clear();
    
    //reverse order and do again
    reverse(adj[cent].begin(), adj[cent].end());
    for(auto &u: adj[cent]){
        if(!vis[u.first]){
            t = 0;
            
            dis[u.first] = u.second;
            dfs(u.first, cent);
            
            //check
            for(int k = 0; k < t; k++){
                auto &i = path[k];
                if(i.first > K)
                    continue;
                
                lazy[i.second] += cnt[K-i.first];
            }
            
            //merge into map
            for(int k = 0; k < t; k++){
                auto &i = path[k];
                if(i.first <= K)
                    cnt[i.first]++;
            }
            
            ans[cent] += prop(u.first, cent);
        }
    }
    
    ans[cent] = init + (ans[cent]-init)/2;
    //except for paths that end at cent, need to be accounted for
    
    for(auto &u: adj[cent]){
        if(!vis[u.first])
            go(u.first);
    }
}

int main(){
    
    scan(N, K);
    
    for(int i = 0,a,b,c; i < N-1; i++){
        scan(a, b, c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    for(int i = 1; i <= N; i++){
        if(adj[i].size() == 1){
            go(i);
            break;
        }
    }
    
    if(!allp){
        for(int i = 1; i <= N; i++)
            puts("0 / 1");
        return 0;
    }
    
    for(int i = 1; i <= N; i++){
        ll gcd = __algo_gcd(ans[i], allp);
        printf("%lld / %lld\n", ans[i]/gcd, allp/gcd);
    }
    
}

/*
 numbers on same path being counted twice
 instead, split into separate, then merge together
 
 for each subtree
     vector for distances in each subtree
     find best ans with existing map
     merge into map
 
 clear map
 
 
 process children in normal and reverse order (to count every subtree path)
 to update, add to most bottom node
 then, dfs from root, add sum of children vals, the return val
 (to propagate up)
 
 */