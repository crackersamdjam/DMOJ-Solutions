#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 2e5+5;

int n, m, c[MM];
vector<int> adj[MM];
int far, ans[MM], in;
int cnt[MM], dep[MM], dp[MM];
stack<int> stk;

void dfs0(int cur, int pre){
	dep[cur] = dep[pre]+1;
	if(dep[cur] > dep[far])
		far = cur;
	for(int u: adj[cur]){
		if(u == pre) continue;
		dfs0(u, cur);
	}
}

void dfs1(int cur, int pre){
	dep[cur] = dep[pre]+1;
	dp[cur] = 1;
	for(int u: adj[cur]){
		if(u == pre) continue;
		dfs1(u, cur);
		dp[cur] = max(dp[cur], dp[u]+1);
	}
}

void add(int a){
	stk.push(a);
	in += !cnt[c[a]]++;
}

void rm(){
	in -= !--cnt[c[stk.top()]];
	stk.pop();
}

void go(int cur, int pre){
	vector<int> ch;
	for(int u: adj[cur])
		if(u != pre)
			ch.emplace_back(u);
	sort(all(ch), [](int x, int y){
		return dp[x] > dp[y];
	});
	int f = size(ch) ? ch[0] : 0;
	int s = size(ch) > 1 ? ch[1] : 0;

	if(pre)	add(pre);

	// remove s before going to f
	while(size(stk) and dep[cur]-dep[stk.top()] <= dp[s])
		rm();

	if(f) go(f, cur);

	// remove f before the rest
	while(size(stk) and dep[cur]-dep[stk.top()] <= dp[f])
		rm();

	ans[cur] = max(ans[cur], in);

	for(int u: ch){
		if(u == f)
			continue;
		go(u, cur);
	}

	if(size(stk) and stk.top() == pre)
		rm();
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i = 0,a,b; i < n-1; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	for(int i = 1; i <= n; i++){
		cin>>c[i];
	}

	dp[0] = -1e9;

	dfs0(1, 0);
	dfs1(far, 0);
	go(far, 0);

	dfs0(far, 0);
	dfs1(far, 0);
	go(far, 0);

	for(int i = 1; i <= n; i++){
		cout<<ans[i]<<'\n';
	}
}