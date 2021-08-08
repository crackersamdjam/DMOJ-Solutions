#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using pii = pair<int, int>;
const int MM = 5e5+5;

int x, n;
int ans;
priority_queue<int, vector<int>, greater<>> q;
vector<int> add[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>x>>n;
	for(int i = 0,a,b; i < n; i++){
		cin>>a>>b;
		a = max(0, a-x);
		// b = a+b;
		// v.emplace_back(a, b);
		add[a].emplace_back(b);
		// pr(a, b);
	}
	for(int i = 0; i < MM; i++){
		for(auto b: add[i])
			q.push(b);
		while(size(q) and q.top() < i)
			q.pop();
		if(size(q)){
			ans++;
			q.pop();
		}
	}
	cout<<ans<<'\n';
}