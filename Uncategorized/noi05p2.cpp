#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using std::max;
typedef long long ll;
constexpr int MM = 5e5+5;

std::mt19937 g1(time(0));

#define l T[x].lc
#define r T[x].rc
struct node{
	int pr, sz;
	ll val, max, lv, rv, sum, lp;
	int lc, rc;
	bool flip, up;
	void clear(){
		pr = g1(), sz = 0;
		val = 0, max = 0, lv = 0, rv = 0, sum = 0, lp = 0;
		lc = 0, rc = 0;
		flip = 0, up = 0;
	}
} T[MM];

inline void push(int x){
	if(!x) return;
	if(T[x].flip){
		std::swap(T[x].lv, T[x].rv);
		std::swap(l, r);
		T[l].flip ^= 1;
		T[r].flip ^= 1;
		T[x].flip = 0;
	}
	if(T[x].up){
		T[x].val = T[x].lp;
		T[x].sum = T[x].sz*T[x].lp;
		T[x].lv = T[x].rv = T[x].max = max(T[x].sum, T[x].val); //nonempty at least one
		
		T[l].lp = T[r].lp = T[x].lp;
		T[l].up = T[r].up = 1;
		T[x].up = 0;
	}
}

inline void pull(int x){
	if(!x) return;
	push(l);
	push(r);
	T[x].sz = 1 + T[l].sz + T[r].sz;
	T[x].sum = T[x].val + T[l].sum + T[r].sum;
	
	T[x].lv = max(T[l].lv, T[l].sum + T[x].val + max(T[r].lv, 0LL));
	T[x].rv = max(T[r].rv, T[r].sum + T[x].val + max(T[l].rv, 0LL));
	
	T[x].max = max({T[x].sum, T[x].lv, T[x].rv, max(T[l].rv, 0LL) + T[x].val + max(T[r].lv, 0LL), T[l].max, T[r].max});
}

void split(int x, int k, int &ls, int &rs, int add){
	push(x);
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

void merge(int &x, int ls, int rs){
	push(ls); push(rs);
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

int n, q, rt, mid, rs, ids[MM], ptr;

void wipe(int x){
	if(!x) return;
	wipe(l);
	wipe(r);
	ids[ptr++] = x;
}

inline int next(ll v){
	int i = ids[--ptr];
	T[i].clear();
	T[i].val = v;
	return i;
}

void out(int x){
	if(!x) return;
	push(x);
	out(l);
	print(T[x].val);
	out(r);
}

int main(){
	T[0].max = LLONG_MIN/3;
	T[0].lv = LLONG_MIN/3;
	T[0].rv = LLONG_MIN/3;
	for(ptr = 0; ptr < MM; ptr++)
		ids[ptr] = ptr;
	
	scan(n, q);
	ll c;
	for(int i = 1; i <= n; i++){
		scan(c);
		merge(rt, rt, next(c));
	}
	int tot, a, b;
	char op0, op1, op2;
	while(q--){
		op0 = gc, op1 = gc, op2 = gc;
		
		if(op2 == 'X'){
			gc;gc;gc;gc;gc;
			push(rt);
			pull(rt);
			print(T[rt].max);
			continue;
		}
		
		if(op0 == 'I'){
			gc;gc;gc;gc;
			scan(a, tot);
			split(rt, a, rt, rs, 0);
			int tmp = 0;
			while(tot--){
				scan(c);
				merge(tmp, tmp, next(c));
			}
			merge(rt, rt, tmp);
			merge(rt, rt, rs);
		}
		else if(op0 == 'D'){
			gc;gc;gc;gc;
			scan(a, tot);
			b = a+tot-1;
			split(rt, b, rt, rs, 0);
			split(rt, a-1, rt, mid, 0);
			wipe(mid);
			merge(rt, rt, rs);
		}
		else if(op0 == 'M'){
			gc;gc;gc;gc;gc;gc;
			scan(a, tot);
			b = a+tot-1;
			scan(c);
			split(rt, b, rt, rs, 0);
			split(rt, a-1, rt, mid, 0);
			if(mid){
				T[mid].lp = c;
				T[mid].up = 1;
				push(mid);
			}
			merge(mid, mid, rs);
			merge(rt, rt, mid);
		}
		else if(op0 == 'R'){
			gc;gc;gc;gc;
			scan(a, tot);
			b = a+tot-1;
			split(rt, b, rt, rs, 0);
			split(rt, a-1, rt, mid, 0);
			if(mid){
				T[mid].flip ^= 1;
				push(mid);
			}
			merge(mid, mid, rs);
			merge(rt, rt, mid);
		}
		else if(op0 == 'G'){
			gc;gc;gc;gc;gc;
			scan(a, tot);
			b = a+tot-1;
			split(rt, b, rt, rs, 0);
			split(rt, a-1, rt, mid, 0);
			push(mid);
			pull(mid);
			print(T[mid].sum);
			merge(mid, mid, rs);
			merge(rt, rt, mid);
		}
		else abort();
	}
	
	return 0;
}