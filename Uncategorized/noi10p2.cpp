#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

template<class T> struct sparse_table{
	
	int n; vector<vector<T>> sp;
	function<T(T, T)> merge;
	
	T query(int l, int r){
		int k = __lg(r-l+1);
		return merge(sp[k][l], sp[k][r-(1<<k)+1]);
	}
	void build(vector<T> v, function<T(T, T)> f){
		merge = f;
		n = (int)size(v);
		sp.resize(__lg(n)+1);
		sp[0] = v;
		for(int i = 1; i <= __lg(n); i++){
			sp[i].resize(n);
			for(int j = 0; j+(1<<i)-1 < n; j++){
				sp[i][j] = merge(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
			}
		}
	}
};

int main(){
	int n, k, L, R;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n>>k>>L>>R;
	vector<pair<int, int>> a(n+1);
	for(int i = 1; i <= n; i++){
		cin>>a[i].first;
		a[i].first += a[i-1].first;
		a[i].second = i;
	}
	sparse_table<pair<int, int>> st;
	st.build(a, [](auto x, auto y){ return max(x, y); });
	priority_queue<tuple<int, int, int, int>> q;
	// val, ll, l, r,
	for(int i = 1; i+L-1 <= n; i++){
		int l = i+L-1, r = min(n, i+R-1);
		int v = st.query(l, r).first-a[i-1].first;
		q.emplace(v, i, l, r);
	}
	long long ans = 0;
	while(k--){
		assert(size(q));
		auto [_, ll, l, r] = q.top(); q.pop();
		// pr(_, ll, l, r);
		auto [v, m] = st.query(l, r);
		ans += v-a[ll-1].first;

		if(l < m){
			q.emplace(st.query(l, m-1).first-a[ll-1].first, ll, l, m-1);
		}
		if(m < r){
			q.emplace(st.query(m+1, r).first-a[ll-1].first, ll, m+1, r);
		}
	}
	cout<<ans<<'\n';
}