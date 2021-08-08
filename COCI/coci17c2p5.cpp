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
const int MM = 3e5+5, LOG = 19;
const ll mod = 1e9+7;

int n, m;
vector<int> adj[MM];
int sp[LOG][MM], dep[MM], psa[MM], par[MM*2];

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

void dfs(int cur, int pre){
	dep[cur] = dep[pre]+1;
	sp[0][cur] = pre;
	for(int u: adj[cur]){
		if(u != pre)
			dfs(u, cur);
	}
}

int go(int cur, int pre){
	for(int u: adj[cur]){
		if(u != pre)
			psa[cur] += go(u, cur);
	}
	if(psa[cur]){
		//merge this and parent to be same
		par[find(cur)] = find(pre);
		par[find(cur+n)] = find(pre+n);
	}
	return psa[cur];
}

int getlca(int a, int b){
	if(dep[a] < dep[b])
		swap(a, b);
	// a is deeper than b
	for(int i = LOG-1; i >= 0; i--){
		if(dep[a]-(1<<i) >= dep[b])
			a = sp[i][a];
	}
	if(a == b)
		return a;

	for(int i = LOG-1; i >= 0; i--){
		if(sp[i][a] != sp[i][b])
			a = sp[i][a], b = sp[i][b];
	}
	return sp[0][a];
}

int before(int a, int b){
	for(int i = LOG-1; i >= 0; i--){
		if(dep[a]-(1<<i) > dep[b])
			a = sp[i][a];
	}
	return a;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 0,a,b; i < n-1; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	for(int i = 1; i <= 2*n; i++)
		par[i] = i;
	
	memset(sp, -1, sizeof sp);
	dfs(1, 0);
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= n; j++){
			int u = sp[i-1][j];
			if(~u) sp[i][j] = sp[i-1][u];
		}
	}

	ll ans = 1;
	while(m--){
		int a, b;
		cin>>a>>b;
		int c = getlca(a, b);
		psa[a]++, psa[b]++;
		a = before(a, c), b = before(b, c);
		psa[a]--, psa[b]--;
		if(a != c and b != c){
			//merge the two ch to be different
			par[find(a)] = find(b+n);
			par[find(a+n)] = find(b);
		}
	}

	go(1, 0);

	for(int i = 2; i <= n; i++){
		if(find(i) == find(i+n))
			ans = 0;
		if(find(i) == i)
			ans = ans*2%mod;
	}

	cout<<ans<<'\n';
}
/*
at lca, colour of edge to each child...
each edge going through the lca gets shorted to the two children
and mark a--c, b--c to be same color (psa?)
*/