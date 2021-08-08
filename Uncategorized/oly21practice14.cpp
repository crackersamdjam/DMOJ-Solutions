#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
using stt = tuple<ll, int, int>;
const int MM = 1e5+5;

int n, m;
map<int, vector<array<int, 2>>> adj[MM];
map<int, ll> mp[MM];
map<int, ll> dis[MM];
priority_queue<stt, vector<stt>, greater<stt>> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i = 0,a,b,c,d; i < m; i++){
		cin>>a>>b>>c>>d;
		adj[a][c].push_back({b, d});
		adj[b][c].push_back({a, d});
		mp[a][c] += d;
		mp[b][c] += d;
	}

	q.emplace(dis[1][0] = 0, 1, 0);

	while(size(q)){
		auto [curd, cur, c] = q.top(); q.pop();
		if(curd > dis[cur][c]) continue;

		if(c){
			//means that last c was changed to different colour
			for(auto [u, d]: adj[cur][c]){
				//keep this edge colour, but change all other of this colour
				ll nd = curd+mp[cur][c]-d;
				if(!dis[u].count(0) or nd < dis[u][0]){
					q.emplace(dis[u][0] = nd, u, 0);
				}

				//for next to be same col
				// nd = curd+mp[cur][c]-d;
				// if(!dis[u].count(c) or nd < dis[u][c]){
					// q.emplace(dis[u][c] = nd, u, c);
				// }
			}
		}
		else{
			for(auto &[c, l]: adj[cur]){
				for(auto [u, d]: l){
					//change all other of this colour
					ll nd = curd+mp[cur][c]-d;
					if(!dis[u].count(0) or nd < dis[u][0]){
						q.emplace(dis[u][0] = nd, u, 0);
					}

					//change this
					//next is different
					nd = curd+d;
					if(!dis[u].count(0) or nd < dis[u][0]){
						q.emplace(dis[u][0] = nd, u, 0);
					}

					//next is same (cost to change this will be covered by next one)
					nd = curd;
					if(!dis[u].count(c) or nd < dis[u][c]){
						q.emplace(dis[u][c] = nd, u, c);
					}
				}
			}
		}
	}
	if(!dis[n].count(0))
		cout<<"-1\n";
	else
		cout<<dis[n][0]<<'\n';
}
/*
at each node, check all edges
can change this edge colour or all other edges of this colour

but when taking all other edges of this colour for many conseq moves, do not need to keep paying
*/

/*
4 3
1 2 1 1
2 3 1 2
3 4 1 3

should be 2
*/