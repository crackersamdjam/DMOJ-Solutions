#include <bits/stdc++.h>
#define size(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 6e5+5;

mt19937_64 g(0);

struct node{
	int key = 0, sz = 0, l = 0, r = 0;
	ll pr = g();
} t[MM];

#define lc t[x].l
#define rc t[x].r

int ptr;

int next(int v){
	t[++ptr].key = v;
	return ptr;
}

void pull(int x){
	if(!x) return;
	t[x].sz = t[lc].sz + t[rc].sz + 1;
}

// >= key -> rs
void split(int x, int key, int &l, int &r){
	if(!x) l = r = 0;
	else if(t[x].key >= key){
		split(lc, key, l, lc);
		r = x;
	}
	else{
		split(rc, key, rc, r);
		l = x;
	}
	pull(x);
}

void merge(int &x, int l, int r){
	if(!l or !r)
		x = l ? l : r;
	else if(t[l].pr > t[r].pr){
		merge(t[l].r, t[l].r, r);
		x = l;
	}
	else{
		merge(t[r].l, l, t[r].l);
		x = r;
	}
	pull(x);
}

int kth(int x, int k){
	if(k < t[lc].sz)
		return kth(lc, k);
	k -= t[lc].sz;
	
	if(!k) return t[x].key;
	k--;
	return kth(rc, k);
}

int ord(int x, int k, int i = 1){
	if(!x) return 1e9;
	if(t[x].key < k)
		return ord(rc, k, i+t[lc].sz+1);

	int ret = ord(lc, k, i);
	if(t[x].key == k)
		ret = min(ret, t[lc].sz+i);
	return ret;
}

void out(int x){
	if(!x) return;
	out(lc);
	cout<<t[x].key<<' ';
	out(rc);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	int n, q;
	cin>>n>>q;
	int rt = 0, t1, t2, last = 0;

	while(n--){
		int x; cin>>x;
		split(rt, x, rt, t1);
		merge(rt, rt, next(x));
		merge(rt, rt, t1);
	}

	while(q--){
		char c; int x;
		cin>>c>>x;
		x ^= last;
		if(c == 'I'){
			split(rt, x, rt, t1);
			merge(rt, rt, next(x));
			merge(rt, rt, t1);
		}
		else if(c == 'R'){
			split(rt, x+1, rt, t1);
			split(rt, x, rt, t2);
			merge(t2, t[t2].l, t[t2].r);
			merge(rt, rt, t2);
			merge(rt, rt, t1);
		}
		else if(c == 'S'){
			cout<<(last=kth(rt, x-1))<<'\n';
		}
		else if(c == 'L'){
			int v = ord(rt, x);
			if(v >= 1e9) v = -1;
			cout<<(last=v)<<'\n';
		}
		else abort();
	}
	out(rt);
}