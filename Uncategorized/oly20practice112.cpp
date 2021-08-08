#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

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
const int MM = 305;

int n, k, v[MM];
char t[MM];
string s;

int full, nolast;
ll dp[MM][MM][MM];
//dp[l][r][mask that replaced [l, r] ]

int getlen(int l, int r){
	return (r-l)%(k-1)+1;
}

ll go(int l, int r, int m){
	if(l == r){
		return (m == s[l]-'0') ? 0 : -1e12;
	}
	ll &ret = dp[l][r][m];
	if(~ret) return ret;
	ret = -1e12;

	if(getlen(l, r) == 1){
		if(m > 1) return ret;
		//different approach
		for(int mm = 0; mm < (1<<k); mm++){
			if(t[mm]-'0' != m) continue;
			ll val = -1e12;
			for(int i = r-1; i >= l; i -= k-1){
				if(getlen(l, i) == k-1 and getlen(i+1, r) == 1)
					val = max(val, go(l, i, mm>>1) + go(i+1, r, mm&1));
			}
			val += v[mm];
			ret = max(ret, val);
		}
		return ret;
	}

	for(int i = r-1; i >= l; i -= k-1){
		if(getlen(l, i)+1 == getlen(l, r) and getlen(i+1, r) == 1)
			ret = max(ret, go(l, i, m>>1) + go(i+1, r, m&1));
	}

	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin>>n>>k;
	cin>>s;

	full = (1<<k)-1;
	nolast = full^1;

	for(int i = 0; i < (1<<k); i++)
		cin>>t[i]>>v[i];

	for(int i = 0; i < n; i++){
		dp[i][i][0] = -1e12;
		dp[i][i][1] = -1e12;
		dp[i][i][s[i]-'0'] = 0;
	}

	ll ans = -1e9;
	for(int i = 0; i < (1<<k); i++){
		ans = max(ans, go(0, n-1, i));
	}
	cout<<ans<<'\n';
}