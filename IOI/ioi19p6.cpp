#ifndef LOCAL
#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("avx2")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, int>;
constexpr int MM = 1e5+5, NN = MM*18;

priority_queue<pll, vector<pll>, greater<pll>> q;
int n, m;
ll dis[NN];
vector<pii> adj[NN];
vector<pii> incol[MM], inrow[MM]; //point ids
map<pii, int> mp; //points
int ptr; //next point
vector<pii> walks;

inline void addedge(int a, int b, int c){
	adj[a].emplace_back(b, c);
	adj[b].emplace_back(a, c);
}

long long min_distance(vector<int> x, vector<int> h, vector<int> l, vector<int> r, vector<int> y, int st, int ed){

	//i and j are indices
	auto add = [&](int i, int j){
		int id = mp[{i, j}];
		if(id) return;
		id = mp[{i, j}] = ++ptr;
		// assert(ptr < NN);
		
		incol[i].emplace_back((~j) ? y[j] : 0, ptr);
		if(~j) inrow[j].emplace_back(x[i], ptr);
		return;
	};

	n = x.size(), m = y.size();
	add(st, -1);
	add(ed, -1);

	// insert all intersections (debug)
	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < m; j++){
	// 		if(y[j] <= h[i] and l[j] <= i and i <= r[j]){
	// 			add(i, j);
	// 		}
	// 	}
	// }

	for(int i = 0; i < m; i++){
		add(l[i], i);
		add(r[i], i);
		walks.emplace_back(y[i], i);

		if(l[i] <= st and st <= r[i] and y[i] <= h[st])
			add(st, i);
		if(l[i] <= ed and ed <= r[i] and y[i] <= h[ed])
			add(ed, i);
	}

	set<int> all;
	all.insert(-1);
	for(int i = 0; i < n; i++)
		all.insert(i);
	all.insert(INT_MAX);

	auto check = [&](int i, int mid){
		if(l[i] > mid or r[i] < mid)
			return;
		auto it = all.upper_bound(mid);
		while(*it <= r[i] and h[*it] < y[i]){
			it = all.erase(it);
		}
		if(*it <= r[i])
			add(*it, i);

		while(*it >= mid)
			it--;
		// assert(it == --all.lower_bound(mid));
		while(*it >= l[i] and h[*it] < y[i]){
			it = all.erase(it);
			it--;
			// assert(it == --all.lower_bound(mid));
		}
		if(*it >= l[i])
			add(*it, i);

		return;
	};

	sort(all(walks));
	for(auto p: walks){
		int i = p.second;
		check(i, st);
		check(i, ed);
	}

	//now add the ones above/below existing points
	//line sweep x 0 to n-1, storing which y intersect
	vector<pii> ins, del;
	for(int i = 0; i < m; i++){
		ins.emplace_back(l[i], i);
		del.emplace_back(r[i], i);
	}

	vector<pii> toadd;
	set<pii> in;
	in.insert({-2, -1});
	in.insert({-1, -1});
	in.insert({INT_MAX, -1});
	sort(all(ins), greater<pii>());
	sort(all(del), greater<pii>());
	for(int i = 0; i < n; i++){
		while(ins.size() and ins.back().first == i){
			int id = ins.back().second, hi = y[id];
			in.insert({hi, id});
			ins.pop_back();
		}

		for(auto j: incol[i]){
			auto it = in.upper_bound({j.first+1, -2});
			if(it->first != INT_MAX and y[it->second] <= h[i])
				toadd.emplace_back(i, it->second);
			----it;
			if(it->first > -1)
				toadd.emplace_back(i, it->second);
		}

		while(del.size() and del.back().first == i){
			int id = del.back().second, hi = y[id];
			in.erase({hi, id});
			del.pop_back();
		}
	}

	for(auto i: toadd)
		add(i.first, i.second);

	//build graph col
	for(int t = 0; t < n; t++){
		auto &i = incol[t];
		sort(all(i));
		i.erase(unique(all(i)), i.end());
		
		for(int j = 1; j < (int)i.size(); j++){
			addedge(i[j-1].second, i[j].second, (ll)i[j].first-i[j-1].first);
		}
	}
	//build row
	for(int t = 0; t < m; t++){
		auto &i = inrow[t];
		sort(all(i));
		i.erase(unique(all(i)), i.end());

		if(i.size())
		for(int j = 1; j < (int)i.size(); j++){
			addedge(i[j-1].second, i[j].second, (ll)i[j].first-i[j-1].first);
		}
	}

	memset(dis, 0x3f, sizeof dis);
	q.emplace(dis[1] = 0, 1);
	while(q.size()){
		int cur = q.top().second; ll curd = q.top().first; q.pop();
		if(curd > dis[cur]) continue;
		if(cur == 2)
			return curd;

		for(auto e: adj[cur]){
			int u = e.first, w = e.second;
			if(curd+w < dis[u])
				q.emplace(dis[u] = curd+w, u);
		}
	}
	return -1;
}

#ifndef ONLINE_JUDGE
int main(){
	// string Z;
	// cin>>Z;
	// int N, M, ST, ED;
	// scan(N, M);
	// vector<int> X(N), H(N), L(M), R(M), Y(M);
	// for(int i = 0; i < N; i++){
	// 	scan(X[i], H[i]);
	// }
	// for(int i = 0; i < M; i++){
	// 	scan(L[i], R[i], Y[i]);
	// }
	// scan(ST, ED);
	// print(min_distance(X, H, L, R, Y, ST, ED));
	// return 0;

	if(1){
		print(min_distance({0, 3, 5, 7, 10, 12, 14},
	             {8, 7, 9, 7, 6, 6, 9},
	             {0, 0, 0, 2, 2, 3, 4},
	             {1, 2, 6, 3, 6, 4, 6},
	             {1, 6, 8, 1, 7, 2, 5},
	             1, 5));
		return 0;
	}
	print(min_distance({0, 4, 5, 6, 9},
             {6, 6, 6, 6, 6},
             {3, 1, 0},
             {4, 3, 2},
             {1, 3, 6},
             0, 4));
}
#endif