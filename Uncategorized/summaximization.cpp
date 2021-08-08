#include <bits/stdc++.h>
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

int ans, t;
ll l, r;

void go(string s, int i, bool f){
	if(i == size(s)){
		if(stoll(s) >= l){
			int sum = 0;
			for(auto c: s)
				sum += c-'0';
			ans = max(ans, sum);
		}
		return;
	}
	if(f){
		s[i] = '9';
		go(s, i+1, 1);
	}
	else{
		go(s, i+1, 0);
		if(s[i] > '0'){
			s[i]--;
			go(s, i+1, 1);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		ans = 0;
		cin>>l>>r;
		go(to_string(r), 0, 0);
		cout<<ans<<'\n';
	}
}