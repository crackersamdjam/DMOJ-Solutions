#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 50001;

int n, m, ans[MM];
vector<pair<int, int>> adj[MM];
multiset<pair<int, int>> st[MM];

void dfs(int cur, int pre, int id){
    for(auto e: adj[cur]){
        int u = e.first;
        if(u == pre)
            continue;
        dfs(u, cur, e.second);
        if(st[u].size() > st[cur].size())
            swap(st[u], st[cur]);
        st[cur].insert(st[u].begin(), st[u].end());
    }
    while(st[cur].size() and st[cur].count(*st[cur].begin()) == 2){
        //printf("rm "); print(st[cur].begin()->first, st[cur].begin()->second);
        st[cur].erase(*st[cur].begin());
    }
    ans[id] = st[cur].size() ? st[cur].begin()->first : -1;
}

int main(){
    
    scan(n, m);
    
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].emplace_back(b, i);
        adj[b].emplace_back(a, i);
    }
    
    for(int i = 0,a,b,c; i < m; i++){
        scan(a, b, c);
        st[a].insert({c, i});
        st[b].insert({c, i});
        
    }
    
    dfs(1, 0, n);
    
    for(int i = 0; i < n-1; i++)
        print(ans[i]);
    
    return 0;
}