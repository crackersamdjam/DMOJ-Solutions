#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n, s;
		cin>>n>>s;
		ll d = n*(n+1)/2-s;
		ll hi = min(n, d-1);
		ll m = d/2;
		cout<<hi-m<<'\n';
	}
}