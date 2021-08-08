#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 2e5+5;

int n, x[MM], dis[MM];
ll k;
vector<int> v;

int main(){
	cin>>n>>k;
	for(int i = 1; i <= n; i++)
		cin>>x[i];

	int a = 1;

	while(1){
		if(dis[a] == k){
			cout<<a<<'\n';
			break;
		}
		v.emplace_back(a);
		int b = x[a];
		if(dis[b]){
			int len = dis[a]+1-dis[b];
			k -= dis[b];
			k %= len;
			k += dis[b];
			cout<<v[k]<<'\n';
			break;
		}
		dis[b] = dis[a]+1;
		a = b;
	}
}