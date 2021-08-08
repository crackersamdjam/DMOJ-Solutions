#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 1e6+5;
const ll mod = 1e9+7;

vector<int> kmp(string s){
	vector<int> pi(size(s));
	pi[0] = 0;
	for(int i = 1, j = 0; i < size(s); i++){
		while(j and s[i] != s[j])
			j = pi[j-1];
		if(s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}

int t, n;
string s;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		cin>>s;
		n = size(s);

		auto k = kmp(s);
		vector<int> cnt(n, 0);

		for(int i = 1; i < n; i++){
			cnt[i] = 1;
			if(k[i-1])
				cnt[i] += cnt[k[i-1]];
		}

		ll ans = 1;
		for(int i = 1, j = 0; i < n; i++){
			while(j and s[i] != s[j])
				j = k[j-1];
			if(s[i] == s[j])
				j++;
			while(j*2 > i+1)
				j = k[j-1];

			ans = ans*(cnt[j]+1)%mod;
		}

		cout<<ans<<'\n';
	}
}