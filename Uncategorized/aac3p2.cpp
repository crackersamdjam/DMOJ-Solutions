#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int k, d;
	cin>>k>>d;
	vector<int> v(d);
	for(auto &i: v)
		cin>>i;
	sort(all(v));

	if(d == 1 and v[0] == 0)
		return cout<<"-1\n", 0;
	
	if(v[0] == 0){
		if(k == 1)
			return cout<<v[1]<<'\n', 0;

		k -= 2;
		cout<<v[1];
		while(k--)
			cout<<v[0];
		cout<<v[1];
		cout<<'\n';
	}
	else{
		while(k--)
			cout<<v[0];
		cout<<'\n';
	}
}