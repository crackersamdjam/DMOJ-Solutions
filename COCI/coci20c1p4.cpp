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

int n, sz[MM], ans = 1e9;
multiset<int> st;
vector<int> adj[MM];

int getsz(int cur, int pre){
	for(int u: adj[cur]){
		if(u != pre)
			sz[cur] += getsz(u, cur);
	}
	return ++sz[cur];
}

void dfs(int cur, int pre){
	int rem = n-sz[cur];
	auto it = st.lower_bound(rem/2+1);
	if(it != st.end()){
		ans = min(ans, max({sz[cur], *it, rem-*it}) - min({sz[cur], *it, rem-*it}));
	}
	if(it != st.begin()){
		it--;
		ans = min(ans, max({sz[cur], *it, rem-*it}) - min({sz[cur], *it, rem-*it}));
	}

	st.insert(n-sz[cur]);
	for(int u: adj[cur]){
		if(u != pre)
			dfs(u, cur);
	}
	st.erase(st.lower_bound(n-sz[cur]));
	st.insert(sz[cur]);
}

int main(){
	scan(n);
	for(int i = 0,a,b; i < n-1; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	getsz(1, 0);
	dfs(1, 0);
	print(ans);
}
/*
first get sizes
then in dfs,
first query for ans when taking current subtree
then insert n-sz[cur] (above)
then dfs all children
then erase n-sz[cur]
then add sz[cur]
return
*/