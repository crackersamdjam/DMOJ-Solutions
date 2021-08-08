#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 2e5+5;

ll hs(ll a, ll b){
	return (a<<32)|b;
}

int n, m, k, a[MM][20];
// __gnu_pbds::gp_hash_table<ll, int> mp[20];
ll ans;

array<int, 2> b[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin>>a[i][j];
		}
	}
	for(int j = 0; j < m-1; j++){
		for(int i = 0; i < n; i++){
			b[i] = {a[i][j], a[i][j+1]};
		}
		sort(b, b+n);
		int l = 0;
		for(int i = 0; i < n; i++){
			array<int, 2> tar = {b[i][0]-k, b[i][1]-k};
			while(b[l] < tar)
				l++;
			if(b[l] == tar)
				ans++;
		}
	}

	cout<<ans<<'\n';
}