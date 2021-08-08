#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;

int n, m, par[MM], e;
vector<int> v;

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i = 1; i <= n; i++)
		par[i] = i;
	for(int i = 1,a,b; i <= m; i++){
		cin>>a>>b;
		a = find(a), b = find(b);
		if(a != b){
			e++;
			par[a] = b;
			v.emplace_back(i);
		}
	}
	if(e != n-1)
		return cout<<"Disconnected Graph", 0;
	for(int i: v)
		cout<<i<<'\n';

	
	return 0;
}