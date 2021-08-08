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
using pii = pair<int, int>;
const int MM = 2e5+5;

int n, m, t[MM], cost;
vector<pii> adj[MM];
ll ans, lvl;
priority_queue<pii, vector<pii>, greater<pii>> q;
bool vis[MM];

int main(){
	scan(n, m);
	for(int i = 1; i <= n; i++){
		scan(t[i]);
	}
	for(int i = 0,a,b,c; i < m; i++){
		scan(a, b, c);
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	lvl = 1;
	cost = t[1];
	q.emplace(0, 1);
	while(size(q)){
		auto [curd, cur] = q.top(); q.pop();
		if(vis[cur]) continue;
		if(lvl < curd){
			ans += cost*(curd-lvl);
			lvl = curd;
		}
		vis[cur] = 1;
		cost = min(cost, t[cur]);
		if(cur == n)
			break;
		for(auto [u, w]: adj[cur]){
			if(!vis[u]){
				q.emplace(w, u);
			}
		}
	}
	print(vis[n] ? ans : -1);
}