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
	int n;
	cin>>n;
	vector<int> v(n);
	for(auto &i: v)
		cin>>i;
	sort(all(v));
	vector<int> a;
	string s;

	for(int i = 0; i < n/2; i++){
		a.emplace_back(v[i]);
		s += 'B';
		a.emplace_back(v[n-1-i]);
		s += 'S';
	}
	if(n%2){
		a.emplace_back(v[n/2]);
		s += 'E';
	}
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" \n"[i==n-1];
	}
	cout<<s<<'\n';
}