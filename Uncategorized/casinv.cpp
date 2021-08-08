#include <bits/stdc++.h>

typedef long long ll;
const int MM = 1e6+2;

int n, a[MM], b[MM], ma, mb, cnta[MM], cntb[MM];
ll ans;

int main(int argc, char *argv[]){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", a+i);
		cnta[a[i]]++;
		ma = std::max(ma, a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", b+i);
		cntb[b[i]]++;
		mb = std::max(mb, b[i]);
	}
	if(ma != mb)
		return !printf("-1\n");

	for(int i = MM-2; i; i--)
		cnta[i] += cnta[i+1], cntb[i] += cntb[i+1];

	for(int i = 0; i < n; i++){
		ans += (ll)a[i]*cntb[a[i]+1] + (ll)b[i]*cnta[b[i]];
	}

	return !printf("%lld\n", ans);
}