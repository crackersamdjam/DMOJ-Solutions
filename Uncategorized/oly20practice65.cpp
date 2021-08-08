#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)

using namespace std;
using ll = long long;
using stt = bitset<1005>;
const ll mod = 1e9+7;

int n, m, l;
ll p[5005];
pair<stt, int> a[5005];
string s;

bool cmp(const stt &x, const stt &y){
	for(int i = n; i >= 0; i--)
		if(x[i]^y[i])
			return x[i] < y[i];
	return 0;
}

ll cnt(const stt &x){
	ll ret = 0;
	for(int i = 0; i <= n; i++){
		ret = (ret+x[i]*p[i])%mod;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>l>>m;

	p[0] = 1;
	for(int i = 1; i <= n+1; i++)
		p[i] = p[i-1]*2%mod;

	for(int i = 0; i < l; i++)
		a[i].second = i;
	
	for(int i = 0; i < n; i++){
		cin>>s;
		for(int j = 0; j < l; j++){
			if(s[j] == '1')
				a[j].first[i] = 1;
		}
	}

	sort(a, a+l, [](auto &x, auto &y){
		return cmp(x.first, y.first);
	});

	while(m--){
		stt lo, hi;
		hi[n] = 1;

		cin>>s;
		for(int j = l-1; j >= 0; j--){
			if(s[a[j].second] == '0'){
				// >=
				lo = a[j].first;
				break;
			}
		}
		for(int j = 0; j < l; j++){
			if(s[a[j].second] == '1'){
				// <
				hi = a[j].first;
				break;
			}
		}
		if(!cmp(lo, hi))
			cout<<"0\n";
		else
			cout<<(cnt(hi)-cnt(lo)+mod)%mod<<'\n';
	}
}