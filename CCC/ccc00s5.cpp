#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
using ld = double;
constexpr int MM = 1005, X = 1000*1000;

struct line{
	ll m, b; int id;
	bool operator<(const line &o) const{
		if(m == o.m){
			// if(b == o.b)
				// abort();
				// return id > o.id;
			return b > o.b;
		}
		return m > o.m; //highest slope first
	}
};

int n;
ld x[MM], y[MM];
vector<line> points, q;

ld inter(line a, line b){
	return ld(b.b-a.b)/ld(a.m-b.m);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>x[i]>>y[i];
		ll xi = round(x[i]*1000);
		ll yi = round(y[i]*1000);
		points.push_back({-2*xi, xi*xi + yi*yi, i});
	}
	sort(all(points));
	for(auto i: points){
		while(size(q) and q.back().m == i.m)
			q.pop_back();
		while(size(q) >= 2 and inter(q.end()[-2], q.back()) > inter(q.back(), i))
			q.pop_back();
		q.push_back(i);
	}
	cout<<fixed<<setprecision(2);
	for(int i = 0; i < (int)size(q); i++){
		if(i < (int)size(q)-1 and inter(q[i], q[i+1]) < 0)
			continue;
		cout<<"The sheep at ("<<x[q[i].id]<<", "<<y[q[i].id]<<") might be eaten.\n";
		if(i < (int)size(q)-1 and inter(q[i], q[i+1]) > X)
			break;
	}
}