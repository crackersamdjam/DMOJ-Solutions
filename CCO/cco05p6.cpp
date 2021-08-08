#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

using namespace std;
const int MM = 1e4+5, NN = 1e7+4e6, KK = 5e4+5;

int n, m, k, q, last[KK];
//last time accessed

struct node{
	int val = 0, lp = 0, lcp = 0, rcp = 0;
	void push(int nl, int nr);
	int query(int nl, int nr, int h);
	void update(int nl, int nr, int l, int r, int v);
	void apply(int v){
		val = lp = v;
	}
} nodes[NN];
int ptr = 1;

void node::push(int nl, int nr){
	if(nl != nr && !lcp){
		lcp = ++ptr;
		rcp = ++ptr;
	}
	if(lp and nl != nr){
		nodes[lcp].apply(lp);
		nodes[rcp].apply(lp);
		lp = 0;
	}
}

int node::query(int nl, int nr, int i){
	if(nl == nr)
		return val;
	push(nl, nr);
	if(i <= nm)
		return nodes[lcp].query(nl, nm, i);
	return nodes[rcp].query(nm+1, nr, i);
}

void node::update(int nl, int nr, int v, int l, int r){
	if(r < nl or nr < l)
		return;
	if(l <= nl and nr <= r){
		apply(v);
		return;
	}
	push(nl, nr);
	nodes[lcp].update(nl, nm, v, l, r);
	nodes[rcp].update(nm+1, nr, v, l, r);
}

struct nnode{
	int id = 0;
} tree[MM*4];

void update(int l, int r, int v, int ll, int lr, int nl, int nr, int rt){
	if(r < nl || l > nr) return;
	if(l <= nl && r >= nr){
		if(!tree[rt].id)
			tree[rt].id = ++ptr;
		nodes[tree[rt].id].update(1, m, v, ll, lr);
		return;
	}
	update(l, r, v, ll, lr, nl, nm, lc);
	update(l, r, v, ll, lr, nm+1, nr, rc);
}

int merge(int a, int b){
	return last[a] > last[b] ? a : b;
}

int query(int i, int j, int nl, int nr, int rt){
	if(i < nl || i > nr) return 0;
	int vv = tree[rt].id ? nodes[tree[rt].id].query(1, m, j) : 0;
	if(nl == nr)
		return vv;
	return merge(vv, merge(query(i, j, nl, nm, lc), query(i, j, nm+1, nr, rc)));
}

int lx[KK], ly[KK], rx[KK], ry[KK];

int main(){
	scan(n, m, k);
	for(int i = 1; i <= k; i++){
		scan(lx[i], ry[i], rx[i], ly[i]);
		int id = i;
		last[id] = i;
		update(lx[id], rx[id], id, ly[id], ry[id], 1, n, 1);
	}
	scan(q);
	for(int i = k+1,x,y; i <= k+q; i++){
		scan(x, y);
		int id = query(x, y, 1, n, 1);
		print(id);
		if(id){
			last[id] = i;
			update(lx[id], rx[id], id, ly[id], ry[id], 1, n, 1);
		}
	}
}
/*
for outer segtree, instead of propagating, get max along way (like li chao)
*/