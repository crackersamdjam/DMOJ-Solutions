#include <bits/stdc++.h>
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 2e5+2;

int N, in[MM], adj[MM], cnt, ans = 1e8;
bool vis[MM];
queue<int> q;

void dfs(int cur){
    vis[cur] = 1;
    cnt++;
    int u = adj[cur];
    if(!vis[u])
        dfs(u);
}
int main(){
    
    scan(N);
    for(int i = 1; i <= N; i++){
        scan(adj[i]);
        in[adj[i]]++;
    }
    for(int i = 1; i <= N; i++){
        if(!in[i])
            q.push(i);
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        vis[cur] = 1;
        
        int u = adj[cur];
        if(!--in[u])
            q.push(u);
    }
    
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            cnt = 0;
            dfs(i);
            //find cycle len
            ans = min(ans, cnt);
        }
    }
    print(ans);
    return 0;
}