#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

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
using pii = pair<ll, int>;
const int MM = 2e5+5;

int n, qs;
pii a[MM];
int par[MM];
ll ls[MM], rs[MM];
ll ans[MM], ml, mr, sum;
priority_queue<pii, vector<pii>, greater<pii>> q;

int find(int x){
	while(x != par[x])
		x = par[x], par[x] = par[par[x]];
	return x;
}

void merge(int x, int y){
	x = find(x), y = find(y);
	assert(x != y);
	par[x] = y;
	ls[y] = min(ls[y], ls[x]);
	rs[y] = max(rs[y], rs[x]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>qs;
	for(int i = 0; i < n; i++){
		cin>>a[i].first;
		a[i].second = i;
		par[i] = i;
		ls[i] = rs[i] = i;
	}
	sort(a, a+n);

	for(int i = 1; i < n; i++){
		q.push({a[i].first-a[i-1].first, i});
	}

	while(qs--){
		ll x; cin>>x;
		// pr("x", x);
		sum += x;
		ll nl = min(ml, sum);
		ll nr = max(mr, sum);
		while(size(q) and -nl+nr >= q.top().first){
			auto [dif, i] = q.top(); q.pop();
			if(sum > 0){
				//left goes into right
				ans[a[i].second] += -ml;
				ans[a[i-1].second] += dif+ml;
				// pr(i, sum, -ml, dif+ml);
				merge(i-1, i);
			}
			else{
				//right goes into left
				ans[a[i-1].second] += nr;
				ans[a[i].second] += dif-nr;
				// pr(i, sum, nr, dif-nr);
				merge(i-1, i);
			}
		}
		ml = nl;
		mr = nr;
	}

	for(int i = 0; i < n; i++){
		if(find(i) == i){
			// pr("ls", ls[i], ml);
			// pr("rs", rs[i], mr);
			ans[a[ls[i]].second] += -ml;
			ans[a[rs[i]].second] += mr;
		}
	}
	for(int i = 0; i < n ; i++){
		cout<<ans[i]<<'\n';
	}
}