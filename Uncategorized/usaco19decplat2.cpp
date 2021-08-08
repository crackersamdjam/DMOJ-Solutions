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

int n, q;
vector<int> adj[MM];
int in[MM], out[MM], tt, nd[MM], sz[MM];
set<int> st[MM];

template<class T, int SZ> struct bit{
	T bit[SZ];
	void up(int i, T v){
		for(; i < SZ; i += i&-i)
			bit[i] += v;
	}
	T qu(int i){
		static T v;
		for(v = 0; i; i -= i&-i)
			v += bit[i];
		return v;
	}
};
bit<int, MM> sum, cnt;
// sum of sizes for subtree query, cnt of how many distinct colours for single node query

int dfs(int cur, int pre){
	in[cur] = ++tt;
	nd[tt] = cur;
	sz[cur] = 1;
	for(int u: adj[cur])
		if(u != pre)
			sz[cur] += dfs(u, cur);

	out[cur] = tt;
	return sz[cur];
}

int main(){
	scan(n, q);
	for(int i = 0,a,b; i < n-1; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	dfs(1, 0);

	while(q--){
		int op, a, b;
		scan(op, a);
		if(op == 1){
			scan(b);
			auto it = st[b].upper_bound(in[a]);
			if(it != st[b].begin() and out[a] <= out[nd[*prev(it)]])
				continue; // already covered
			
			while(it != st[b].end() and *it <= out[a]){
				int x = nd[*it];
				sum.up(in[x], -sz[x]);
				cnt.up(in[x], -1);
				cnt.up(out[x]+1, 1);
				it = st[b].erase(it);
			}
			st[b].insert(in[a]);
			sum.up(in[a], sz[a]);
			cnt.up(in[a], 1);
			cnt.up(out[a]+1, -1);
		}
		else{
			print(sum.qu(out[a])-sum.qu(in[a]) + sz[a]*cnt.qu(in[a]));
		}
	}
}
/*
subtree update and subtree query

http://usaco.org/current/data/sol_snowcow_platinum_dec19.html
*/