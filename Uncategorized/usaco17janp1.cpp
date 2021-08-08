#include <bits/extc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int constexpr MM = 1e5+5;

int n, a[MM], ans[MM];
pair<int, int> b[MM];
vector<int> adj[MM];
int bit[MM], in[MM], out[MM], t;

void up(int i){
	for(; i < MM; i += i&-i)
		bit[i]++;
}
int qu(int i){
	int x = 0;
	for(; i; i -= i&-i)
		x += bit[i];
	return x;
}

void dfs(int cur){
	in[cur] = ++t;
	for(int u: adj[cur])
		dfs(u);
	out[cur] = t;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		b[i] = {a[i], -i};
	}
	for(int i = 2,p; i <= n; i++){
		cin>>p;
		assert(p < i);
		adj[p].emplace_back(i);
	}
	dfs(1);

	sort(b+1, b+1+n);
	for(int i = n; i; i--){
		int u = -b[i].second;
		ans[u] = qu(out[u])-qu(in[u]-1);		
		up(in[u]);
	}
	for(int i = 1; i <= n; i++)
		cout<<ans[i]<<'\n';
}