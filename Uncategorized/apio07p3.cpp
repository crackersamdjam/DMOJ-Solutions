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
const int N = 1e4+9, C = 5e4+9;

int dp[N][1<<4];
int n, m, ans;
vector<pair<int, int>> v[N];

int cnt(int i, int mask){
	int ret = 0;
	for(auto j: v[i]){
		// print(i, mask, j.first, j.second, !!(mask&(j.first|j.second)));
		if((mask&j.second) or (j.first != (mask&j.first))) //added wanted or {out of hated, some are not there}
			ret++;
	}
	return ret;
}

int main(){
	scan(n, m);
	while(m--){
		int i, a, b, mask = 0, mask2 = 0;
		scan(i, a, b);
		i += 4;
		while(a--){
			int j; scan(j);
			int d = (i-j)%n;
			// print(i, j, i-j, d);
			if(d >= 0 and d < 5)
				mask |= 1<<d;
		}
		while(b--){
			int j; scan(j);
			int d = (i-j)%n;
			// print(i, j, i-j, d);
			if(d >= 0 and d < 5)
				mask2 |= 1<<d;
		}
		v[i].emplace_back(mask, mask2);
		// print(mask, mask2);
	}
	for(int st = 0; st < (1<<4); st++){
		//1,2,3,4 are fixed
		memset(dp, -0x3f, sizeof dp);
		dp[4][st] = 0;
		for(int i = 5; i <= n+4; i++){
			for(int prem = 0; prem < (1<<4); prem++){
				// if(dp[i-1][prem] >= 0)
					// print(st, i-1, prem, dp[i-1][prem]);

				if(i > n){
					//not more taking, only merging
					int realm = prem<<1;
					int curm = realm&15;

					realm |= st>>(n+4-i);
					dp[i][curm] = max(dp[i][curm], dp[i-1][prem] + cnt(i, realm));

					ans = max(ans, dp[i][curm]);
					continue;
				}

				int realm = prem<<1;
				int curm = realm&15;
				//no take
				dp[i][curm] = max(dp[i][curm], dp[i-1][prem] + cnt(i, realm));
				
				//take
				realm |= 1;
				curm |= 1;
				dp[i][curm] = max(dp[i][curm], dp[i-1][prem] + cnt(i, realm));
			}
		}

	}
	print(ans);
}
//1100010000