#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 1e5+5;
const ll inf = 1e15;

#define lc rt<<1
#define rc rt<<1|1
#define nm ((nl+nr)/2)
#define npm int nl = 0, int nr = MM-2, int rt = 1
#define lpm nl, nm, lc
#define rpm nm+1, nr, rc

struct stt{
	ll n, c;
} tree[MM*4*8];

// make sure they're distinct after cordcomp, so I can get each indiv cost
// I guess I don't need to

stt merge(stt va, stt vb){
	return {va.n+vb.n, va.c+vb.c};
}

void pull(int rt){
	tree[rt] = merge(tree[lc], tree[rc]);
}

void update(int i, stt x, npm){
	if(nl == nr){
		tree[rt] = merge(tree[rt], x);
		return;
	}
	i <= nm ? update(i, x, lpm) : update(i, x, rpm);
	pull(rt);
}

// cost to get k candies
ll kth(ll k, npm){
	if(k > tree[rt].n)
		return inf;
	
	if(nl == nr){
		ll each = tree[rt].c/tree[rt].n;
		return each*k;
	}
	if(k > tree[lc].n){
		k -= tree[lc].n;
		return tree[lc].c + kth(k, rpm);
	}
	return kth(k, lpm);
}

#undef lc
#undef rc
#undef nm
#undef npm
#undef lpm
#undef rpm

struct query{
	ll ava, num;
	int id;
};

struct candy{
	int val; ll cost, num;
};

int n, q;
int ans[MM];
vector<candy> vc;

void go(int l, int r, vector<query> v){
	if(l > r or v.empty()) return;
	int m = l+r>>1;
	for(int i = m; i <= r; i++){
		update((int)vc[i].cost, {vc[i].num, vc[i].cost*vc[i].num});
	}
	
	vector<query> ls, rs;
	for(auto i: v){
		ll res = kth(i.num);
		if(res <= i.ava){
			ans[i.id] = max(ans[i.id], vc[m].val);
			rs.push_back(i);
		}
		else{
			ls.push_back(i);
		}
	}
	
	go(l, m-1, ls);
	for(int i = m; i <= r; i++)
		update((int)vc[i].cost, {-vc[i].num, -vc[i].cost*vc[i].num});
	go(m+1, r, rs);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	memset(ans, -1, sizeof ans);
	cin>>n>>q;
	vc.push_back({-1, 0, (ll)1e15});
	
	for(int i = 0,a,b,c; i < n; i++){
		cin>>a>>b>>c;
		vc.push_back({a, b, c});
	}
	
	vector<query> vq;
	for(int i = 0; i < q; i++){
		ll a, b;
		cin>>a>>b;
		vq.push_back({a, b, i});
	}
	
	sort(all(vc), [](auto x, auto y){
		return x.val < y.val;
	});
	
	go(0, size(vc)-1, vq);
	
	for(int i = 0; i < q; i++)
		cout<<ans[i]<<'\n';
}