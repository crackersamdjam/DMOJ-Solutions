#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 2e5+5;

int t;

int main(){
	cin>>t;
	while(t--){
		ll g, h;
		cin>>g>>h;
		// if(g == 1 and a == 4){
			// cout<<"99 23\n";
			// continue;
		// }

		ll b = 1;
		while(b <= g)
			b = b*h;

		b += (g-b%g)%g;

		ll a = b*h+g;

		cout<<a<<' '<<b<<'\n';
	}
}