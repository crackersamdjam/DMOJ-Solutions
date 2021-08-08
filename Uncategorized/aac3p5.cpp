#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int const MM = 2005;

int n, m;
string s[MM];
int dis[MM][MM];
using stt = tuple<int, int, int>;
// priority_queue<stt, vector<stt>, greater<>> q;
priority_queue<stt> q;
// pair<int, int> mv[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int up[MM][MM], down[MM][MM], ls[MM][MM], rs[MM][MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>m;

	// for(int i = 0; i < MM; i++){
	// 	for(int j = 0; j < MM; j++){
	// 		down[i][j] = n+1;
	// 		rs[i][j] = m+1;
	// 	}
	// }
	memset(down, -1, sizeof down);
	memset(up, -1, sizeof up);
	memset(ls, -1, sizeof ls);
	memset(rs, -1, sizeof rs);

	for(int i = 1; i <= n; i++){
		cin>>s[i];
		s[i] = " "+s[i];
		for(int j = 1; j <= m; j++){
			up[i][j] = up[i-1][j];
			ls[i][j] = ls[i][j-1];
			if(s[i][j] == '#'){
				up[i][j] = i;
				ls[i][j] = j;
			}
		}
	}

	for(int i = n; i; i--){
		for(int j = m; j; j--){
			down[i][j] = down[i+1][j];
			rs[i][j] = rs[i][j+1];
			if(s[i][j] == '#'){
				down[i][j] = i;
				rs[i][j] = j;
			}
		}
	}

	for(int j = 0; j < m+5; j++){
		s[0] += " ";
		s[n+1] += " ";
	}

	memset(dis, -1, sizeof dis);
	for(int j = 1; j <= m; j++){
		if(s[1][j] == '#'){
			q.emplace(dis[1][j] = 1e9, 1, j);
		}
	}

	auto ok = [&](int x, int y){
		return x > 0 and x <= n and y > 0 and y <= m;
	};

	auto push = [&](int x, int y, int v, int d){
		if(!ok(x, y)) return;
		if(d){
			d = min(d, v);
		}
		else{
			d = v;
		}
		// when d=0, camn just walk

		if(d > dis[x][y]){
			// pr("  p", x, y, d);
			q.emplace(dis[x][y] = d, x, y);
		}
	};

	while(size(q)){
		auto [curd, i, j] = q.top(); q.pop();
		if(curd < dis[i][j]) continue;
		// pr(curd, i, j);
		push(i, rs[i][j+1], curd, rs[i][j+1]-j-1);
		push(i, ls[i][j-1], curd, j-ls[i][j-1]-1);
		push(down[i+1][j], j, curd, down[i+1][j]-i-1);
		push(up[i-1][j], j, curd, i-up[i-1][j]-1);
	}
	for(int j = 1; j <= m; j++){
		if(dis[n][j] == 1e9)
			dis[n][j] = 0;
		cout<<(s[n][j] == '#' ? dis[n][j] : -1)<<" \n"[j==m];
	}
}
/*

#..#
#.##
#..#

width 3, go right until hit earliest...


dis[i][j] is the max len canoe I can have and still reach i, j
(on a path, gets lower, but not higher)

*/