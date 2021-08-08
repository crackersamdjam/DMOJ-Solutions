#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 2005;

int n, m, a[MM][MM], rs[MM], mx;

bool go2(int d){
	//wlog split pt goes right as i -> n
	for(int i = 1; i <= n; i++){
		int j = 0;
		while(j+1 <= m and mx-a[i][j+1] <= d)
			j++;
		rs[i] = j;
		for(int k = i-1; k; k--)
			rs[k] = min(rs[k], j);
	}
	int md = 0, hi = 0, lo = 1e9;
	for(int i = 1; i <= n; i++){
		for(int j = rs[i]+1; j <= m; j++){
			hi = max(hi, a[i][j]);
			lo = min(lo, a[i][j]);
		}
	}
	return hi-lo <= d;
}

bool go(int d){
	if(go2(d)) return 1;
	for(int i = 1; i <= n; i++)
		reverse(a[i]+1, a[i]+1+m);
	if(go2(d)) return 1;
	reverse(a+1, a+1+n);
	if(go2(d)) return 1;
	for(int i = 1; i <= n; i++)
		reverse(a[i]+1, a[i]+1+m);
	if(go2(d)) return 1;
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin>>a[i][j];
			mx = max(mx, a[i][j]);
		}
	}
	int l = 0, m, r = 1e9;
	while(l <= r){
		m = l+r>>1;
		if(go(m))
			r = m-1;
		else
			l = m+1;
	}
	cout<<l<<'\n';
}