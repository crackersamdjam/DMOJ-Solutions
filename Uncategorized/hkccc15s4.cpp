#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+5;

int n, ins[MM], path[MM], dfn[MM], low[MM], t, ptr, sz[MM], id[MM];
vector<int> adj[MM], v[MM];

void dfs(int cur){
	ins[cur] = 1;
	path[++ptr] = cur;
	dfn[cur] = low[cur] = ++t;
	
	for(int u: adj[cur]){
		if(!dfn[u]){
			dfs(u);
			low[cur] = min(low[cur], low[u]);
		}
		else if(ins[u])
			low[cur] = min(low[cur], dfn[u]);
	}
	
	if(dfn[cur] == low[cur]){
		int u = -1;
		while(u != cur){
			u = path[ptr--];
			ins[u] = 0;
			id[u] = cur;
			sz[cur]++;
			v[cur].emplace_back(u);
		}
	}
}
int dp[MM];
int dfs2(int cur){
	int &ret = dp[cur];
	if(~ret)
		return ret;
	ret = 0;
	for(int u: adj[cur]){
		if(sz[id[u]] == 1){
			ret = max(ret, dfs2(u)+1);
		}
	}
	return ret;
}

int last[MM], ans;

int main(){
	memset(dp, -1, sizeof dp);
	scan(n);
	for(int i = 1,u; i <= n; i++){
		scan(u);
		adj[u].emplace_back(i);
	}
	for(int i = 1; i <= n; i++){
		if(!dfn[i])
			dfs(i);
	}
	for(int i = 1; i <= n; i++){
		if(!v[i].size())
			continue;
		int mx = 0;
		for(int j: v[i])
			mx = max(mx, dfs2(j));
		ans = max(ans, mx*2 + (sz[i]-1)*2);
	}
	print(ans);
}