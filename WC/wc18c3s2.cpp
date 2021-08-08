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

int n, k, f, on[MM], fast;
vector<int> adj[MM];

bool dfs1(int cur, int pre){
	bool b = on[cur] || cur == f;
	for(int u: adj[cur])
		if(u != pre)
			b |= dfs1(u, cur);
	fast += b;
	return b;
}

int slow, mx;
bool dfs2(int cur, int pre, int d){
	bool b = on[cur];
	for(int u: adj[cur])
		if(u != pre)
			b |= dfs2(u, cur, d+1);
	slow += b;
	if(b) mx = max(mx, d);
	return b;
}


int main(){
	scan(n, k, f);
	while(k--){
		int a; scan(a);
		on[a] = 1;
	}
	for(int i = 0,a,b; i < n-1; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs1(1, 0);
	dfs2(1, 0, 0);
	fast--, slow--; //1 overcount
	int ans = min(fast, slow*2-mx);
	// print(fast, slow, mx);
	print(ans);
}