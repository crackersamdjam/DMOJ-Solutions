#include <bits/extc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
using T = int;

typedef __gnu_pbds::tree<T, __gnu_pbds::null_type, less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> bbst;
bbst t;

int n, m;
ll ans;

struct st{
	int op, x, y;
	bool operator<(const st &o) const{
		if(x != o.x)
			return x < o.x;
		return op < o.op;
	}
};
vector<st> v;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>m;
	while(n--){
		int x, y;
		cin>>x>>y;
		v.push_back({1, x, y});
	}
	while(m--){
		int x, y;
		cin>>x>>y;
		v.push_back({0, x, y});
	}
	// t.insert(-1);
	// t.insert(1e9+5);
	sort(all(v));
	for(auto [op, x, y]: v){
		// pr(op, x, y);
		if(!op){
			t.insert(y);
		}
		else{
			ans += size(t)-t.order_of_key(y);
			// pr(size(t)-t.order_of_key(y));
		}
	}
	cout<<ans<<'\n';
}