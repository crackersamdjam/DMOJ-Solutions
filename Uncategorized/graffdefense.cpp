#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 1e6+5;

int n, m, st[MM], ed[MM];
pair<int, int> adj[MM*2];
int dfn[MM], low[MM], t, path[MM], ptr, sz[MM];

void dfs(int cur, int pre){
	
	path[++ptr] = cur;
	dfn[cur] = low[cur] = ++t;
	
	for(int i = st[cur]; i < ed[cur]; i++){
		int u = adj[i].second;
		if(u == pre)
			continue;
		if(!dfn[u]){
			dfs(u, cur);
			low[cur] = min(low[cur], low[u]);
		}
		else
			low[cur] = min(low[cur], dfn[u]);
	}
	
	if(dfn[cur] == low[cur]){
		int u = -1;
		while(u != cur){
			u = path[ptr--];
			sz[cur]++;
		}
	}
}

int main(){
	scan(n, m);
	for(int i = 0,a,b; i < m; i++){
		scan(a, b);
		adj[i] = {a, b};
		adj[m+i] = {b, a};
	}
	m *= 2;
	sort(adj, adj+m);
	int nn = 1;
    for(int i = 0; i < m; i++){
        if(adj[i].first != nn){
            ed[nn] = i;
            nn = adj[i].first;
            st[nn] = i;
        }
    }
    ed[nn] = m;

	dfs(1, 0);
	ll sum = 0;
	for(int i = 1; i <= n; i++){
		sum += (ll)sz[i]*(sz[i]-1)/2;
	}
	printf("%.5Lf\n", 1-(long double)sum/((ll)n*(n-1)/2));
}