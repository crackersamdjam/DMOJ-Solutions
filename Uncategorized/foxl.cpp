#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int n, m, ans;
map<int, int> par;

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>m;
	ans = n;
	while(m--){
		int a, b;
		cin>>a>>b;
		if(!par[a])
			par[a] = a;
		if(!par[b])
			par[b] = b;
		a = find(a);
		b = find(b);
		if(a != b){
			par[a] = b;
			ans--;
		}
	}
	cout<<ans<<'\n';
}