#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 5e5+5, LOG = 20, SZ = MM*4, MV = 524287;

#define nm ((nl+nr)/2)
#define lc t[rt].l
#define rc t[rt].r

struct node{
	int l, r, lvl, val, lp;
	bool sz;
	void apply(int v){
		if(sz) val ^= v;
		lp ^= v;
		if(v&(1<<lvl>>1))
			swap(l, r);
	}
} t[SZ];

int ptr, root;

int next(int l, int r, int lvl){
	ptr++;
	t[ptr].l = l;
	t[ptr].r = r;
	t[ptr].lvl = lvl;
	assert(ptr < SZ-5);
	return ptr;
}

void pull(int rt){
	t[rt].val = t[lc].val^t[rc].val;
	t[rt].sz = t[lc].sz^t[rc].sz;
}

void push(int rt){
	if(!t[rt].lvl) return;
	int &v = t[rt].lp;
	if(lc) t[lc].apply(v);
	if(rc) t[rc].apply(v);
	v = 0;
}

void merge(int &a, int b, int lvl){
	if(!a or !b){
		a = a ? a : b;
		return;
	}
	t[a].val ^= t[b].val;
	t[a].sz ^= t[b].sz;
	if(!lvl) return;
	push(a);
	push(b);
	merge(t[a].l, t[b].l, lvl-1);
	merge(t[a].r, t[b].r, lvl-1);
}

void attach(int l, int r, int b, int nl, int nr, int &rt){
	if(l > nr or r < nl) return;
	if(l <= nl and r >= nr){
		merge(rt, b, t[rt].lvl);
		return;
	}
	if(!rt) rt = next(0, 0, __lg(nr-nl+1));
	push(rt); attach(l, r, b, nl, nm, lc); attach(l, r, b, nm+1, nr, rc); pull(rt);
}

vector<array<int, 3>> ops;

void update(int l, int r, int v, int nl, int nr, int &rt){
	if(!rt or l > nr or r < nl) return;
	if(l <= nl and r >= nr){
		t[rt].apply(v);
		int vv = (v>>t[rt].lvl)<<t[rt].lvl;
		ops.push_back({nl^vv, nr^vv, rt});
		rt = 0;
		return;
	}
	push(rt); update(l, r, v, nl, nm, lc); update(l, r, v, nm+1, nr, rc); pull(rt);
}

void add(int i, int v, int nl, int nr, int &rt){
	if(i > nr or i < nl) return;
	if(!rt) rt = next(0, 0, __lg(nr-nl+1));
	if(nl == nr){
		t[rt].val ^= v;
		t[rt].sz ^= 1;
		return;
	}
	push(rt); add(i, v, nl, nm, lc); add(i, v, nm+1, nr, rc); pull(rt);
}

int query(int l, int r, int nl, int nr, int rt){
	if(!rt or l > nr or r < nl) return 0;
	if(l <= nl and r >= nr) return t[rt].val;
	push(rt); return query(l, r, nl, nm, lc)^query(l, r, nm+1, nr, rc);
}

int n, q;

int main(){
	#ifndef LOCAL
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#endif

	cin>>n>>q;

	while(n--){
		int x; cin>>x;
		add(x, x, 0, MV, root);
	}

	while(q--){
		int op, l, r, x;
		cin>>op;
		if(op == 1){
			cin>>x;
			add(x, x, 0, MV, root);
		}
		else if(op == 2){
			cin>>l>>r>>x;
			update(l, r, x, 0, MV, root);
			for(auto &&i: ops){
				attach(i[0], i[1], i[2], 0, MV, root);
			}
			ops.clear();
		}
		else if(op == 3){
			cin>>l>>r;
			cout<<query(l, r, 0, MV, root)<<'\n';
		}
		else abort();
	}
}