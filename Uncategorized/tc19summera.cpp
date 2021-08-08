//cave escape
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 4e5+1;

int N, dp[MM];
vector<int> adj[MM];

int dfs(int cur, int pre){
    vector<int> ch;
    for(int u: adj[cur]){
        if(u ^ pre)
            ch.push_back(dfs(u, cur));
    }
    sort(ch.begin(), ch.end(), greater<>());
    
    dp[cur] = 1;
    
    for(int i = 0; i < ch.size(); i++)
        dp[cur] = max(dp[cur], ch[i] + i);
    //how many need to be keep on during push
    
    return dp[cur];
}

int main(){
    
    scan(N);
    
    for(int i = 1,j; i < N; i++){
        scan(j);
        adj[i].push_back(j);
        adj[j].push_back(i);
    }
    
    print(dfs(0, -1));
    
}