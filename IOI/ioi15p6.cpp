#include "towns.h"
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
template<typename T> int size(T &x){return (int)x.size();}

// #ifndef ONLINE_JUDGE
// template<typename T>
// void pr(T a){std::cerr<<a<<std::endl;}
// template<typename T,typename... Args>
// void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
// #else
// template<typename... Args>
// void pr(Args... args){}
// #endif

using namespace std;

int hubDistance(int n, int sub){
	int lim = (7*n+1)/2;
	map<pair<int, int>, int> mp;
	auto getdis = [&](int x, int y){
		if(x == y) return 0;
		if(x > y) swap(x, y);
		if(mp[{x, y}]) return mp[{x, y}];
		lim--;
		assert(lim >= 0);
		return mp[{x, y}] = getDistance(x, y);
	};

	vector<int> dis0(n), diss(n);
	dis0[0] = 0;
	int s = 0;
	for(int i = 0; i < n; i++){
		dis0[i] = getdis(0, i);
		if(dis0[i] > dis0[s])
			s = i;
	}
	diss[s] = 0;
	diss[0] = dis0[s];
	vector<int> cc(n), bb(n), aa(n);
	int t = 0;

	for(int i = 0; i < n; i++){
		diss[i] = getdis(s, i);
		//use previous to calculate this
		// a + b = dis0[s]
		// a + c = dis0[i]
		// b + c = diss[i]
		// 
		// diss[i]+dis0[i]-dis0[s] = 2c
		int c = diss[i]+dis0[i]-dis0[s];
		// assert(c%2 == 0);
		c /= 2;
		aa[i] = dis0[i]-c;
		bb[i] = diss[i]-c;
		cc[i] = c;

		if(diss[i] > diss[t])
			t = i;
	}

	int dia = diss[t];

	auto val = [&](int x){
		return max(x, dia-x);
	};

	int best = dia;
	
	for(int i = 0; i < n; i++){
		// this distance works since path 0 to s passes centre
		int d = diss[i]-cc[i];
		if(val(d) < val(best)){
			best = d;
		}
	}

	int ans = val(best), second = -1;
	for(int i = 0; i < n; i++){
		int d = diss[i]-cc[i];
		if(d == dia-best)
			second = d;
	}

	auto centval = [&](int val){
		int ls = 0, rs = 0;
		for(int i = 0; i < n; i++){
			int d = bb[i];
			if(d == val);
			else if(d > val)
				ls++;
			else if(d < val)
				rs++;
		}
		return max(ls, rs);
	};

	//there may be two centres
	if(second != -1 and val(second) == val(best) and centval(second) < centval(best))
		best = second;

	vector<int> v;
	int ls = 0, rs = 0;
	for(int i = 0; i < n; i++){
		int d = bb[i];
		if(d == best){
			v.emplace_back(i);
		}
		else if(d > best)
			ls++;
		else if(d < best)
			rs++;
	}

	if(max(ls, rs) > n/2)
		return -ans;

	vector<array<int, 3>> cur, rest;
	for(int i: v)
		cur.push_back({i, 1, 1});

	while(size(cur) > 1){
		vector<array<int, 3>> nx;
		for(int i = 0; i < size(cur); i += 2){
			if(i == size(cur)-1){
				nx.emplace_back(cur[i]);
				continue;
			}
			auto a = cur[i], b = cur[i+1];
			
			int longd = cc[a[0]]+cc[b[0]];
			int reald = getdis(a[0], b[0]);
			// assert(reald <= longd);

			if(reald < longd){
				nx.push_back({a[0], a[1]+b[1], a[2]+b[2]});
			}
			else{
				if(a[1] > b[1]){
					nx.push_back({a[0], a[1]-b[1], a[2]});
					rest.push_back(b);
				}
				else if(a[1] < b[1]){
					nx.push_back({b[0], b[1]-a[1], b[2]});
					rest.push_back(a);
				}
				else{
					rest.push_back(a);
					rest.push_back(b);
				}
			}
		}
		cur = nx;
	}
	if(sub > 2 and size(cur)){
		// assert(size(cur) == 1);
		int a = cur[0][0], yes = cur[0][2];
		for(auto [b, _, sz]: rest){
			int longd = cc[a]+cc[b];
			int reald = getdis(a, b);
			// assert(reald <= longd);
			if(reald < longd){
				yes += sz;
			}
		}
		if(yes > n/2)
			return -ans;
	}

	return ans;
}