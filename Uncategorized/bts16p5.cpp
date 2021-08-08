#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
typedef pair<int, int> pii;
const int MM = 1e5+1;

int N, C, K, a[MM], w[MM], ans;
vector<pii> adj[MM];

void dfs(int cur, int pre){
    
    for(auto e: adj[cur]){
        if(e.first == pre)
            continue;
        
        w[e.first] = e.second;
        dfs(e.first, cur);
        
        w[cur] += w[e.first];
        a[cur] += a[e.first];
    }
}

int main(){
    
    scan(N, C, K);
    
    for(int i = 1; i <= N; i++)
        scan(a[i]);
    
    for(int i = 0,a,b,c; i < N-1; i++){
        scan(a, b, c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    dfs(1, -1);
    
    for(int i = 2; i <= N; i++){
        if(a[i] >= C && w[i] <= K)
            ans++;
    }
    
    print(ans);
    
    return 0;
}