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
const ll mod = 1e9+7;
const int MM = 5e5+5;

struct stt{
	ll v; bool m;
	bool operator<(const stt &o) const{
		if(m or o.m) return o.m;
		return v < o.v;
	}
	stt operator*(const stt &o) const{
		return {v*o.v%mod, v*o.v >= mod or m or o.m};
	}
};

struct node{
	stt l, r;
	stt y;
} t[MM*4];

int n, x[MM], y[MM];

#define nm ((nl+nr)/2)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define npm int nl = 0, int nr = n-1, int rt = 1
#define lpm nl, nm, lc
#define rpm nm+1, nr, rc

void pull(int rt){
	if(t[lc].y < t[lc].r*t[rc].l*t[rc].y){
		t[rt].y = t[rc].y;
		t[rt].l = t[lc].l*t[lc].r*t[rc].l;
		t[rt].r = t[rc].r;
	}
	else{
		t[rt].y = t[lc].y;
		t[rt].l = t[lc].l;
		t[rt].r = t[lc].r*t[rc].l*t[rc].r;
	}
}

void build(npm){
	if(nl == nr){
		t[rt].y = {y[nl], 0};
		t[rt].l = {x[nl], 0};
		t[rt].r = {1, 0};
		return;
	}
	build(lpm); build(rpm);
	pull(rt);
}

void update(int i, npm){
	if(nl == nr){
		assert(nl == i);
		t[rt].y = {y[nl], 0};
		t[rt].l = {x[nl], 0};
		t[rt].r = {1, 0};
		return;
	}
	i <= nm ? update(i, lpm) : update(i, rpm);
	pull(rt);
}

int query(){
	return (t[1].l*t[1].y).v;
}

int init(int _n, int _x[], int _y[]){
	n = _n;
	for(int i = 0; i < n; i++){
		x[i] = _x[i], y[i] = _y[i];
	}
	build();
	return query();
}

int updateX(int i, int v){
	x[i] = v;
	update(i);
	return query();
}

int updateY(int i, int v){
	y[i] = v;
	update(i);
	return query();
}

int _n, _x[MM], _y[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>_n;
	for(int i = 0; i < _n; i++)
		cin>>_x[i];
	for(int i = 0; i < _n; i++)
		cin>>_y[i];
	init(_n, _x, _y);
	cout<<query()<<'\n';
	int q; cin>>q;
	while(q--){
		int op, i, v;
		cin>>op>>i>>v;
		op == 1 ? updateX(i, v) : updateY(i, v);
		cout<<query()<<'\n';
	}
}