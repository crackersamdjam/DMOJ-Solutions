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
using pii = pair<int, int>;
const int MM = 1<<17;

int n, m, C, st, ed;
vector<pii> adj[MM];
int dis[MM], hi[MM];

priority_queue<pii, vector<pii>, greater<pii>> q;

int main(){
	scan(n, m, C);
	for(int i = 0,a,b,c; i < m; i++){
		scan(a, b, c);
		adj[a].emplace_back(b, c);
	}
	scan(st, ed);
	memset(dis, 0x3f, sizeof dis);
	q.emplace(dis[st] = 0, st);

	while(size(q)){
		auto [curd, cur] = q.top(); q.pop();
		if(curd > dis[cur])
			continue;
		if(cur == ed){
			print(dis[ed]);
			break;
		}

		for(auto [u, w]: adj[cur]){
			if(curd+w < dis[u])
				q.emplace(dis[u] = curd+w, u);
		}

		for(int i = 1; i <= n; i <<= 1){
			int u = cur^i;
			if(curd+i*C < dis[u])
				q.emplace(dis[u] = curd+i*C, u);
		}
	}
}