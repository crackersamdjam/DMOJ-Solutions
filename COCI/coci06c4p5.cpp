#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

void go(vector<int> v){
	int sz = size(v);
	if(!sz) return;
	int m = (sz-2)/2;
	cout<<v[m]<<' ';
	vector<int> c[2];
	for(int i = 0; i < sz; i++){
		if(i == m) continue;
		c[i%2].emplace_back(v[i]);
	}
	go(c[0]);
	go(c[1]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	int n;
	cin>>n;
	vector<int> v((1<<n)-1);
	iota(all(v), 1);
	go(v);
}