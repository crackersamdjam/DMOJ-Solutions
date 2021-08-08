#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

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
constexpr int MAXN = 5e5+5, SAMSZ = MAXN*2, BBSTSZ = SAMSZ*2;

//mt19937_64 g(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 g((uint64_t) new char);
mt19937_64 g(224);

#define l T[x].lc
#define r T[x].rc

struct node{
	ll pr = g();
	int val = 0, sz = 0, max = 0;
	int lc = 0, rc = 0, p = 0;
} T[BBSTSZ];

int nx;

void pull(int x){
	if(!x) return;
	// if(l) assert(T[l].p == x);
	// if(r) assert(T[r].p == x);
	T[x].sz = 1 + T[l].sz + T[r].sz;
	T[x].max = max({T[x].val, T[l].max, T[r].max});
}

// ls gets <= k (inclusive)
void split(int x, int k, int &ls, int &rs, int add){
	T[x].p = 0;
	int cur = add + T[l].sz; //current key
	if(!x) ls = rs = 0;
	else if(k <= cur){
		split(l, k, ls, l, add);
		rs = x;
		T[l].p = x;
	}
	else{
		split(r, k, r, rs, add+1+T[l].sz);
		ls = x;
		T[r].p = x;
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
		T[r].p = x;
	}
	else{
		merge(T[rs].lc, ls, T[rs].lc);
		x = rs;
		T[l].p = x;
	}
	pull(x);
}

void out(int x){
	if(!x) return;
	pr("+", x, T[x].p);
	// pr(l, T[l].p);
	// pr(r, T[r].p);
	// pr(".");
	if(l) assert(T[l].p == x);
	if(r) assert(T[r].p == x);
	out(l);
	out(r);
	pr("-", x);
}

int ord(int x, int ch = -1){
	if(!x) return 0;
	return (l != ch)*(T[l].sz+1) + ord(T[x].p, x);
}

#undef l
#undef r

int rt, ls, rs;	
//root of tree(s)
int st[SAMSZ], en[SAMSZ];
//starting and ending nodes of the subtree

void insert2(int ind, int c){
	split(rt, ind, rt, rs, 0);
	merge(rt, rt, c);
	merge(rt, rt, rs);
}

// under a's subtree, insert node b with value r
void insert(int a, int b, int r){
	en[b] = ++nx;
	T[nx].val = r;
	insert2(ord(st[a]), nx);

	st[b] = ++nx;
	T[nx].val = r;
	insert2(ord(st[a]), nx);
}

struct st{
	int len, par;
	map<int, int> ch;
} sa[SAMSZ];
int sz, last;

void init(){
	sa[0].len = 0; //0 is the root of SAM
	sa[0].par = -1;
	sz = 1;
	last = 0;

	merge(rt, rt, st[0] = ++nx);
	merge(rt, rt, en[0] = ++nx);
}

void extend(int c, int r){
	int cur = sz++;
	sa[cur].len = sa[last].len+1;
	int p = last;
	while(p != -1 && !sa[p].ch.count(c)){
		sa[p].ch[c] = cur;
		p = sa[p].par;
	}
	if(p == -1){
		sa[cur].par = 0;
		//insert under root node
		insert(0, cur, r);
	}
	else{
		int o = sa[p].ch[c]; //"other"
		if(sa[p].len+1 == sa[o].len){
			sa[cur].par = o;
			//insert cur right withing o's subtree
			insert(o, cur, r);
		}
		else{
			int clone = sz++; //clone
			sa[clone].ch = sa[o].ch;
			sa[clone].par = sa[o].par;
			sa[clone].len = sa[p].len+1;
			while(p != -1 && sa[p].ch[c] == o){
				//redirect all these to clone
				sa[p].ch[c] = clone;
				p = sa[p].par;
			}
			sa[o].par = sa[cur].par = clone;

			//insert clone "hugging" o
			insert2(ord(st[o])-1, st[clone] = ++nx);
			insert2(ord(en[o]), en[clone] = ++nx);

			//insert cur right within clone's subtree
			insert(clone, cur, r);
		}
	}
	last = cur;
	assert(sz < SAMSZ-5);
	assert(nx < BBSTSZ-5);
}

int n, q, ans;

vector<int> read(){
	int k; scan(k);
	vector<int> v(k);
	for(int &i: v){
		scan(i);
		i ^= ans;
	}
	for(int i = 0; i < k-1; i++)
		v[i] = v[i+1]-v[i];
	v.pop_back();
	return v;
}

int main(){
	init();
	scan(n, q);
	while(n--){
		int r; scan(r);
		auto v = read();
		v.emplace_back((int)1e9);
		for(auto a: v)
			extend(a, r);
	}
	while(q--){
		int op; scan(op);
		if(op == 1){
			int r; scan(r);
			auto v = read();
			v.emplace_back((int)1e9);
			for(auto a: v)
				extend(a, r);
		}
		else{
			auto v = read();
			int cur = 0;

			for(auto i: v){
				if(!sa[cur].ch.count(i)){
					ans = 0;
					goto out;
				}
				cur = sa[cur].ch[i];
			}

			split(rt, ord(en[cur]), rt, rs, 0);
			split(rt, ord(st[cur])-1, ls, rt, 0);
			ans = T[rt].max;
			merge(rt, ls, rt);
			merge(rt, rt, rs);

			out: print(ans);
		}
	}
}