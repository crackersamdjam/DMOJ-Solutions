#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
// using ll = long long;
using ll = __int128;
const int MM = 2e5+5;

int n, in[MM];
ll p[MM], ans, add, sz[MM], up[MM];
vector<int> adj[MM];

ll dfs(int cur){
	if(sz[cur]) return sz[cur];
	sz[cur] = p[cur];

	for(int u: adj[cur])
		sz[cur] += dfs(u);
	
	for(int u: adj[cur])
		add = max(add, (sz[cur]-sz[u])*(up[u]-up[cur]));

	ans += p[cur]*(sz[cur]-1);
	return sz[cur];
}

int main(){
	scan(n);
	for(int i = 1; i <= n; i++){
		scan(p[i]);
	}
	for(int i = 0,a,b; i < n-1; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		in[b]++;
	}
	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(!in[i])
			q.emplace(i);
	}
	while(size(q)){
		int cur = q.front(); q.pop();
		up[cur] += p[cur];
		for(int u: adj[cur]){
			up[u] += up[cur];
			if(!--in[u]){
				q.emplace(u);
			}
		}
		// print(cur, up[cur]);
	}

	for(int i = 1; i <= n; i++){
		if(!sz[i])
			dfs(i);
	}

	print(ans + add);
	// pr(ans, add);
}