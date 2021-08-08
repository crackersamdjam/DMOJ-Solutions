#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using ld = long double;
constexpr int MM = 2e5+5;

struct line{
	ll m, b; int id;
	bool operator<(const line &o) const{
		if(m == o.m){
			if(b == o.b)
				return id > o.id;
			return b > o.b;
		}
		return m > o.m; //highest slope first
	}
};

struct hline{
	ll y; int id;
	bool operator<(const hline &o) const{
		if(y == o.y)
			return id < o.id; //break ties
		return y < o.y;
	}
};

int n, X;
ld ans[MM];
vector<line> points, q;
vector<pair<pair<int, int>, hline>> ord;

ld inter(line a, line b){
	// assert(a.m != b.m);
	return ld(b.b-a.b)/ld(a.m-b.m);
}
// a.m*x + a.b = b.m*x + b.b
// a.m*x - b.m*x = b.b-a.b
// x(a.m-b.m) = (b.b-a.b)
// x = (b.b-a.b)/(a.m-b.m)

void addpt(ll x, ll y, int id){
	points.push_back({-2*x, x*x + y*y, id});
}

int main(){
	scan(n, X);
	for(int i = 0,x,y,h,w; i < n; i++){
		scan(x, y, h, w);
		addpt(x, y, i);
		addpt(x+h, y, i);
		ord.push_back({{x, 0}, {y, i}});
		ord.push_back({{x+h, 1}, {y, i}});
	}
	
	sort(all(points));
	for(auto i: points){
		while(size(q) and q.back().m == i.m)
			q.pop_back();
		while(size(q) >= 2 and inter(q.end()[-2], q.back()) >= inter(q.back(), i))
			q.pop_back();
		q.push_back(i);
	}

	vector<line> v1;
	vector<ld> i1;
	q.push_back({(ll)-2.1e9, (ll)3e18});

	for(int i = 1; i < (int)size(q); i++){
		ld x = inter(q[i-1], q[i]);
		if(x >= X){
			i1.push_back(X);
			v1.push_back(q[i-1]);
			break;
		}
		if(x > 0){
			i1.push_back(x);
			v1.push_back(q[i-1]);
		}
	}

	vector<ld> i2;
	vector<ll> x2;
	vector<int> id2;
	multiset<pair<ll, hline>> best;
	best.insert({LLONG_MAX, {(ll)2e9, n}});

	ord.push_back({{X, 2}, {}});
	sort(all(ord));

	for(auto i: ord){
		//i.first.first is index that this range ends at
		if(i.first.first > 0){
			auto ins = best.begin()->second;
			x2.push_back(ins.y);
			id2.push_back(ins.id);
			i2.push_back(i.first.first);
		}
		if(i.first.second == 2)
			break;
		else if(i.first.second == 0)
			best.insert({i.second.y, i.second});
		else
			best.erase(best.lower_bound({i.second.y, i.second}));
	}

	int l1 = 0, l2 = 0;
	ld last1 = 0, last2 = 0;
	while(l1 < size(i1) and l2 < size(i2)){
		//calculate how much v2[l2] takes away from v1[l1]
		/*
		x^2 + mx + b = h^2
		x^2 + mx + b - h^2 = 0
		x = (-m +- sqrt(m^2 - (4*(b-h^2))) )/2
		*/
		auto a = v1[l1];
		auto h = x2[l2];
		//a is cht, h is horizontal line
		ld ls = max(last1, last2), rs = min(i1[l1], i2[l2]), len = rs-ls, cht = 0;

		ld delta = a.m*a.m - 4*(a.b-(ld)h*h);
		if(delta >= 0){
			delta = sqrtl(abs(delta));
			ld l = (-a.m - delta)/2, r = (-a.m + delta)/2;
			l = max(l, ls);
			r = min(r, rs);
			cht = max((ld)0, r-l);
		}

		ans[v1[l1].id] += cht;
		ans[id2[l2]] += len-cht;

		//v1 for cht, v2 to hor line segment, d is when parabola goes above cht line (cht better)

		//which to move forward next
		if(i1[l1] < i2[l2])
			last1 = i1[l1++];
		else
			last2 = i2[l2++];
	}

	// cout<<setprecision(9);
	for(int i = 0; i < n; i++)
		printf("%.9Lf\n", 100*ans[i]/X);
		// cout<<100*ans[i]/X<<'\n';
}
/*
closest(i) = sqrt((i-x)^2 + y^2)
	ignore sqrt by doing it afterwards
(i-x)^2 + y^2
i^2 - 2ix + x^2 + y^2
m = -2x, b = x^2 + y^2

graph is monotonically decreasing, looks like rainbow
so sort for highest slope first


allen: subtract i^2 froom segment so that it becomes parabola
this helps us calculate intersect with the convex hull

x^2 + mx + b = h^2
x^2 + mx + b - h^2 = 0
x = (-m +- (m^2 - sqrt(4*(b-h^2))) )/2

if no intersection, ignore this hline from hull (because the segment - x^2 = a parabola opens down)

do NOT worry about overlaps
this will be handled with by the "points" at the corners

*/