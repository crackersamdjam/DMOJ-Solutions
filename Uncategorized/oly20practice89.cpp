#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T ac=gc;_=ac==45;ac=_?gc:ac;while(ac<48||ac>57)ac=gc;for(;ac<48||ac>57;ac=gc);for(;ac>47&&ac<58;ac=gc)x=(x<<3)+(x<<1)+(ac&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

typedef long long ll;
constexpr int MM = 1e4+1;
constexpr ll mod = 1e9+7;

ll gcd(ll gcd_a, ll gcd_b){return gcd_b == 0 ? gcd_a : gcd(gcd_b, gcd_a % gcd_b);}
ll fpow(ll fpow_b, ll fpow_exp, ll fpow_mod){if(fpow_exp == 0) return 1;ll t = fpow(fpow_b,fpow_exp/2,fpow_mod);if(fpow_exp&1) return t*t%fpow_mod*fpow_b%fpow_mod;return t*t%fpow_mod;}
ll divmod(ll divmod_i, ll divmod_j, ll divmod_mod){divmod_i%=divmod_mod,divmod_j%=divmod_mod;return divmod_i*fpow(divmod_j,divmod_mod-2,divmod_mod)%divmod_mod;}

ll f[MM], inv[MM];

inline ll C(int n, int k){
	return f[n]*inv[k]%mod*inv[n-k]%mod;
}

int n, r[3];
std::string s[3];
ll ans;
int psa[MM][MM];
int abc, ab, ac, bc;

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	
	std::cin>>n;
	f[0] = inv[0] = 1;
	ans = fpow(2, n, mod);
	for(int i = 1; i <= n; i++)
		f[i] = f[i-1]*i%mod;
	inv[n] = fpow(f[n], mod-2, mod);
	for(int i = n-1; i; i--)
		inv[i] = inv[i+1]*(i+1)%mod;

	for(int i = 0; i < 3; i++){
		std::cin>>r[i]>>s[i];
		r[i] = n-r[i]-1;
	}
	for(int i = 0; i < n; i++){
		if(s[0][i] == s[1][i] and s[0][i] == s[2][i])
			abc++;
		else if(s[0][i] == s[1][i])
			ab++;
		else if(s[0][i] == s[2][i])
			ac++;
		else
			bc++;
	}
	
	for(int i = 0; i <= abc; i++){
		for(int j = 0; j <= ab; j++)
			psa[i+j][i+ab-j] = (psa[i+j][i+ab-j] + C(abc, i)*C(ab, j))%mod;
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			ll v = (ll)psa[i][j] + (i ? psa[i-1][j] : 0) + (j ? psa[i][j-1] : 0) - (i and j ? psa[i-1][j-1] : 0);
			while(v >= mod)
				v -= mod;
			while(v < 0)
				v += mod;
			psa[i][j] = v;
		}
	}
	for(int i = 0; i <= bc; i++){
		for(int j = 0; j <= ac; j++){
			int la = std::min(r[0]-j-(bc-i), r[1]-i-(ac-j));
			int lb = r[2]-i-j;
			if(la >= 0 and lb >= 0){
				ans = (ans - psa[la][lb]*C(bc, i)%mod*C(ac, j))%mod;
			}
		}
	}
	if(ans < 0)
		ans += mod;
	std::cout<<ans;
}
/*
abc+ab+ac+!bc <= r[0]
abc+ab+bc+!ac <= r[1]
abc+!ab+ac+bc <= r[2]

group A = abc+ab, abc+!ab = B

A+ac+!bc <= r[0]
A+bc+!ac <= r[1]
B+bc+ac <= r[2]

[A <= min(r[0]-ac-!bc, r[1]-bc-!ac)]
[B <= r[2]-bc-ac]

*/