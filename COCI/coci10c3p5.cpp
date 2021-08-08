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
const int MM = 3e5+5;

int n, a[MM], l[MM], r[MM];
ll ans;

ll go(){
	a[0] = a[n+1] = 1e9;
	stack<int> stk;
	stk.push(0);
	ll ret = 0;
	for(int i = 1; i <= n+1; i++){
		while(size(stk) and a[stk.top()] <= a[i]){
			r[stk.top()] = i;
			stk.pop();
		}
		stk.push(i);
	}
	for(int i = n; i >= 0; i--){
		while(size(stk) and a[stk.top()] < a[i]){
			l[stk.top()] = i;
			stk.pop();
		}
		stk.push(i);
	}
	for(int i = 1; i <= n; i++){
		ret += (ll)a[i]*(i-l[i])*(r[i]-i);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	ans += go();
	for(int i = 1; i <= n; i++)
		a[i] = -a[i];
	ans += go();
	cout<<ans<<'\n';
}