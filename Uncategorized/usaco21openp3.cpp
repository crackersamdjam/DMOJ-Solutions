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
const ll mod = 1e9+7;
const int MM = 155;

int n;
string s[MM];
ll dp[MM][MM][2][2];
ll ans;
int bad[MM][MM];

ll bl[MM][MM][2][2];
ll ul[MM][MM][2][2];

ll md(ll a){
	while(a < 0) a += mod;
	while(a >= mod) a -= mod;
	return a;
}

void add(ll &a, ll b){
	a = md(a+b);
}

int main(){
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>s[i];
		s[i] = " "+s[i];
		for(int j = 1; j <= n; j++){
			bad[i][j] = bad[i][j-1] + (s[i][j] == '.');
		}
	}
	for(int i = 1; i <= n; i++){
		memset(dp, 0, sizeof dp);
		for(int len = 1; len <= n; len++){
			for(int l = 1; l+len-1 <= n; l++){
				int r = l+len-1;
				if(bad[i][r]-bad[i][l-1]) continue;

				for(int fa = 0; fa <= 1; fa++){
					for(int fb = 0; fb <= 1; fb++){
						ll &v = dp[l][r][fa][fb];

						if(fa and fb){
							//both must decrease or same
							// for(int j = 1; j <= l; j++){
							// 	for(int k = r; k <= n; k++){
							// 		add(v, dp[i-1][j][k][1][1]);
							// 	}
							// }
							add(v, ul[l][r][1][1]);

							//also might just come from one that was growing (force to shrink to avoid overcount)
							//force ls to shrink
							// for(int j = 1; j < l; j++){
							// 	for(int k = r; k <= n; k++){
							// 		add(v, dp[i-1][j][k][0][1]);
							// 	}
							// }
							add(v, ul[l-1][r][0][1]);
							//force rs to shrink
							// for(int j = 1; j <= l; j++){
							// 	for(int k = r+1; k <= n; k++){
							// 		add(v, dp[i-1][j][k][1][0]);
							// 	}
							// }
							add(v, ul[l][r+1][1][0]);
							//force both to shirnk
							// for(int j = 1; j < l; j++){
							// 	for(int k = r+1; k <= n; k++){
							// 		add(v, dp[i-1][j][k][0][0]);
							// 	}
							// }
							add(v, ul[l-1][r+1][0][0]);
						}

						if(fa and !fb){
							// for(int j = 1; j <= l; j++){
							// 	for(int k = l; k <= r; k++){
							// 		add(v, dp[i-1][j][k][1][0]);
							// 	}
							// }
							add(v, bl[l][r][1][0]-bl[l][l-1][1][0]);

							//force ls to shrink
							// for(int j = 1; j < l; j++){
							// 	for(int k = l; k <= r; k++){
							// 		add(v, dp[i-1][j][k][0][0]);
							// 	}
							// }
							add(v, bl[l-1][r][0][0]-bl[l-1][l-1][0][0]);
						}
						if(!fa and fb){
							// for(int j = l; j <= r; j++){
							// 	for(int k = r; k <= n; k++){
							// 		add(v, dp[i-1][j][k][0][1]);
							// 	}
							// }
							add(v, ul[r][r][0][1]-ul[l-1][r][0][1]);

							//force rs to shrink
							// for(int j = l; j <= r; j++){
							// 	for(int k = r+1; k <= n; k++){
							// 		add(v, dp[i-1][j][k][0][0]);
							// 	}
							// }
							add(v, ul[r][r+1][0][0]-ul[l-1][r+1][0][0]);
						}
						if(!fa and !fb){
							// for(int j = l; j <= r; j++){
							// 	for(int k = j; k <= r; k++){
							// 		add(v, dp[i-1][j][k][0][0]);
							// 	}
							// }
							add(v, bl[r][r][0][0] - bl[l-1][r][0][0] - bl[r][l-1][0][0] + bl[l-1][l-1][0][0]);

							add(v, 1);
							//allow new one (nothing previous)
						}
						add(ans, v);
						// if(v) pr(i, l, r, fa, fb, v);

					}
				}
			}
		}
		for(int l = 1; l <= n; l++){
			for(int r = 1; r <= n; r++){
				for(int fa = 0; fa <= 1; fa++){
					for(int fb = 0; fb <= 1; fb++){
						bl[l][r][fa][fb] = md(bl[l-1][r][fa][fb] + bl[l][r-1][fa][fb] - bl[l-1][r-1][fa][fb] + dp[l][r][fa][fb]);
					}
				}
			}
		}
		for(int l = 1; l <= n; l++){
			for(int r = n; r > 0; r--){
				for(int fa = 0; fa <= 1; fa++){
					for(int fb = 0; fb <= 1; fb++){
						ul[l][r][fa][fb] = md(ul[l-1][r][fa][fb] + ul[l][r+1][fa][fb] - ul[l-1][r+1][fa][fb] + dp[l][r][fa][fb]);
					}
				}
			}
		}
	}
	cout<<ans<<'\n';
}