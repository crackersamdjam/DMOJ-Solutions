#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 2e5+5;

int n, m;
vector<tuple<int, int, int, int>> adj[MM];
int deg[MM];
queue<int> q;
bool bad[MM], done[MM];

using stt = tuple<int, int, int>;
priority_queue<stt> pq;
int ans[MM];
int in[MM];
bool ee[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>m;
	pr(n, m);
	for(int i = 0,a,b,c,d; i < m; i++){
		cin>>a>>b>>c>>d;
		pr(a, b, c, d);
		adj[b].push_back({a, c, d, i});
		deg[a]++;
	}
	for(int i = 1; i <= n; i++){
		if(deg[i] == 0){
			q.push(i);
		}
	}
	while(size(q)){
		int cur = q.front(); q.pop();
		bad[cur] = 1;
		// pr("bad", cur);
		for(auto [u, c, d, id]: adj[cur]){
			if(!--deg[u]){
				q.push(u);
			}
		}
	}

	for(int i = 1; i <= n; i++){
		ans[i] = 2e9+5;
		for(auto [u, c, d, id]: adj[i]){
			if(!bad[i] and !bad[u]){
				pq.push({c, u, id});
				in[u]++;
			}
		}
	}

	while(size(pq)){
		auto [val, cur, i] = pq.top(); pq.pop();

		if(ee[i])
			continue;
		ee[i] = 1;

		ans[cur] = min(ans[cur], val);
		// pr("cur", cur, val, ans[cur]);
		in[cur]--;

		if(!in[cur]){

			done[cur] = 1;
			// pr("done");

			for(auto [u, c, d, id]: adj[cur]){
				if(bad[u] or done[u]) continue;

				int r = max(c, ans[cur]-d);
				// pr("push", u, c, d, "r", r);
				pq.push({r, u, id});
			}
		}
	}

	for(int i = 1; i <= n; i++){
		if(ans[i] > 1e9)
			ans[i] = -1;
		cout<<ans[i]<<' ';
	}
}