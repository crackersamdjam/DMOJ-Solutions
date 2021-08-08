#ifndef LOCAL
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 1e5+5;

int n, k, x;
unordered_map<int, array<int, 2>> mp;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>k>>x;
	for(int i = 0; i < n; i++){
		int l, r, t;
		cin>>l>>t>>r;
		mp[l][0]++;
		mp[r+1][0]--;

		for(int j = -1; j <= 1; j++){
			for(int a = -x; a <= 0; a += 2*x){
				mp[l+j+a];
				mp[r+j+a];
			}
		}
		// for the linesweep

		if(t >= r-l+1)
			continue;

		mp[l+t][1]++;
		mp[r+1][1]--;
	}

	ll ans = 0, sum = 0;

	vector<array<ll, 3>> a;
	a.resize(size(mp)+5);

	mp[0];
	mp[2e9];
	mp[2e9+1];

	for(auto [i, j]: mp){
		a.push_back({i, j[0], j[1]});
	}

	sort(all(a));

	for(int i = 1; i < (int)size(a); i++){
		a[i][1] += a[i-1][1]; //count psa
		a[i][2] += a[i-1][2]; //delta psa
	}

	//two pointers
	int l = 1, r = 1;
	while(r < (int)size(a)-1){
		// [l, r) and a bit of r if there is space

		ll len = a[r][0]-a[l][0];
		
		if(len <= x){
			ll rs = x-len;
			//add this much of r
			if(a[r][0]+rs < a[r+1][0]){
				//calc
				//otherwise r++ and calc next time
				ll add = 0;
				if(a[r][1] >= k){
					add = rs*a[r][2];
				}
				ans = max(ans, sum+add);
			}

			if(a[r][1] >= k){
				ll dd = (a[r+1][0]-a[r][0]);
				sum += dd*a[r][2];
			}
			r++;

		}
		else{
			if(a[l][1] >= k){
				ll dd = (a[l+1][0]-a[l][0]);
				sum -= dd*a[l][2];
			}
			l++;
		}
	}

	cout<<ans<<'\n';
}