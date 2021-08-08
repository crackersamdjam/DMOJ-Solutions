#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define ONLINE_JUDGE

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
const int MM = 10+2, NN = 1024+2;
const ll mod = 1e9+7;

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

int tc, n, lx[MM], ly[MM], rx[MM], ry[MM], v[MM];
ll sz[NN];
int H, W, M;

int main(){
	scan(tc);
	while(tc--){
		scan(H, W, M, n);
		for(int i = 0; i < n; i++){
			scan(lx[i], ly[i], rx[i], ry[i], v[i]);
		}
		for(int i = 0; i < (1<<n); i++){
			int la = 1, lb = 1, ra = H, rb = W;
			for(int j = 0; j < n; j++){
				if(i&(1<<j)){
					la = max(la, lx[j]);
					lb = max(lb, ly[j]);
					ra = min(ra, rx[j]);
					rb = min(rb, ry[j]);
				}
			}
			sz[i] = (ll)(ra-la+1)*(rb-lb+1);
			if(la > ra or lb > rb)
				sz[i] = 0;
			pr(i, "sz", la, lb, ra, rb, sz[i]);
			for(int j = 0; j < i; j++){
				if(((j&i) == j)){
					ll f = (__builtin_popcount(j^i)&1) ? -1 : 1;
					//subtract from j's size
					sz[j] += f*sz[i];
				}
			}
		}
		ll A = 0;
		for(int i = 0; i < (1<<n); i++){
			pr(i, "newsz", sz[i]);
			// sz[i] = max(sz[i], 0LL);
			assert(sz[i] >= 0);
			A += sz[i];
		}
		assert(A == (ll)H*W);
		ll ans = 0;
		for(int mask = 0; mask < (1<<n); mask++){
			pr("mask", mask);
			ll f = (__builtin_popcount(mask)&1) ? -1 : 1;
			//all in mask get -1
			ll cnt = 1;
			for(int i = 0; i < (1<<n); i++){
				//look in group i
				ll mx = M;
				for(int j = 0; j < n; j++){
					if(i&(1<<j)){
						ll val = v[j];
						if(mask&(1<<j)){
							val--;
							pr("sub", val, j, mask);
						}
						mx = min(mx, val);
					}
				}
				cnt = cnt*fpow(mx, sz[i], mod)%mod;
				pr(i, "mul", mx, "^", sz[i], "=", fpow(mx, sz[i], mod));
			}
			pr("cnt", mask, cnt);
			ans = (ans+cnt*f)%mod;
		}
		if(ans < 0)
			ans += mod;
		print(ans);
	}
}