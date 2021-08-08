#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef pair<int, int> pii;
const int MM = 5001;

int N, S, dis[MM], par[MM];
vector<int> adj[MM];
bool vis[MM];
pii far[MM];

void add(int cur, int pre, int d){
    vis[cur] = 1;
    if(!d) return;
    
    for(int u: adj[cur]){
        if(u ^ pre)
            add(u, cur, d-1);
    }
}

bool test(int d){
    
    int cnt = 0;
    
    memset(vis, 0, sizeof vis);
    
    for(int i = N; i; i--){
        
        int n = far[i].second;
        
        if(!vis[n]){
            if(++cnt > S)
                return 0;
    
            for(int t = 0; t < d && par[n]; t++)
                n = par[n];
            
            add(n, 0, d);
        }
    }
    
    return 1;
}

void dfs(int cur, int pre){
    
    par[cur] = pre;
    dis[cur] = dis[pre]+1;
    
    for(int u: adj[cur]){
        if(u ^ pre)
            dfs(u, cur);
    }
}

int main(){
    
    scan(N, S);
    
    for(int i = 0,a,b; i < N-1; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, 0);
    
    for(int i = 1; i <= N; i++)
        far[i] = {dis[i], i};
    
    sort(far+1, far+1+N);
    
    int l = 0, m, r = N;
    while(l <= r){
        m = (l+r)>>1;
        if(!test(m))
            l = m+1;
        else
            r = m-1;
    }
    
    print(l);
    
    return 0;
}