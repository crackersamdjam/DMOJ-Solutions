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
using ll = long long;
using T = pair<ll, int>;
using L = ll;
const int MM = 1e6+5;

struct node{
	T val; L lp;
	inline void apply(const L v){
		val.first += v;
		lp += v;
	}
};

int m, n;

struct segtree{
	node tree[MM*4];
	const T DEF = {LLONG_MAX/2, 0};
	const L DEFL = 0;
	#define LS 1
	#define RS n+1
	
	inline T merge(T va, T vb){
		return min(va, vb);
	}
	
	inline void pull(int rt){
		tree[rt].val = merge(tree[lc].val, tree[rc].val);
	}
	
	inline void push(int rt, int nl, int nr){ // node with lazy val means yet to push to children (but updated itself)
		if(nl == nr or tree[rt].lp == DEFL) return;
		L &val = tree[rt].lp; tree[lc].apply(val); tree[rc].apply(val); val = DEFL;
		pull(rt);
	}
	
	void build(int nl = LS, int nr = RS, int rt = 1){
		tree[rt].val = DEF;
		tree[rt].lp = DEFL;
		if(nl == nr){
			tree[rt].val = {0, nl-1};
			return;
		}
		build(nl, nm, lc); build(nm+1, nr, rc); pull(rt);
	}
	
	void update(int l, int r, L val, int nl = LS, int nr = RS, int rt = 1){
		if(r < nl || l > nr) return;
		if(l <= nl && r >= nr){
			tree[rt].apply(val);
			return;
		}
		push(rt, nl, nr); update(l, r, val, nl, nm, lc); update(l, r, val, nm+1, nr, rc); pull(rt);
	}
	
	T query(int l, int r, int nl = LS, int nr = RS, int rt = 1){
		if(r < nl || l > nr) return DEF;
		if(l <= nl && r >= nr) return tree[rt].val;
		push(rt, nl, nr);
		return merge(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
	}
} ST;

ll a[MM];
string s[MM];
T dp[MM];
deque<int> q;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>m>>n;
	ST.build();
	q.emplace_back(0);
	for(int i = 1; i <= n; i++){
		ll tmp;
		cin>>s[i]>>tmp;
		//q.emplace_back(i); //current one gets updated
		//idk what this line was doing here
		   ST.update(i, i, tmp); //???
		
		while(size(q) > 1 and a[q.back()] <= tmp){
			int r = q.back(); q.pop_back();
			ll dif = tmp-a[r];
			ST.update(q.back()+1, r, dif);
		}
		q.emplace_back(i);
		a[i] = tmp;
		dp[i] = ST.query(max(1, i-m+1), i);
		ST.update(i+1, i+1, dp[i].first);
	}
	cout<<"Total Time: "<<dp[n].first<<'\n';

	vector<int> v;
	int l = n;
	while(l){
		v.emplace_back(l);
		l = dp[l].second;
	}
	
	reverse(all(v));
	l = 1;
	for(auto i: v){
		while(l <= i)
			cout<<s[l++]<<' ';
		cout<<'\n';
	}
}