#include <bits/extc++.h>
#define all(x) (x).begin(), (x).end()
template<typename T> int size(const T &a){return a.size();}

using namespace std;
using ll = long long;
const int MM = 1505;


int n;
ll a[MM];
__gnu_pbds::gp_hash_table<ll, ll> mp, sub[MM];
ll ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			ll v = a[i]*a[j];
			ans += mp[v]++;
			ans -= sub[j][v]++;
			ans -= sub[i][v]++;
		}
	}
	cout<<ans*8<<'\n';
}