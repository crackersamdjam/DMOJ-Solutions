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
constexpr int MM = 1e5+5;

int n, k, q, a[MM], b[MM];
int bit[MM];
vector<int> in[MM];
ll sum;
map<int, ll> mp[MM];

void up(int i, int x){
	for(; i <= n; i += i&-i)
		bit[i] += x;
}

int qu(int i){
	int x = 0;
	for(; i; i -= i&-i)
		x += bit[i];
	return x;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>k>>q;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		in[a[i]].emplace_back(i);
		up(a[i], 1);
		sum += i-qu(a[i]);
		b[i] = i;
	}
	while(q--){
		int i; cin>>i;
		int f = b[i], s = b[i+1];
		if(mp[f].count(s)){
			sum += mp[f][s];
		}
		else{
			ll add = 0, sub = 0, ret = 0;
			ll tot = (ll)size(in[f])*size(in[s]);

			int i = 0, j = 0;

			if(size(in[f]) < size(in[s])){
				while(i < size(in[f])){
					j = lower_bound(all(in[s]), in[f][i])-in[s].begin();
					add += j;
					i++;
				}
				sub = tot-add;
				swap(add, sub);
			}
			else{
				while(j < size(in[s])){
					i = lower_bound(all(in[f]), in[s][j])-in[f].begin();
					add += i;
					j++;
				}
				sub = tot-add;
			}

			ret = add-sub;
			mp[f][s] = ret;
			sum += ret;
		}

		cout<<sum<<'\n';
		swap(b[i], b[i+1]);
	}
}