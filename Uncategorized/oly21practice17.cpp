#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

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
const ll mod = 998244353;

template<class T> T gcd(T _a, T _b){return _b == 0 ? _a : gcd(_b, _a%_b);}
template<class T, class U> T fpow(T _base, U _pow, T _mod){_base %= _mod; T _x = 1; for(; _pow > 0; _pow >>= 1){ if(_pow&1) _x = _x*_base%_mod; _base = _base*_base%_mod;} return _x;}
template<class T> T divmod(T _a, T _b, T _mod){return _a*fpow(_b, _mod-2, _mod)%_mod;}

int n, k;
ll dp[1<<12][1<<12], pre[1<<12][1<<12];
ll adj[12][12];

ll p1[1<<12][12];
ll p2[1<<12][12];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>k;
	for(int i = 0,a,b; i < n*(n-1); i++){
		ll p, q;
		cin>>a>>b>>p>>q;
		adj[a-1][b-1] = divmod(p, q, mod);
	}

	for(int m = 0; m < (1<<n); m++){
		for(int i = 0; i < n; i++){
			if((1<<i)&m) continue;

			//probability of not connected, no bad edge
			ll nc = 1, nbe = 1;

			for(int j = 0; j < n; j++){
				if((1<<j)&m){
					//never take
					nbe = nbe*(1 - adj[j][i])%mod;
					
					//keep unconnected
					nc = nc*(1 - adj[j][i])%mod;
				}
			}
			p1[m][i] = nbe;
			p2[m][i] = 1-nc;
		}
	}

	dp[0][1] = 1;
	int full = (1<<n)-1;

	for(int d = 0; d <= k; d++){
		swap(dp, pre);
		// memset(dp, 0, sizeof dp);

		for(int lo = 0; lo < (1<<n); lo++){
			int maxhi = full^lo;
			for(int hi = maxhi; ; hi = (hi-1)&maxhi){
				dp[lo][hi] = 0;
				if(!hi) break;
			}
		}

		//dis(i in lo) < d, dis(i in hi) = d, m is new layer with dis(i in m) = d+1
		for(int lo = 0; lo < (1<<n); lo++){
			
			int maxhi = full^lo;

			for(int hi = maxhi; ; hi = (hi-1)&maxhi){

				int maxm = full^lo^hi;

				//move this loop after... so that new nodes are added "one by one"
				for(int m = maxm; ; m = (m-1)&maxm){

					ll v = pre[lo][hi];
					if(!v) goto out;

					for(int i = 0; i < n; i++){
						if((1<<i)&m)
							v = v*p1[lo][i]%mod*p2[hi][i]%mod;
					}
					dp[lo|hi][m] += v;
					dp[lo|hi][m] %= mod;

					out:;
					if(!m) break;
				}
				if(!hi) break;
			}
		}
	}
	cout<<(dp[full][0]+mod)%mod<<'\n';
}