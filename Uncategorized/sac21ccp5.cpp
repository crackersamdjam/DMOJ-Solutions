#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 1e5+5;

int n, q, par[MM], sz[MM];

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>q;
	iota(par, par+n+1, 0);
	fill(sz, sz+n+1, 1);
	while(q--){
		int op, a, b;
		cin>>op;
		if(op == 1){
			cin>>a>>b;
			a = find(a), b = find(b);
			if(a != b){
				par[a] = b;
				sz[b] += sz[a];
			}
		}
		else{
			cin>>a;
			a = find(a);
			cout<<sz[a]<<'\n';
		}
	}
}