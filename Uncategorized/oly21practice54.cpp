#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;

int n, x;
set<int> st;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>x>>n;
	while(n--){
		int v;
		cin>>v;
		st.insert(v);
	}

	int d = 0;
	while(1){
		if(!st.count(x-d)){
			cout<<x-d<<'\n';
			break;
		}
		if(!st.count(x+d)){
			cout<<x+d<<'\n';
			break;
		}
		d++;
	}
}