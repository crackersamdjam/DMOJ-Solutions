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

typedef long long ll;
constexpr int MM = 1e6+1;

std::mt19937 g(0);

struct node{
	ll val, lp, sum;
	int lc, rc, sz, pr;
	bool fix ;
} T[MM];
#define l T[x].lc
#define r T[x].rc

inline void push(int x){
	if(!x) return;
	if(T[x].fix){
		T[x].val = T[x].lp;
		T[x].sum = T[x].sz*T[x].lp;
		
		T[l].lp = T[r].lp = T[x].lp;
		T[l].fix = T[r].fix = 1;
		T[x].lp = 0;
		T[x].fix = 0;
	}
	else{
		T[x].val += T[x].lp;
		T[x].sum += T[x].lp*T[x].sz;
		
		T[l].lp += T[x].lp;
		T[r].lp += T[x].lp;
		T[x].lp = 0;
	}
}

inline void pull(int x){
	if(!x) return;
	push(l), push(r);
	T[x].sz = T[l].sz + T[r].sz + 1;
	T[x].sum = T[x].val + T[l].sum + T[r].sum;
}

void split(int x, int &ls, int &rs, ll k){
	push(x);
	if(!x) ls = rs = 0;
	else if(k <= T[l].sz){
		split(l, ls, l, k);
		rs = x;
	}
	else{
		split(r, r, rs, k-T[l].sz-1);
		ls = x;
	}
	pull(x);
}

void splitkey(int x, int &ls, int &rs, ll key){
	push(x);
	if(!x) ls = rs = 0;
	else if(key <= T[x].val){
		splitkey(l, ls, l, key);
		rs = x;
	}
	else{
		splitkey(r, r, rs, key);
		ls = x;
	}
	pull(x);
}

void merge(int &x, int ls, int rs){
	push(ls), push(rs);
	if(!x) x = ls ? ls : rs;
	if(!ls or !rs)
		x = ls?ls:rs;
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

int n, a, rt, ls, rs;
ll k, ans;

int main(){
	scan(n, k);
	for(int i = 1; i <= n; i++){
		scan(a);
		
		split(rt, ls, rs, a-1);
		ll rem = k - T[ls].sum;
		
		if(rem < 0){
			print(ans = -1);
			merge(rt, ls, rs);
		}
		else{
			print(ans = rem);
			T[ls].lp++;
			
			T[rs].lp = 1;
			T[rs].fix = 1;
			//rs -1s will turn into 1 because they will not get overboard, so want at least 1 coin next time
			merge(rt, rs, ls);
		}

		T[i].pr = g();
		T[i].val = T[i].sum = ans+1;
		T[i].sz = 1;
		
		//split by value and insert ans+1
		splitkey(rt, ls, rs, ans+1);
		
		merge(ls, ls, i);
		merge(rt, ls, rs);
	}
}
/*
say with i-1, we know how many coins each gets
now the new pirate needs to buy off the cheapest k-1 onto his side
he needs to pay each of them 1 more than they would otherwise get
(for the pirate that get -1, they take nothing to buy)

now, for the pirates that i does not buy, they will cost the next pirate 1 to buy over
so their cost gets reset to 1

bbst is used for range insert of newest ans, and range update of k-1 minimum

*/