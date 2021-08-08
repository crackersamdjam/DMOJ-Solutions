#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define f first
#define s second

using namespace std;
typedef double ld;
constexpr int MM = 1e5+1;
constexpr ld eps = 1e-9;

inline ld inter(pair<ld, ld> a, pair<ld, ld> b){
	return (b.s-a.s)/(a.f-b.f);
	// x = (b2-b1)/(m1-m2)
}

int n;
deque<pair<ld, ld>> q;
bool ok[MM];

struct st{
	int op, id, l, r;
	ld a, b;
	bool operator<(const st &o) const{
		if(op != o.op)
			return op < o.op;
		if(abs(this->a - o.a) < eps)
			return b > o.b;
		return a < o.a;
	}
};

void go(int l, int r, vector<st> &v){
	if(l > r or v.empty())
		return;
	int m = (l+r)/2;
	vector<st> vl, vr;
	for(auto &i: v){
		if(i.op == 0){
			if(i.l <= l and r <= i.r){
				if(q.size() and q.back().s == i.b)
					continue;
				while(q.size() >= 2 and inter(q[q.size()-2], q.back()) >= eps+inter(q.back(), {i.a, i.b}))
					q.pop_back();
				q.emplace_back(i.a, i.b);
			}
			else{
				if(i.l <= m)
					vl.push_back(i);
				if(i.r > m)
					vr.push_back(i);
			}
		}
	}
	for(auto &i: v){
		if(i.op == 2){
			if(q.size() and i.op == 2){
				while(q.size() >= 2 and inter(q[0], q[1])+eps < i.a)
					q.pop_front();
				ld res = q[0].f*i.a + q[0].s;
				if(i.b < res-eps)
					ok[i.id] = 0;
			}
			if(i.l <= m)
				vl.push_back(i);
			else
				vr.push_back(i);
		}
	}
	q.clear();

	if(l == r)
		return;
	go(l, m, vl);
	go(m+1, r, vr);
}

int op[MM], id[MM], l[MM], r[MM];
ld a[MM], b[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>op[i];
		if(op[i] == 0){
			cin>>a[i]>>b[i]>>id[i];
			// assert(!l[id[i]]);
			l[id[i]] = i;
		}
		else if(op[i] == 1){
			cin>>id[i];
			r[id[i]] = i;
		}
		else{
			cin>>a[i]>>b[i];
			ok[i] = 1;
		}
	}
	vector<st> v;
	for(int i = 1; i <= n; i++){
		if(!r[i])
			r[i] = n;
	}

	for(int i = 1; i <= n; i++){
		if(op[i] == 0){
			v.push_back({op[i], 0, l[id[i]], r[id[i]], -a[i]/b[i], 1/b[i]});
		}
		else if(op[i] == 2){
			v.push_back({op[i], i, i, i, a[i], b[i]});
		}
	}

	sort(all(v));
	go(1, n, v);

	for(int i = 1; i <= n; i++){
		if(op[i] == 2)
			print(ok[i]);
	}
}
/*
sort for lines before queries, lines by lowest slope, queries by lowest a[i]
each cdq interval build convex hull
loop with ptr in hull and ptr of queries in range
*/