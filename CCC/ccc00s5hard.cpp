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
using ld = long double;
constexpr int MM = 1e5+5, X = 1e6;

struct line{
	ll m, b; int id;
	bool operator<(const line &o) const{
		if(m == o.m){
			if(b == o.b)
				abort();
				// return id > o.id;
			return b > o.b;
		}
		return m > o.m; //highest slope first
	}
};

int n;
ll x[MM], y[MM];
vector<line> points, q;

ld inter(line a, line b){
	assert(a.m != b.m);
	return ld(b.b-a.b)/ld(a.m-b.m);
}

int main(){
	scan(n);
	for(int i = 0; i < n; i++){
		scan(x[i], y[i]);
		points.push_back({-2*x[i], x[i]*x[i] + y[i]*y[i], i});
	}
	sort(all(points));
	for(auto i: points){
		while(size(q) and q.back().m == i.m)
			q.pop_back();
		while(size(q) >= 2 and inter(q.end()[-2], q.back()) > inter(q.back(), i))
			q.pop_back();
		q.push_back(i);
	}
	for(int i = 0; i < (int)size(q); i++){
		if(i < (int)size(q)-1 and inter(q[i], q[i+1]) < 0)
			continue;
		printf("The sheep at (%lld, %lld) might be eaten.\n", x[q[i].id], y[q[i].id]);
		if(i < (int)size(q)-1 and inter(q[i], q[i+1]) > X)
			break;
	}
}