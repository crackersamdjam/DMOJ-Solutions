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
const int MM = 5005;

vector<int> adj[MM], a, r;
int n, dp[MM], off[MM], in[MM], go[MM], no[MM];

void dfs(int cur){
	for(int u: adj[cur]){
		if(no[u])
			continue;
		go[u]--;
		if(!go[u] and u != cur and !r[u]) //do not visit charging again
			dfs(u);
	}
}

vector<int> who_wins(vector<int> _a, vector<int> _r, vector<int> st, vector<int> ed){
	a = _a, r = _r, n = a.size();
	for(int i = 0; i < st.size(); i++){
		adj[ed[i]].emplace_back(st[i]);
		in[st[i]]++;
	}
	for(int i = 0; i < n; i++)
		if(a[i]) in[i] = 1;

	while(1){
		bool f = 0;
		for(int i = 0; i < n; i++)
			go[i] = in[i];
		for(int i = 0; i < n; i++){
			if(r[i] and !no[i])
				dfs(i);
		}
		for(int i = 0; i < n; i++){
			if(r[i] and !no[i] and go[i] > 0){
				no[i] = 1;
				f = 1;
			}
		}
		if(!f) break;
	}
	vector<int> ans(n);
	for(int i = 0; i < n; i++)
		ans[i] = (go[i] <= 0 and !no[i]);
	
	return ans;
}

#ifndef ONLINE_JUDGE
int main(){
	vector<int> out = who_wins({0, 1}, {1, 0}, {0, 0, 1, 1}, {0, 1, 0, 1});
	for(int i: out)
		cout<<i<<' ';
	return 0;
}
#endif
/*
There is at least one track starting at each station.
*/