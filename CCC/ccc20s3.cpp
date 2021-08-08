// S3 solution in O(|H| log |H|)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int MM = 2e5+5;

int n, m, cnta[30], cntb[30];
char sa[MM], sb[MM];
set<pair<ll, ll>> st;
ll base = 131, mod = 1685518853;
ll base2 = 131, mod2 = 1494318097;
ll h[MM], p[MM], h2[MM], p2[MM];

void go(int j){
	for(int i = 0; i < 30; i++)
		if(cnta[i] != cntb[i])
			return;
	ll hs = ((h[j] - h[j-n]*p[n])%mod+mod)%mod;
	ll hs2 = ((h2[j] - h2[j-n]*p2[n])%mod2+mod2)%mod2;
	st.insert({hs, hs2});
}

int main(){
	scanf("%s %s", sa+1, sb+1);
	n = strlen(sa+1), m = strlen(sb+1);
	p[0] = p2[0] = 1;
	for(int i = 1; i <= m; i++){
		p[i] = p[i-1]*base%mod;
		h[i] = (h[i-1]*base + sb[i])%mod;
		p2[i] = p2[i-1]*base2%mod2;
		h2[i] = (h2[i-1]*base2 + sb[i])%mod2;
	}
	for(int i = 1; i <= n; i++){
		cnta[sa[i]-'a']++;
		cntb[sb[i]-'a']++;
	}
	go(n);
	for(int i = n+1; i <= m; i++){
		cntb[sb[i]-'a']++;
		cntb[sb[i-n]-'a']--;
		go(i);
	}
	printf("%ld\n", st.size());
}