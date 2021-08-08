#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using pii = pair<int, int>;
using piii = pair<pair<int, int>, int>;

constexpr int MM = 5e5+1, NN = 1<<20, inf = 1e7;

#define nm ((nl+nr)/2)
#define lc (rt<<1)
#define rc (rt<<1|1)

#define MINR 1
#define MAXL 2

struct node{
	int minr = inf, maxl = -inf, ans = inf;
} tree[NN*2];

multiset<int> stl[NN], str[NN];

node merge(node l, node r){
	return {min(l.minr, r.minr), max(l.maxl, r.maxl), min(min(l.ans, r.ans), r.minr-l.maxl)};
}

void update(int i, int x, int op, int nl = 0, int nr = NN-1, int rt = 1){
	if(nl == nr){
		if(op == MINR)
			str[i].insert(x);
		else if(op == -MINR)
			str[i].erase(str[i].lower_bound(x));
		else if(op == MAXL)
			stl[i].insert(x);
		else if(op == -MAXL)
			stl[i].erase(stl[i].lower_bound(x));
		else abort();
		tree[rt].minr = size(str[i]) ? *str[i].begin() : inf;
		tree[rt].maxl = size(stl[i]) ? *stl[i].rbegin() : -inf;
		tree[rt].ans = tree[rt].minr-tree[rt].maxl;
		return;
	}
	i <= nm ? update(i, x, op, nl, nm, lc) : update(i, x, op, nm+1, nr, rc);
	tree[rt] = merge(tree[lc], tree[rc]);
}

node query(int l, int r, int nl = 0, int nr = NN-1, int rt = 1){
	if(r < nl or nr < l)
		return tree[0];
	if(l <= nl and nr <= r)
		return tree[rt];
	return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	int q;
	cin>>q;
	while(q--){
		char op;
		int a, b;
		cin>>op>>a>>b;
		if(op == 'A'){
			update(a, b, MINR);
			update(b, a, MAXL);
		}
		else{
			update(a, b, -MINR);
			update(b, a, -MAXL);
		}
	
		int hil = query(0, NN-1).maxl;
		int lor = query(0, NN-1).minr;

		if(hil < lor){
			//get overlap
			int rs = query(hil, hil).minr;
			int ls = query(lor, lor).maxl;
			cout<<rs-ls<<'\n';
		}
		else{
			cout<<tree[1].ans<<'\n';
		}
	}
}