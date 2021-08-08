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

int n;
int to[MM];
ll r[MM], sum[MM];
int in[MM];
bool vis[MM];
queue<int> q;
ll ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>to[i]>>r[i];
		in[to[i]]++;
	}
	for(int i = 1; i <= n; i++){
		if(!in[i]){
			vis[i] = 1;
			ans += r[i];
			sum[i] = r[i];
			q.push(i);
		}
	}

	while(size(q)){
		int cur = q.front(); q.pop();
		vis[cur] = 1;
		int u = to[cur];
		assert(r[cur] == sum[cur]);
		sum[u] = min(r[u], sum[u]+r[cur]);
		in[u]--;

		if(!vis[u] and !in[u]){
			ans += r[u]-sum[u];
			sum[u] += r[u]-sum[u];
			q.push(u);
		}
	}

	for(int st = 1; st <= n; st++){
		if(!vis[st]){
			int u = st;
			vector<int> v;
			do{
				v.emplace_back(u);
				assert(!vis[u]);
				vis[u] = 1;
				u = to[u];
			} while(u != st);

			vector<ll> add(size(v));
			for(int i = 0; i < size(v); i++){
				int p = v[i ? i-1 : size(v)-1];
				add[i] = max(0LL, r[v[i]]-sum[v[i]]-r[p]);
			}

			ll tot = accumulate(all(add), 0LL);
			ll best = 1e9;
			for(int i = 0; i < size(v); i++){
				best = min(best, tot-add[i]+max(0LL, r[v[i]]-sum[v[i]]));
			}
			ans += best;
		}
	}

	cout<<ans<<'\n';
}