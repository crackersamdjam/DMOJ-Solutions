#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using pii = pair<int, int>;

// map<pair<int, int>, int> mp;
set<pii> rep;

map<pii, map<pii, int>> adj;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	pii cur = {2e9, 2e9};
	
	vector<pair<int, int>> input;
	int n;
	cin>>n;
	for(int i = 0,a,b; i < n; i++){
		cin>>a>>b;
		input.emplace_back(a, b);
	}
	for(auto [a, b]: input){
		// if(rep.count({a, b}))
			// continue;
		// rep.insert({a, b});
		assert(b%2 == 0);
		assert(a%2 == 0);
		int f = ((b%4+4)%4==2)^((a%4+4)%4==2);
		vector<pair<int, int>> v;
		
		if(f){
			v.emplace_back(a-1, b);
			v.emplace_back(a-1, b+1);
			v.emplace_back(a, b+2);
			v.emplace_back(a+1, b+2);
			v.emplace_back(a+2, b+1);
			v.emplace_back(a+2, b);
			v.emplace_back(a+1, b-1);
			v.emplace_back(a, b-1);
		}
		else{
			v.emplace_back(a, b);
			v.emplace_back(a+1, b);
			v.emplace_back(a+1, b+1);
			v.emplace_back(a, b+1);
		}
		int sz = size(v);
		for(int i = 0; i < sz; i++){
			adj[v[i]][v[(i+1)%sz]]++;
			adj[v[i]][v[(i-1+sz)%sz]]++;
			// mp[v[i]]++;
			// tie(a, b) = v[i];
			// adj[v[i]].emplace_back(a+1, b);
			// adj[v[i]].emplace_back(a-1, b);
			// adj[v[i]].emplace_back(a, b+1);
			// adj[v[i]].emplace_back(a, b-1);
			cur = min(cur, v[i]);
		}
	}
	// for(auto [a, b]: mp){
		// pr(a.first, a.second, b);
		// if(b < 3){
			// cur = min(cur, a);
		// }
	// }
	assert(cur.first != (int)2e9);
	pii init = cur;
	pii pre = cur;

	vector<pii> ans;
	do{
		// pr(cur.first, cur.second);
		ans.emplace_back(cur);
		int ok = 0;
		for(auto [u, k]: adj[cur]){
			if(k == 1 and u != pre){
				pre = cur;
				cur = u;
				ok = 1;
				break;
			}
		}
		assert(ok);
		// if(size(v) > 50) break;
	} while(cur != init);

	cout<<size(ans)<<'\n';
	for(auto [a, b]: ans)
		cout<<a<<' '<<b<<'\n';
}