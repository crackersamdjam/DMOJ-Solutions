#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using pii = pair<ll, int>;
const int MM = 1e5+5;

ll n, dis[MM], ans;
int a, b, c;
priority_queue<pii, vector<pii>, greater<pii>> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>a>>b>>c;
	n--;
	memset(dis, 0x3f, sizeof dis);
	q.emplace(dis[0] = 0, 0);
	while(size(q)){
		auto [curd, cur] = q.top(); q.pop();
		if(curd > dis[cur])
			continue;
		for(auto v: {b, c}){
			int u = (cur+v)%a;
			if(curd+v < dis[u]){
				q.emplace(dis[u] = curd+v, u);
			}
		}
	}
	for(int i = 0; i < a; i++){
		if(dis[i] <= n)
			ans += (n-dis[i])/a+1;
	}
	cout<<ans<<'\n';
}