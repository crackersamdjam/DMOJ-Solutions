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
const int MM = 1e5+5;

int dpup[MM], dpdown[MM];
int n, q;
vector<pair<int, int>> adj[MM];

void dfs1(int cur, int pre){
	for(auto [u, w]: adj[cur]){
		if(u == pre) continue;
		dfs1(u, cur);
		dpdown[cur] = max(dpdown[cur], dpdown[u]+w);
	}
}

void dfs2(int cur, int pre){
	int mx = dpup[cur];
	for(auto [u, w]: adj[cur]){
		if(u == pre) continue;
		dpup[u] = max(dpup[u], mx+w);
		mx = max(mx, dpdown[u]+w);
	}
	reverse(all(adj[cur]));
	mx = dpup[cur];
	for(auto [u, w]: adj[cur]){
		if(u == pre) continue;
		dpup[u] = max(dpup[u], mx+w);
		dfs2(u, cur);
		mx = max(mx, dpdown[u]+w);
	}
}

int main(){
	scan(n, q);
	for(int i = 0,a,b,c; i < n-1; i++){
		scan(a, b, c);
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	
	while(q--){
		int a; scan(a);
		print(max(dpup[a], dpdown[a]));
	}
}