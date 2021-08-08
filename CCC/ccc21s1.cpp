#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1e4+5;

int n, h[MM], w[MM], ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 0; i <= n; i++){
		cin>>h[i];
	}
	for(int i = 0; i < n; i++){
		cin>>w[i];
		ans += w[i]*(h[i]+h[i+1]);
	}
	cout<<fixed<<ans/2.0<<'\n';
}