#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int MM = 2e5;

int N, K, sz[MM], tot, len[MM], ans = INT_MAX, t;
ll dis[MM];
bool vis[MM];
vector<pii> adj[MM];
pii vec[MM];
map<int, int> cnt;

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
        len[e.first] = len[cur] + 1;
        dfs(e.first, cur);
    }
    
    if(dis[cur] <= K)
        vec[t++] = {dis[cur], len[cur]};
}

void go(int root){
    
    getsz(root, -1);
    tot = sz[root];
    
    if(sz[root] == 1)
        return;
    
    int cent = findcent(root, -1);
    
    dis[cent] = 0;
    len[cent] = 0;
    cnt.clear();
    
    vis[cent] = 1;
    //block off
    
    for(auto &u: adj[cent]){
        if(!vis[u.first]){
            t = 0;
            dis[u.first] = u.second;
            len[u.first] = 1;
            dfs(u.first, cent);
            
            for(int k = 0; k < t; k++){
                auto i = vec[k];
                if(!i.first)
                    continue;
                if(i.first == K)
                    ans = min(ans, i.second);
                else if(i.first < K and cnt[K-i.first])
                    ans = min(ans, i.second + cnt[K-i.first]);
            }
            
            for(int k = 0; k < t; k++){
                auto i = vec[k];
                if(!cnt[i.first])
                    cnt[i.first] = i.second;
                else
                    cnt[i.first] = min(cnt[i.first], i.second);
            }
        }
    }
    
    for(auto u: adj[cent]){
        if(!vis[u.first])
            go(u.first);
    }
}

int best_path(int n, int k, int h[][2], int l[]){
    
    N = n, K = k;
    
    for(int i = 0; i < N-1; i++){
        adj[h[i][0]].push_back({h[i][1], l[i]});
        adj[h[i][1]].push_back({h[i][0], l[i]});
    }
    
    for(int i = 0; i < N; i++){
        if(adj[i].size() == 1){
            go(i);
            break;
        }
    }
    
    return (ans == INT_MAX? -1: ans);
}


#ifndef ONLINE_JUDGE

int in, ik, ih[MM][2], il[MM];

int main(){
    
    scan(in, ik);
    for(int i = 0; i < in-1; i++)
        scan(ih[i][0], ih[i][1], il[i]);
    
    print(best_path(in, ik, ih, il));
}

#endif

/*
 numbers on same path being counted twice
 instead, split into separate, then merge together
 
 for each subtree
     vector for distances in each subtree
     find best ans with existing map
     merge into map
 
 clear map
 
 */