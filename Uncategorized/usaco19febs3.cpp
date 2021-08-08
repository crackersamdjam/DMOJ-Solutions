#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 2e5+5;

int n, m, par[MM];

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	iota(par, par+MM, 0);
	cin>>n>>m;
	while(m--){
		char c; int a, b;
		cin>>c>>a>>b;
		if(c == 'S'){
			par[find(a)] = b;
			par[find(a+n)] = b+n;
		}
		else if(c == 'D'){
			par[find(a)] = b+n;
			par[find(b)] = a+n;
		}
		else abort();
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(find(i) == find(i+n)){
			cout<<"0\n";
			return 0;
		}
		ans += (find(i) == i) + (find(i+n) == i+n);
	}
	assert(ans%2 == 0);
	ans /= 2;
	cout<<"1";
	while(ans--)
		cout<<"0";
	cout<<'\n';
}