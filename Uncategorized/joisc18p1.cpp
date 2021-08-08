#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e5+5;

ll ans;
int n, c[MM], bit[MM], lz[MM], t, x;
map<int, int> mp;

void bitupdate(int i, int v){
	for(; i < MM; i += i&-i){
		if(lz[i] < t)
			bit[i] = 0, lz[i] = t;
		bit[i] += v;
	}
}

int bitquery(int i){
	int ret = 0;
	for(; i; i -= i&-i){
		if(lz[i] < t)
			bit[i] = 0, lz[i] = t;
		ret += bit[i];
	}
	return ret;
}

struct linkcut{
	struct node{
		int p = 0, ch[2] = {0, 0}, pp = 0, sz = 1;
		bool flip = 0;
		int val = 0, lp = 0;
	} T[MM];

	linkcut(){
		T[0].sz = 0;
	}

	int dir(int x, int y){ //which ch[?] y is of x
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
		
		if(T[x].lp){
			T[x].val = T[x].lp;
			T[l].lp = T[r].lp = T[x].lp;
			T[x].lp = 0;
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
			swap(T[r].p, T[r].pp);

			set(u, 1, 0);
			ans += (ll)T[u].sz*bitquery(T[u].val-1);
			bitupdate(T[u].val, T[u].sz);

			T[v].pp = 0;
			set(u, 1, v);
		}
		splay(_u);
		return v; // last node that pp jumped to (for lca)
	}

	void link(int u, int v){ // make v's parent u
		makeroot(v);
		T[v].pp = u;
	}

	void update(int v, int w, int x){
		makeroot(w), access(v);
		T[v].lp = x;
	}
} T;

int main(){
	scan(n);
	for(int i = 1; i <= n; i++){
		scan(c[i]);
		mp[c[i]] = 0;
	}
	for(auto &i: mp)
		i.second = ++x;

	for(int i = 1; i <= n; i++){
		T.T[i].val = c[i] = mp[c[i]];
	}
	
	for(int i = 0,a,b; i < n-1; i++){
		scan(a, b);
		ans = 0; t++;
		T.access(a);
		print(ans);
		T.T[a].lp = c[b];
		T.link(a, b);
		// T.update(b, 1, c[b]);
	}
}