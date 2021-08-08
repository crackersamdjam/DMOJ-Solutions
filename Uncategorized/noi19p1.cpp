#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using ld = double;
using pii = pair<ll, ll>;
const int MM = 2e5+5;

#define sq(x) (x)*(x)

int n, m;
ll A, B, C, ans = LLONG_MAX;
struct st{
	ll a, b, c, d;
	bool operator<(const st &o) const{
		return c < o.c;
	}
} e[MM];

ld eval(pii j, pii k){
	auto [jt, jv] = j;
	auto [kt, kv] = k;
	if(!A)
		return (B*jt + jv >= B*kt + kv) ? 0: MM;
	return ld(A*(sq(jt)-sq(kt)) + B*(kt-jt) + jv - kv) / ld(2*A*(jt-kt));
}

deque<pii> q[MM];
priority_queue<pii, vector<pii>, greater<pii>> add[MM];

int main(){
	scan(n, m, A, B, C);
	for(int i = 0; i < m; i++)
		scan(e[i].a, e[i].b, e[i].c, e[i].d);
	sort(e, e+m);
	q[1].emplace_back(0, 0);
	
	for(int t = 0; t < m; t++){
		auto i = e[t];
		while(size(add[i.a]) and add[i.a].top().first <= i.c){
			auto j = add[i.a].top(); add[i.a].pop();
			while(size(q[i.a]) > 1 and eval(q[i.a][size(q[i.a])-2], q[i.a].back()) >= eval(q[i.a].back(), j))
				q[i.a].pop_back();
			q[i.a].emplace_back(j);
		}

		if(!size(q[i.a]))
			continue;

		while(size(q[i.a]) > 1 and eval(q[i.a][0], q[i.a][1]) <= i.c)
			q[i.a].pop_front();
		
		auto [jt, jv] = q[i.a].front();
		ll it = i.c;
		ll dp = A*sq(it) + B*it + C - 2*A*it*jt + A*sq(jt) - B*jt + jv;
		if(i.b == n)
			ans = min(ans, dp+i.d);
		add[i.b].emplace(i.d, dp);
	}
	print(ans);
}
/*
at point i,
min { A*sq(it - jt) + B*(it-jt) + C + jv}
min { A*sq(it) - 2*A*it*jt + A*sq(jt) + B*it - B*jt + C + jv}
A*sq(it) + B*it + C + min { -2*A*it*jt + (A*sq(jt) - B*jt + jv)}

x is queried time
line = -2*A*jt*(x) + (A*sq(jt) - B*jt + jv)

-2*A*jt*(x) + (A*sq(jt) - B*jt + jv) >= -2*A*kt*(x) + (A*sq(kt) - B*kt + kv),   j < k (also jt < kt)
A*sq(jt) - A*sq(kt) - B*jt + B*kt + jv - kv >= 2*A*jt*(x)-2*A*kt*(x) 
A*(sq(jt)-sq(kt)) + B*(kt-jt) + jv - kv >= 2*A*(x)*(jt-kt)
(A*(sq(jt)-sq(kt)) + B*(kt-jt) + jv - kv) / (2*A*(jt-kt)) >= x


case A = 0:
B*jt + jv >= B*kt + kv

*/