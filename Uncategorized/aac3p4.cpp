#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int const MM = 5e5+5;

int n, m;
int a[MM], b[MM], ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>m;
	set<pair<int, int>> st;
	for(int i = 0; i < n; i++){
		cin>>a[i];
		if(~a[i]){
			st.insert({a[i]-i, i});
		}
	}
	for(int i = 0; i < m; i++){
		cin>>b[i];
		if(b[i] == -1) continue;

		int val = b[i]-i;
		auto it = st.lower_bound({val, -1});
		if(it != st.end() and it->first == val){
			// pr(i, b[i], ",", it->second, a[it->second]);
			ans++;
			st.erase(it);
		}
	}

	cout<<ans<<'\n';
}
/*
a[i] + j = b[j] + i
a[i]-i = b[j]-j
*/