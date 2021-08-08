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
const int MM = 2e4+5;

int n, sz[MM], par[MM];
vector<int> adj[MM], vec;

int getsz(int cur, int pre){
	par[cur] = pre;
	bool b = 1;
	sz[cur] = 1;
	for(int u: adj[cur]){
		if(u != pre){
			sz[cur] += getsz(u, cur);
			if(sz[u] > n/2)
				b = 0;
		}
	}
	if(b && ((n - sz[cur]) <= n/2))
		vec.push_back(cur);
	return sz[cur];
}

int main(){
	scan(n);
	for(int i = 0,a,b; i < n-1; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	
	getsz(1, 0);

	sort(all(vec));
	int mx = 0;
	for(int u: adj[vec[0]]){
		if(u == par[vec[0]])
			mx = max(mx, n-sz[vec[0]]);
		else
			mx = max(mx, sz[u]);
	}
	print(vec[0], mx);
}