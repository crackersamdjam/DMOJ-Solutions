#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 1e6+5;

map<int, vector<int>> in;
vector<pair<int, int>> v, w;
set<pair<int, int>, greater<>> st;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	int n;
	cin>>n;
	for(int i = 1,a; i <= 2*n; i++){
		cin>>a;
		in[a].emplace_back(i);
	}
	for(auto &[a, b]: in){
		if(size(b)){
			st.insert({size(b), a});
		}
	}
	while(size(st) > 1){
		auto [cnta, a] = *st.begin();
		st.erase(st.begin());
		auto [cntb, b] = *st.begin();
		st.erase(st.begin());
		v.emplace_back(in[a].back(), in[b].back());
		in[a].pop_back();
		in[b].pop_back();
		if(cnta > 1)
			st.insert({cnta-1, a});
		if(cntb > 1)
			st.insert({cntb-1, b});
	}
	if(size(st)){
		int a = st.begin()->second;
		while(size(in[a])){
			int b = in[a].back();
			in[a].pop_back();
			int c = in[a].back();
			in[a].pop_back();
			w.emplace_back(b, c);
		}
	}
	cout<<size(v)<<'\n';
	for(auto [a, b]: v)
		cout<<a<<' '<<b<<'\n';
	for(auto [a, b]: w)
		cout<<a<<' '<<b<<'\n';
}