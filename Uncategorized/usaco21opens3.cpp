#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 1e5+5;

int n, m, k, a[MM];

bool go(int v){
	ll rem = (ll)m*k;
	int ans = 0;
	for(int i = 0; i < n; i++){
		int d = max(0, v-a[i]);
		if(d > m) break;
		if(d > rem) break;
		rem -= d;
		ans++;
	}
	return ans >= v;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m>>k;
	for(int i = 0; i < n; i++)
		cin>>a[i];
	sort(a, a+n, greater<>());
	int l = 0, r = 2e5;
	while(l <= r){
		int v = l+r>>1;
		if(go(v))
			l = v+1;
		else
			r = v-1;
	}
	cout<<r<<'\n';
}