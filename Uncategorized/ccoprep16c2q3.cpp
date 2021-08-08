#include <bits/stdc++.h>
using namespace std;
using T = int;
const int MM = 2e5+5;

struct LinkCut {
	struct node{
		int p, ch[2], pp, sz = 1;
		bool flip;
	} T[MM];
	
	LinkCut(){
		T[0].sz = 0;
	}
	
	bool dir(int x, int y){ //which ch[?] y is of x
		return T[x].ch[1] == y;
	}
	
	void set(int x, int d, int y){ //set x's ch[d] to y and y's par to x
		if(x) T[x].ch[d] = y, pull(x);
		if(y) T[y].p = x;
	}
	
	void pull(int x){
		if(!x) return;
		int l = T[x].ch[0], r = T[x].ch[1];
		push(l), push(r);
		T[x].sz = T[l].sz + T[r].sz + 1;
	}
	
	void push(int x){
		if(!x) return;
		int &l = T[x].ch[0], &r = T[x].ch[1];
		
		if(T[x].flip){
			swap(l, r);
			T[l].flip ^= 1; T[r].flip ^= 1;
			T[x].flip = 0;
		}
	}
	
	void rotate(int x, int d){ // 0 left, 1 right
		int y = T[x].p, z = T[y].p, w = T[x].ch[d];
		swap(T[x].pp, T[y].pp);
		set(y, !d, w);
		set(x, d, y);
		set(z, dir(z, y), x);
	}
	
	void splay(int x){
		for(push(x); T[x].p;){
			int y = T[x].p, z = T[y].p;
			push(z); push(y); push(x);
			int dx = dir(y, x), dy = dir(z, y);
			if(!z)
				rotate(x, !dx);
			else if(dx == dy)
				rotate(y, !dx), rotate(x, !dx); // zig zag
			else
				rotate(x, dy), rotate(x, dx); // zig zig
		}
		push(x); pull(x);
	}
	
	void makeroot(int u){
		access(u);
		int l = T[u].ch[0];
		T[l].flip ^= 1;
		swap(T[l].p, T[l].pp);
		set(u, 0, 0);
	}
	
	int access(int _u){
		int v, u;
		for(v = 0, u = _u; u; u = T[v = u].pp){ // jump both up (u is pp of v)
			splay(u); splay(v);
			//remove u's prefered child (r), change to v if it exists
			int r = T[u].ch[1];
			T[v].pp = 0;
			swap(T[r].p, T[r].pp);
			set(u, 1, v);
		}
		splay(_u);
		return v; // last node that pp jumped to (for lca)
	}
	
	void link(int u, int v){ // make v's parent u
		makeroot(v);
		T[v].pp = u;
	}
	
	void cut(int u, int v){
		makeroot(u); access(u); splay(v);
		// assert(T[v].pp == u);
		T[v].pp = 0;
	}
	
	bool connected(int u, int v){
		if(u == v) return 1;
		makeroot(u); access(v); splay(u);
		return T[v].p == u || T[T[v].p].p == u;
	}
	
	node query(int u, int v){
		makeroot(u); access(v);
		//now v is at top of ALL and only nodes in the splay are on path root(u) -> v
		//so it becomes subtree sum
		return T[v];
	}
	
	// void update(int v, int w, bool op, ll x){
	// 	makeroot(w), access(v);
	// 	if(op == 0){
	// 		T[v].lp += x;
	// 	}
	// 	else{
	// 		T[v].lp = 0;
	// 		T[v].fix = 1;
	// 		T[v].fixv = x;
	// 	}
	// }
	
	int findroot(int u){
		access(u);
		while(T[u].ch[0])
			u = T[u].ch[0];
		splay(u);
		return u;
	}
	
	int lca(int v, int w){
		access(v);
		return access(w);
		//v already on preferred path
		//returning last time w had to jump to join preferred path (with v)
	}
	
	void wtf(int x, int y){
		//change x's par to y, unless y is in x's subtree
		if(lca(x, y) == x) return;
		access(x);
		cut(x, T[x].ch[0]);
		link(x, y);
	}
} LCT;

int n, q, a[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
		LCT.link(i, min(n+1, i+a[i]));
	}
	cin>>q;
	int op, i;
	while(q--){
		cin>>op>>i;
		i++; //zero indexed
		if(op == 1){
			cout<<LCT.query(i, n+1).sz-1<<'\n';
		}
		else{
			LCT.cut(i, min(n+1, i+a[i]));
			cin>>a[i];
			LCT.link(i, min(n+1, i+a[i]));
		}
	}
}