#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename T> void printmn(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}
template<typename First, typename ... Ints>
void printm(First arg, Ints... rest) {printmn(arg);pc(32);printmn(rest...);pc(10);}

using namespace std;
const int MM = 1e5+1;

int N, M, dp[MM];
vector<int> adj[MM];

int go(int n){
    
    if(adj[n].empty())
        return 0;
    
    if(dp[n])
        return dp[n];
    
    int ret = 0;
    
    for(int u: adj[n]){
        ret = max(ret, go(u) + 1);
    }
    
    return dp[n] = ret;
}

int main(){
    
    scan(N, M);
    
    for(int i = 0,a,b; i < M; i++){
        scan(a, b);
        adj[a].push_back(b);
    }
    
    int ans = 0;
    
    for(int i = 1; i <= N; i++){
        ans = max(ans, go(i));
    }
    
    print(ans);
    
    return 0;
}