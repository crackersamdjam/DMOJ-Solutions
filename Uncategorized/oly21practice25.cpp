#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 3e5+5;

//mt19937_64 g(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 g((uint64_t) new char);
mt19937_64 g(224);

#define l T[x].lc
#define r T[x].rc

struct node{
	unsigned long long pr = g();
	ll val = 0;
	int sz = 0;
	int lc = 0, rc = 0;
} T[MM*3];

void pull(int x){
	if(!x) return;
	T[x].sz = 1 + T[l].sz + T[r].sz;
}

void split(int x, int k, int &ls, int &rs, int add){
	int cur = add + T[l].sz; //current key
	if(!x) ls = rs = 0;
	else if(k <= cur){
		split(l, k, ls, l, add);
		rs = x;
	}
	else{
		split(r, k, r, rs, add+1+T[l].sz);
		ls = x;
	}
	pull(x);
}

// >= key goes to rs
void split(int x, int key, int &ls, int &rs){
	if(!x) ls = rs = 0;
	else if(T[x].val >= key){
		split(l, key, ls, l);
		rs = x;
	}
	else{
		split(r, key, r, rs);
		ls = x;
	}
	pull(x);
}

void merge(int &x, int ls, int rs){
	if(!x) x = ls ? ls : rs;
	if(!ls || !rs)
		x = ls ? ls : rs;
	else if(T[ls].pr > T[rs].pr){
		merge(T[ls].rc, T[ls].rc, rs);
		x = ls;
	}
	else{
		merge(T[rs].lc, ls, T[rs].lc);
		x = rs;
	}
	pull(x);
}

ll kth(int x, int k, int lo){
	if(!x) return k;
	int v = T[x].val-1-lo-T[l].sz;
	//how many not taken in left side
	if(k <= v)
		return kth(l, k, lo);
	return T[x].val-lo+kth(r, k-v, T[x].val);
}

void out(int x){
	if(!x) return;
	out(l);
	cout << T[x].val << ' ';
	out(r);
}

#undef l
#undef r

ll n, m, qq;
ll rem[MM];
deque<ll> q[MM];
int last, mid, rs;
int in[MM], ptr, d[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m>>qq;
	for(int i = 1; i <= n; i++){
		rem[i] = m-1;
		T[i].val = i*m;
		merge(last, last, i);
	}
	ptr = n;

	while(qq--){
		int r, c; cin>>r>>c;

		split(last, r-1, last, mid, 0);
		split(mid, 1, mid, rs, 0);
		merge(last, last, rs);
		merge(in[r], in[r], mid);

		if(c <= rem[r]){
			ll bl = kth(d[r], c, 0);
			// now add it
			split(d[r], bl, d[r], rs);
			T[++ptr].val = bl;
			merge(d[r], d[r], ptr);
			merge(d[r], d[r], rs);

			ll v = (r-1)*m+bl;
			cout<<v<<'\n';

			T[++ptr].val = v;
			merge(last, last, ptr);

			rem[r]--;
			//ptr++ and add to last
		}
		else{
			c -= rem[r];
			//get from bbst
			split(in[r], c-1, in[r], mid, 0);
			split(mid, 1, mid, rs, 0);
			merge(in[r], in[r], rs);
			ll v = T[mid].val;
			cout<<v<<'\n';
			merge(last, last, mid);
		}
	}
}