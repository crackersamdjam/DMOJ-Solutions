#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e5+1;
int N, M, K;

int dep[MM], lens[MM], t;
vector<int> adj[MM];

void hld(int cur){
    dep[cur] = 1;
    if(adj[cur].empty())
        return;
    
    bool done = 0;
    for(int u: adj[cur]){
        hld(u);
        dep[cur] = max(dep[cur], dep[u]+1);
    }
    for(int u: adj[cur]){
        if(!done && dep[u]+1 == dep[cur])
            done = 1;
        else
            lens[t++] = dep[u];
    }
}

int main(){
    
    scan(N, M, K);
    
    for(int i = 2,a; i <= N; i++){
        scan(a);
        adj[a].push_back(i);
    }
    
    hld(1);
    lens[t++] = dep[1];
    
    sort(lens, lens+t, greater<>());
    
    for(int i = 0, j = 0; i < M; i++, j++){
        if(j >= K)
            j -= K;
        print(lens[j]);
        
        pc(i < M-1? 32 : 10);
    }
    
    return 0;
}