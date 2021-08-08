#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using pii = array<int, 2>;
const int MM = 2e5+5;

int dis(pii a, pii b){
	return b[0]-a[0] + abs(b[1]-a[1]);
}

pii ree(pii a){
	if(a[0]%2) return a;
	return {a[0], -a[1]};
}

struct cmp{
	bool operator()(pii a, pii b) const{
		return ree(a) < ree(b);
	}
};

set<pii, cmp> st;
int n;
ll ans;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	st.insert({1, 1});
	for(int i = 1; i <= n; i++){
		pii a;
		cin>>a[0]>>a[1];
		auto it = st.upper_bound(a);
		if(it != st.begin() and it != st.end())
			ans -= dis(*prev(it), *it);
		
		it = st.insert(a).first;
		if(next(it) != st.end())
			ans += dis(*it, *next(it));
		if(it != st.begin())
			ans += dis(*prev(it), *it);
		
		cout<<ans<<'\n';
	}
}