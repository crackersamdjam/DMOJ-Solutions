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
typedef long long ll;
const int MM = 1e5+1, mod = 1e9+7;

int N;
ll dp[2][MM];
vector<int> adj[MM];

//if this one was coloured
ll go(int cur, bool last, int pre){
    
    if(dp[last][cur] != -1)
        return dp[last][cur];
    
    ll ret = 1, two = 1;
    
    for(int u: adj[cur]){
        
        if(u == pre)
            continue;
        
        if(!last){
            ret *= go(u, 1, cur); //colour next one
            two *= go(u, 0, cur);
            two %= mod;
        }
        else
            ret *= go(u, 0, cur);
        
        ret %= mod;
    }
    if(!last)
        ret = (ret + two) % mod;
    
    return dp[last][cur] = ret;
}

int main(){
    
    memset(dp, -1, sizeof dp);
    
    scan(N);
    
    if(N == 1)
        return 0*puts("2");
    
    for(int i = 0,a,b; i < N-1; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    print(go(1, 0, -1) % mod);
    
    return 0;
}