#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using stt = pair<pair<int, ll>, pair<int, int>>;
const ll mod = 1e9+7;
const int MM = 505;

int n, m, qt;
ll v[MM][MM];
pair<int, ll> dis[MM][MM], ans;
array<int, 2> mv[] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
priority_queue<stt> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>qt;
	while(qt--){
		ll a, b, c, d, k;
		cin>>a>>b>>c>>d>>k;
		v[a][b] += k;
		
		v[a][b+d] -= k*(d+1);
		v[a][b+d+1] += k*(d);

		v[a+c][b] -= k*(c+1);
		v[a+c+1][b] += k*(c);

		v[a+c][b+d] += k*(c+1)*(d+1);
		v[a+c+1][b+d] -= k*(c)*(d+1);
		v[a+c][b+d+1] -= k*(c+1)*(d);
		v[a+c+1][b+d+1] += k*(c)*(d);
	}

	for(int t = 0; t < 2; t++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				v[i][j] += v[i-1][j] + v[i][j-1] - v[i-1][j-1];
			}
		}
	}
	
	memset(dis, -0x3f, sizeof dis);
	int sx, sy; cin>>sx>>sy;
	q.push({dis[sx][sy] = {1, v[sx][sy]}, {sx, sy}});

	while(size(q)){
		auto [curd, p] = q.top(); q.pop();
		auto [a, b] = p;
		if(curd < dis[a][b])
			continue;
		ans = max(ans, curd);
		for(auto [x, y]: mv){
			x += a, y += b;
			if(x and x <= n and y and y <= m and v[x][y] > v[a][b]){
				auto nx = curd;
				nx.first++;
				nx.second += v[x][y];
				if(nx > dis[x][y]){
					q.push({dis[x][y] = nx, {x, y}});
				}
			}
		}
	}
	cout<<ans.second%mod<<'\n';
}
/*

 1 0 0 -4 0
 0 0 0  0 0
-3 0 0 12 0
 0 0 0  0 0

 1  1  1 -3 0
 1  1  1 -3 0
-2 -2 -2 -6 0
 0  0  0  0 0

1 2 3 0 0 
2 4 6 0 0
0 0 0 0 0
0 0 0 0 0

*/