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
const ll mod = 1e9+7;
const int MM = 303, NN = 1e6+5;

int n, m, k, a[MM][MM], mp[NN];
vector<int> v;
ll dp[2][MM][2005], ans;

int main(){
	scan(n, m, k);
	k--;
	int quot = 1, div;

	v.emplace_back(k+1);
	v.emplace_back(k);
	while(quot < k){
		div = k/(quot+1);
		//lowest quot option is quot+1
		v.emplace_back(div);
		quot = k/div;
	}
	v.emplace_back(0);
	k++;
	reverse(all(v));

	mp[0] = 0;
	for(int i = 1; i <= k; i++){
		mp[i] = mp[i-1];
		while(mp[i] < v.size() and v[mp[i]] < i)
			mp[i]++;
		// print(mp[i], lower_bound(all(v), i)-v.begin());
	}

	int c = 0;
	dp[c^1][0][1] = 1;
	for(int i = 0; i < n; i++){
		c ^= 1;
		for(int j = 0; j <= m; j++)
			for(int pre = 0; pre < v.size(); pre++)
				dp[c][m][pre] = dp[c^1][j][pre] = 0;

		for(int j = 0; j < m; j++){
			scan(a[i][j]);
			for(int pre = 1; pre <= v.size(); pre++){
				int val = min((ll)v[pre]*a[i][j], (ll)k);
				int id = mp[val];
				// print(val, id, v[id]); cout<<flush;
				// assert(v[id] <= val and (id+1 >= v.size() or v[id+1] > val));
				dp[c^1][j][id] += dp[c][j][pre];
				dp[c^1][j][id] %= mod;
				dp[c][j+1][id] += dp[c][j][pre];
				dp[c][j+1][id] %= mod;
			}
		}
	}

	print((dp[c^1][m-1][v.size()-1])%mod);
}