#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using ld = long double;
const int MM = 5e5+5;

int n, p[MM], par[MM], sz[MM];
ll sum[MM], val[MM];
bool taken[MM];

using stt = pair<ld, int>;
priority_queue<stt, vector<stt>, greater<stt>> q;

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

int vis[MM];

void dfs(int cur){
	vis[cur] = 1;
	if(p[cur]){
		if(!vis[p[cur]])
			dfs(p[cur]);
		else if(vis[p[cur]] == 1){
			cout<<"-1\n";
			exit(0);
		}
	}
	vis[cur] = 2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>p[i];
		par[i] = i;
	}
	for(int i = 1; i <= n; i++){
		cin>>sum[i];
		sz[i] = 1;
		val[i] = sum[i];
		q.push({val[i], i});
	}
	taken[0] = 1;
	ll ans = 0;
	int k = 0;

	for(int i = 1; i <= n; i++){
		if(!vis[i])
			dfs(i);
	}

	while(size(q)){
		int i = q.top().second; q.pop();
		if(i != find(i))
			continue;
		i = find(i);
		if(taken[i])
			continue;

		int b = find(p[i]);

		if(taken[b]){
			ans += sum[i]*k + val[i];
			k += sz[i];
			taken[i] = 1;
		}
		else{
			par[i] = b;
			val[b] += val[i]+sum[i]*sz[b];
			sum[b] += sum[i];
			sz[b] += sz[i];
			q.push({(ld)sum[b]/sz[b], b});
		}
	}
	cout<<ans<<'\n';
}