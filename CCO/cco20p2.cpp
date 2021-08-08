#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
constexpr int MM = 2e5+5;

int n, ord[MM], bit[MM];
vector<int> in[MM];
priority_queue<int> q;
long long ans;

void up(int i, int x){
	for(; i < MM; i += i&-i)
		bit[i] += x;
}

int qu(int i){
	static int x;
	for(x = 0; i; i -= i&-i)
		x += bit[i];
	return x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	for(int i = 1,d; i <= n; i++){
		cin>>d;
		in[d].emplace_back(i);
	}
	for(int i = n; i; i--){
		for(int a: in[i])
			q.emplace(a);
		if(q.empty()) return cout<<"-1\n", 0;
		ord[i] = q.top(); q.pop();
	}
	for(int i = 1; i <= n; i++){
		ans += i-1-qu(ord[i]);
		up(ord[i], 1);
	}
	cout<<ans<<'\n';
}