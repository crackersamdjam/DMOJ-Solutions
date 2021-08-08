#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 1e5+5, LIM = 320;

set<pair<int, int>> pts;
map<int, vector<int>> mpx, mpy;

bool go(int a, int b){
	return pts.count({a, b});
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	while(cin>>n){
		int ans = 0;
		pts.clear();
		mpx.clear();
		mpy.clear();

		for(int i = 0,x,y; i < n; i++){
			cin>>x>>y;
			pts.insert({x, y});
			mpx[x].emplace_back(y);
			mpy[y].emplace_back(x);
		}

		for(auto &[x, v]: mpx){
			if(size(v) < LIM){
				for(int i = 0; i < size(v); i++){
					for(int j = i-1; j >= 0; j--){
						int d = abs(v[i]-v[j]);
						if(d < ans) continue;
						if(go(x-d, v[j]) and go(x-d, v[i]))
							ans = d;
						if(go(x+d, v[j]) and go(x+d, v[i]))
							ans = d;
					}
				}
			}
			else{
				for(int i = 0; i < size(v); i++){
					int y = v[i];
					auto &vv = mpy[y];
					for(int j = 0; j < size(vv); j++){
						int d = abs(x-vv[j]);
						if(d < ans) continue;
						if(go(x, y-d) and go(vv[j], y-d))
							ans = d;
						if(go(x, y+d) and go(vv[j], y+d))
							ans = d;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}