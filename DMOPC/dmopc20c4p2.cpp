#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

ll n, m, k;
set<ll> x, y;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>k;
	while(k--){
		ll a, b;
		cin>>a>>b;
		if(x.count(a))
			x.erase(a);
		else
			x.insert(a);

		if(y.count(b))
			y.erase(b);
		else
			y.insert(b);
	}
	assert(max(size(x), size(y)) <= 1e6);
	cout<<max(size(x), size(y))<<'\n';

	vector<ll> va, vb;
	for(auto i: x)
		va.emplace_back(i);
	for(auto i: y)
		vb.emplace_back(i);

	for(int i = 0; i < max(size(va), size(vb)); i++){
		ll a = (i < size(va)) ? va[i] : 1;
		ll b = (i < size(vb)) ? vb[i] : 1;
		// assert(1 <= a and a <= n);
		// assert(1 <= b and b <= m);
		cout<<a<<' '<<b<<'\n';
	}

	// while(size(x) or size(y)){
	// 	int a = 1;
	// 	if(size(x)){
	// 		a = *x.begin();
	// 		x.erase(a);
	// 	}

	// 	int b = 1;
	// 	if(size(y)){
	// 		b = *y.begin();
	// 		y.erase(b);
	// 	}

	// 	// cout<<a<<' '<<b<<'\n';
	// }
}