#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 5e5+5;

int n, m, p[MM];
vector<int> adj[MM];
int bad[MM];
int deg[MM];
bool vis[MM];
queue<int> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		cin>>p[i];
	for(int i = 0,a,b; i < m; i++){
		cin>>a>>b;
		adj[b].emplace_back(a);
		deg[a]++;
	}
	for(int i = 1; i <= n; i++){
		if(!deg[i]){
			bad[i] = 1;
			q.push(i);
			// pr("i", i);
		}
	}
	while(size(q)){
		int cur = q.front(); q.pop();
		// pr("cur", cur);
		vis[cur] = 1;
		for(int u: adj[cur]){
			deg[u]--;
			if(vis[u]) continue;
			if(p[u] or !deg[u]){
				bad[u] = 1;
				vis[u] = 1;
				q.push(u);
				continue;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout<<bad[i]<<" \n"[i==n];
	}
}