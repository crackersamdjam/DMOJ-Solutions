#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 5e5+5, MV = 5e5+2;

struct Bit{
	ll bit[MM];
	Bit(){
		memset(bit, -0x3f, sizeof bit);
	}
	void up(int i, ll x){
		for(; i < MM; i += i&-i)
			bit[i] = max(bit[i], x);
	}
	ll qu(int i){
		ll x = bit[0];
		for(; i; i -= i&-i)
			x = max(x, bit[i]);
		return x;
	}
} TL, TR;

int n, u, d, s;
vector<pair<int, int>> v[MM];
ll tmpl[MM], tmpr[MM];

void add(int i, ll x){
	TL.up(i, x+d*i);
	TR.up(MV-i, x+u*(MV-i));
}

ll get(int i){
	ll vl = TL.qu(i)-d*i;
	ll vr = TR.qu(MV-i)-u*(MV-i);
	return max(vl, vr);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>u>>d>>s;
	while(n--){
		int t, l, m;
		cin>>t>>l>>m;
		v[t].emplace_back(l, m);
	}
	add(s, 0);

	for(int i = 1; i < MM; i++){
		sort(all(v[i]));
		int m = size(v[i]);
		for(int j = 0; j < m; j++){
			tmpl[j] = get(v[i][j].first) + v[i][j].second;
			if(j) tmpl[j] = max(tmpl[j], tmpl[j-1] + v[i][j].second - d*(v[i][j].first-v[i][j-1].first));
		}
		for(int j = m-1; j >= 0; j--){
			tmpr[j] = get(v[i][j].first) + v[i][j].second;
			if(j < m-1) tmpr[j] = max(tmpr[j], tmpr[j+1] + v[i][j].second - u*(v[i][j+1].first-v[i][j].first));
		}
		for(int j = 0; j < m; j++){
			add(v[i][j].first, max(tmpl[j], tmpr[j]));
		}
	}
	cout<<get(s)<<'\n';
}
/*
template two segtrees
but for those on same day... loop once in order l->r, then undo and try r->l

*/