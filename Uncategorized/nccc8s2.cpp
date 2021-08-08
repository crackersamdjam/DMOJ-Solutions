#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const ll mod = 1e9+7;

string s;
ll ans = 1, cnt[200];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	for(auto c: s)
		cnt[c]++;
	for(auto i: cnt)
		ans = ans*(i+1)%mod;
	cout<<ans<<'\n';
}