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
const int MM = 2e5+5;

int n, q, v[MM], psa[2][MM], par[MM], dep[MM], heavy[MM], head[MM];
vector<int> adj[MM];

int dfs(int cur, int pre){
	int size = 1, maxsz = 0;
	for(int u: adj[cur]){
		if(u == pre)
			continue;
		par[u] = cur, dep[u] = dep[cur]+1;
		int szu = dfs(u, cur);
		size += szu;
		if(szu > maxsz)
			maxsz = szu, heavy[cur] = u;
	}
	return size;
}

void hld(int cur, int hd){
	head[cur] = hd;
	if(heavy[cur])
		hld(heavy[cur], hd);
	for(int u: adj[cur]){
		if(u != par[cur] && u != heavy[cur])
			hld(u, u);
	}
}

void prop(int cur, int pre){
	for(int u: adj[cur]){
		if(u == pre)
			continue;
		prop(u, cur);
		psa[0][cur] ^= psa[0][u];
		psa[1][cur] ^= psa[1][u];
	}
}

int getlca(int a, int b){
	while(head[a] != head[b]){
		if(dep[head[a]] < dep[head[b]])
			b = par[head[b]];
		else
			a = par[head[a]];
	}
	return dep[a] < dep[b] ? a : b;
}

int main(){
	scan(n, q);
	for(int i = 1; i <= n; i++)
		scan(v[i]);
	for(int i = 0,a,b; i < n-1; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs(1, 1);
	hld(1, 1);
	while(q--){
		int a, b, c;
		scan(a, b, c);
		int lca = getlca(a, b);
		psa[dep[a]&1][a] ^= c;
		// psa[dep[a]&1][lca] ^= c;
		psa[dep[a]&1][b] ^= c;
		// psa[dep[a]&1][lca] ^= c;
		if((dep[a]-dep[lca])%2 == 0)
			v[lca] ^= c;
		// print(a, b, lca, dep[a]&1, dep[b]&1);
	}
	prop(1, 1);
	for(int i = 1; i <= n; i++)
		printf("%d ", v[i]^psa[dep[i]&1][i]);

}