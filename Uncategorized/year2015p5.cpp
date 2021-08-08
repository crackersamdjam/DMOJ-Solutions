#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 2001;
const ll base = 31, mod = 1e9+7;

string s, t[MM];
int n, m;
ll dp[MM], v[MM], hs[MM], p[MM], ans;
bitset<MM> st[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s>>m;
	for(int i = 0; i < m; i++){
		cin>>t[i];
		for(auto c: t[i])
			v[i] = (v[i]*base+c)%mod;
	}

	p[0] = 1;
	st[0][0] = 1;
	for(int i = 1; i <= s.size(); i++){
		p[i] = p[i-1]*base%mod;
		hs[i] = (hs[i-1]*base+s[i-1])%mod;
		for(int j = 0; j < m; j++){
			int l = t[j].size();
			if(i >= l and v[j] == ((hs[i]-hs[i-l]*p[l]%mod+mod)%mod)){
				st[i] |= st[i-l];
			}
		}
		ans += st[i].count();
		st[i][i] = 1;
	}
	cout<<ans<<'\n';
}