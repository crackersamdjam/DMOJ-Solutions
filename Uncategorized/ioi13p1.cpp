#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
const int MM = 100002;
vector<pii> adj[MM];
int len, rad, dia, r1, r2, r3, ed, dis[MM], par[MM], cnt; //number of disjoint sets
bool vis[MM];

void dfs(int cur, int pre){
    if(dis[cur] > len){
        len = dis[cur];
        ed = cur;
    }
    for(auto &e: adj[cur]){
        if(e.f != pre){
            vis[e.f] = 1;
            dis[e.f] = dis[cur] + e.s;
            par[e.f] = cur;
            dfs(e.f, cur);
        }
    }
}
inline void go(int st){
    cnt++;
    vis[st] = 1;
    if(adj[st].empty())
        return;
    
    len = 0, rad = INT_MAX, ed = -1;
    par[st] = -1;
    dis[st] = 0;
    dfs(st, -1);
    //find endpoint
    
    /*
    dis[ed] = 0;
    par[ed] = -1;
    dfs(ed, -1);
    //find endpoint
    */
    
    dis[ed] = 0;
    par[ed] = -1;
    len = 0;
    dfs(ed, -1);
    
    
    while(ed != -1){
        if(max(dis[ed], len - dis[ed]) < rad)
            rad = max(dis[ed], len - dis[ed]);
        else break;
        ed = par[ed];
    }
    
    dia = max(dia, len);
    
    if(rad > r1){
        r3 = r2;
        r2 = r1;
        r1 = rad;
    }else if(rad > r2){
        r3 = r2;
        r2 = rad;
    }else if(rad > r3){
        r3 = rad;
    }
}
int travelTime(int N, int M, int L, int A[], int B[], int T[]){
    for(int i = 0; i < M; i++){
        adj[A[i]].push_back({B[i], T[i]});
        adj[B[i]].push_back({A[i], T[i]});
    }
    for(int i = 0; i < N; i++){
        if(!vis[i])
            go(i);
    }
    int ans = dia;
    if(cnt >= 2)
        ans = max(ans, r1 + r2 + L);
    if(cnt >= 3)
        ans = max(ans, r2 + r3 + 2*L);
    return ans;
}


#ifndef ONLINE_JUDGE

int main(){
    int za[] = {0, 8, 2, 5, 5, 1, 1, 10}, zb[] =  {8, 2, 7, 11, 1, 3, 9, 6}, zc[] = {4, 2, 4, 3, 7, 1, 5, 3};
    printf("%d\n", travelTime(10, 8, 2, za, zb, zc));
    return 0;
}

#endif