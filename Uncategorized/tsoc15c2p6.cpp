#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 1e6+5;

#define lc rt<<1
#define rc rt<<1|1
#define nm (nl+nr)/2
#define npm int nl = 1, int nr = n, int rt = 1
#define lpm nl, nm, lc
#define rpm nm+1, nr, rc

ll t[MM*4], lp[MM*4];
int in[MM];
int n, q;

void pull(int rt){
	t[rt] = min(t[lc], t[rc]);
}

void push(int rt){
	t[lc] += lp[rt];
	t[rc] += lp[rt];
	lp[lc] += lp[rt];
	lp[rc] += lp[rt];
	lp[rt] = 0;
}

void build(npm){
	if(nl == nr){
		t[rt] = in[nl];
		return;
	}
	build(lpm);
	build(rpm);
	pull(rt);
}

ll update(int l, int r, int x, npm){
	if(r < nl or nr < l) return 1e9;
	if(l <= nl and nr <= r){
		t[rt] -= x;
		lp[rt] -= x;
		return t[rt];
	}
	push(rt);
	auto ret = min(update(l, r, x, lpm), update(l, r, x, rpm));
	pull(rt);
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	memset(t, 0x3f, sizeof t);
	
	cin>>n>>q;
	for(int i = 1; i <= n; i++)
		cin>>in[i];
	build();
	while(q--){
		int l, r, x;
		cin>>l>>r>>x;
		cout<<max(0LL, update(l, r, x))<<' '<<max(0LL, t[1])<<'\n';
	}
}