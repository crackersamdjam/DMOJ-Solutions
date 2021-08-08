#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 4e5+2;

int N, dis[MM], dia;
ll cnt[MM], c;
vector<int> adj[MM];

void dfs(int cur, int pre){
    cnt[cur] = 1;
    
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        
        dfs(u, cur);
        if(dis[u] + dis[cur] + 1 > dia){
            dia = dis[u] + dis[cur] + 1;
            c = cnt[u]*cnt[cur];
        }
        else if(dis[u] + dis[cur] + 1 == dia)
            c += cnt[u]*cnt[cur];
        
        if(dis[u]+1 > dis[cur]){
            dis[cur] = dis[u]+1;
            cnt[cur] = cnt[u];
        }
        else if(dis[u]+1 == dis[cur])
            cnt[cur] += cnt[u];
    }
}

int main(){
    
    scan(N);
    
    for(int i = 0,a,b; i < N-1; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, -1);
    
    printf("%d %lld\n", dia+1, c);
    
    return 0;
}
/*
 * at each point, in its subtree, dfs paths
 *  get best dia
 *  count for each node, meaning it's subtree
 */