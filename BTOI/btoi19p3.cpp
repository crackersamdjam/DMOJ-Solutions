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
using ll = long long;
using pii = pair<int, int>;
const int MM = 1e5+5, LOG = 18;

int n, k, q, rt, dep[MM], sp[LOG][MM], kk[MM];
ll val[LOG][MM], dp[MM], dis[MM];
vector<pii> adj[MM];

void dfs(int cur, int pre){
	dep[cur] = dep[pre]+1;
	if(kk[cur])
		dp[cur] = 0;
	for(auto e: adj[cur]){
		int u = e.first;
		if(u == pre) continue;
		dis[u] = dis[cur]+e.second;
		dfs(u, cur);
		dp[cur] = min(dp[cur], dp[u]+e.second);
	}
	sp[0][cur] = pre;
	val[0][cur] = dp[cur]-dis[cur];
	// print(cur, dp[cur]-dis[cur]);
}

void query(int a, int b, int &lca, ll &ret){
	ret = dp[0]; //inf
	// cout<<"qu "<<a<<' '<<b<<endl;

	if(dep[a] < dep[b])
		swap(a, b);
	for(int i = LOG-1; i >= 0; i--){
		if(dep[a]-(1<<i) >= dep[b]){
			// cout<<"a "<<a<<' '<<sp[i][a]<<' '<<val[i][a]<<endl;
			ret = min(ret, val[i][a]);
			a = sp[i][a];
		}
	}
	if(a == b){
		lca = a;
		ret = min(ret, val[0][a]);
		return;
	}
	for(int i = LOG-1; i >= 0; i--){
		if(~sp[i][a] and sp[i][a] != sp[i][b]){
			ret = min(ret, min(val[i][a], val[i][b]));
			// cout<<"ab "<<a<<' '<<sp[i][a]<<' '<<val[i][a]<<endl;
			// cout<<"abb "<<b<<' '<<sp[i][b]<<' '<<val[i][b]<<endl;
			a = sp[i][a];
			b = sp[i][b];
		}
	}
	//one more bc par edge
	ret = min(ret, val[1][a]);
	ret = min(ret, val[0][a]);
	ret = min(ret, val[0][b]);
	lca = sp[0][a];
}

int a[MM], b[MM];

int main(){
	memset(sp, -1, sizeof sp);
	memset(dp, 0x3f, sizeof dp);
	scan(n, k, q, rt);
	for(int i = 0,c; i < n-1; i++){
		scan(a[i], b[i], c);
		adj[a[i]].emplace_back(b[i], c);
		adj[b[i]].emplace_back(a[i], c);
	}
	while(k--){
		int i;
		scan(i);
		kk[i] = 1;
	}
	dfs(rt, 0);

	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= n; j++){
			int u = sp[i-1][j];
			if(~u){
				sp[i][j] = sp[i-1][u];
				val[i][j] = min(val[i-1][j], val[i-1][u]);
			}
		}
	}

	while(q--){
		int i, x;
		scan(i, x);
		int aa = a[i-1], bb = b[i-1];
		if(dep[aa] < dep[bb])
			swap(aa, bb); //aa deeper

		int lca; ll ret;
		query(x, aa, lca, ret);

		// print(x, aa, lca);

		if(lca != aa){
			puts("escaped");
			continue;
		}
		ret += dis[x];
		if(ret < dp[0])
			print(ret);
		else
			puts("oo");
	}
}