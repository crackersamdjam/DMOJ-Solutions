#include <bits/extc++.h>
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
const int MM = 2e5+5, NN = 500;
const ll base = 131, mod = 1e9+7;

ll mmod(ll x){
	x %= mod;
	if(x < 0) x += mod;
	return x;
}

__gnu_pbds::gp_hash_table<ll, ll> mp;

ll n, m, p[MM];
array<string, MM> s, t;
ll ans;
int bot[MM];
vector<int> upd[MM];

int main(){
	#ifdef CLION
	freopen("../in", "r", stdin);
	#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>s[i];
		s[i] = " "+s[i];
	}

	if(n < m){
		for(int j = 1; j <= m; j++)
			t[j].resize(n+1);

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				t[j][i] = s[i][j];
			}
		}
		swap(n, m);
		swap(s, t);
	}

	ll hasha[n+1][m+1];
	memset(hasha, 0, sizeof hasha);
	
	p[0] = 1;
	for(int i = 1; i < MM; i++)
		p[i] = p[i-1]*base%mod;
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			hasha[i][j] = (hasha[i][j-1]*base + s[i][j])%mod;
		}
	}
	
	for(int l = 1; l <= m; l++){
		for(int r = l+1; r <= m; r++){
			
			mp.clear();
			for(int i = 1, lo = 1; i <= n+1; i++){
				upd[i].clear();

				if(i == n+1 or s[i][l] != s[i][r]){
					while(lo <= i){
						bot[lo] = i;
						lo++;
					}
				}
			}
			
			for(int i = 1; i <= n; i++){

				for(auto j: upd[i]){
					mp[j]--;
				}
				
				ll cur = mmod(hasha[i][r] - hasha[i][l-1]*p[r-l+1]);
				ans += mp[cur];
				
				if(bot[i] > i+1){
					 mp[cur]++;
					upd[bot[i]].emplace_back(cur);
				}
			}
			
		}
	}
	cout<<ans<<'\n';
}
/*

2 2
YY
YY
ans = 1

3 4
YYBY
BYBB
YYBY
ans = 1

5 6
BBYBYB
BBBYBB
YYYBYY
YBYBBY
BBYBYB

*/