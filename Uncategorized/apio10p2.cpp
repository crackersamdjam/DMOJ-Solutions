#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e5+1;

int N, K, dia, ed, fp, dis[MM], par[MM], ans, len;
map<int, int> adj[MM];
bool rm[MM];

void dfs(int cur, int pre){
    if(dis[cur] > dia)
        dia = dis[cur], ed = cur;
    for(auto e: adj[cur])
        if(e.first ^ pre){
            dis[e.first] = dis[cur] + e.second;
            dfs(e.first, cur);
        }
}

bool prune(int cur, int pre){
    par[cur] = pre;
    if(cur == ed)
        rm[cur] = 1;
    for(auto e: adj[cur])
        if(e.first ^ pre)
            rm[cur] |= prune(e.first, cur);
    return rm[cur];
}

int go(int cur, int pre){
    int f = 0, s = 0;
    for(auto e: adj[cur]){
        if(e.first == pre)
            continue;
        int d = go(e.first, cur) + e.second;
        if(d > f)
            s = f, f = d;
        else if(d > s)
            s = d;
    }
    //printf("l %d %d\n", cur, f+s);
    len = max(len, f+s);
    return f;
}

int main(){
    
    scan(N, K);
    
    for(int i = 0,a,b; i < N-1; i++){
        scan(a, b);
        adj[a].insert({b, 1});
        adj[b].insert({a, 1});
        ans += 2;
    }
    
    dfs(1, -1);
    
    memset(dis, 0, sizeof dis);
    fp = ed;
    dia = 0;
    dfs(ed, -1);
    
    ans = ans - dia + 1;
    
    if(K == 1){
        print(ans);
        return 0;
    }
    
    prune(fp, 0);
    
    for(int i = 1; i <= N; i++){
        if(rm[i]){
            //printf("rm %d %d\n", i, par[i]);
            adj[i][par[i]] = -1;
            adj[par[i]][i] = -1;
        }
    }
    
    go(1, 0);
    
    print(ans-len+1);
    
    return 0;
}
/*
 * find longest path
 * go from one endpt, dfs to prune, store parents
 *
 */