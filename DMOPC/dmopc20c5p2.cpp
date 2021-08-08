#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

ll n, m;
vector<pair<ll, ll>> v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	ll i = 1, j = 1;
	while(i <= n and j <= m){
		v.emplace_back(i, j);
		if(i*m == j*n)
			i++, j++;
		else if(i*m > j*n)
			j++;
		else
			i++;
	}
	cout<<size(v)<<'\n';
	for(auto [a, b]: v)
		cout<<a<<' '<<b<<'\n';
}