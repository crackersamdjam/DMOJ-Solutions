#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 2e5+5;

int n;
array<int, 2> a[MM];
ll low, hi;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>low>>hi;
	for(int i = 0; i < n; i++){
		cin>>a[i][0];
		a[i][1] = i;
	}
	sort(a, a+n);

	set<int> st;
	int l = 0, r = -1;
	ll sum = 0;

	while(r < n){
		if(sum < low){
			r++;
			sum += a[r][0];
			st.insert(a[r][1]);
		}
		else if(sum > hi){
			sum -= a[l][0];
			st.erase(a[l][1]);
			l++;
		}
		else{
			cout<<size(st)<<'\n';
			for(auto i: st)
				cout<<i<<' ';
			exit(0);
		}
	}

	cout<<"0\n";
}