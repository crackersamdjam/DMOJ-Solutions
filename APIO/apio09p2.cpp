#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using pii = pair<int, int>;
const int MM = 2e5+5, LOG = 18;

struct stt{
	int l, r, i;
};
vector<stt> va, second;
// va is all, second is what I use for greedy

int n;
int at[MM];
int sp[LOG][MM];

int go(int l, int r){
	l = lower_bound(all(second), stt({l, -1, -1}), [](auto x, auto y){
		return x.l < y.l;
	}) - second.begin();

	l = at[second[l].i];

	if(va[l].r > r)
		return 0;

	int ret = 1;
	// take l

	for(int i = LOG-1; i >= 0; i--){
		if(sp[i][l] and va[sp[i][l]].r <= r){
			// if I can take (l, l+1<<i]
			// (l has been already taken)
			l = sp[i][l];
			ret += 1<<i;
		}
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);

	cin>>n;
	for(int i = 1,a,b; i <= n; i++){
		cin>>a>>b;
		va.push_back({a, b, i});
	}
	va.push_back({INT_MAX-2, INT_MAX-2, 0});

	sort(all(va), [](auto x, auto y){
		if(x.r != y.r)
			return x.r < y.r;
		if(x.l != y.l)
			return x.l > y.l; //later rend first
		return x.i < y.i;
	});

	// gets rid of completely contained
	// so that now I can greedily take next
	int last = 0;
	for(auto i: va){
		if(last < i.l){
			second.push_back(i);
			last = i.l;
		}
	}
		
	sort(all(second), [](auto x, auto y){
		return x.l < y.l;
	});

	memset(at, -1, sizeof at);
	for(int i = 0; i < size(va); i++){
		at[va[i].i] = i;
	}

	// map va to second
	for(int i = 0; i < size(va)-1; i++){
		// skip last dummy
		// find r endpoint
		int l = 0, r = (int)size(second)-1;
		while(l <= r){
			int m = l+r>>1;
			if(va[i].r >= second[m].l)
				l = m+1;
			else
				r = m-1;
		}
		// assert(l < size(second));
		sp[0][i] = at[second[l].i];
	}

	for(int i = 1; i < LOG; i++){
		for(int j = 0; j < size(va); j++){
			int u = sp[i-1][j];
			if(u) sp[i][j] = sp[i-1][u];
		}
	}

	vector<int> out;
	map<int, int> in = {{0, INT_MAX-5}, {INT_MAX, INT_MAX}};

	for(int t = 1; t <= n; t++){
		int i = at[t];
		if(i == -1) continue;

		int l = va[i].l, r = va[i].r;
		auto it = prev(in.upper_bound(l));
		auto [ls, rs] = *it;

		// assert(ls <= l);
		if(rs < r)
			continue;
		
		int old = go(ls, rs);
		int cur = go(ls, l-1) + go(r+1, rs) + 1;

		// assert(old >= cur);
		if(cur == old){
			out.emplace_back(t);
			in[r+1] = it->second;
			it->second = l-1;
		}
	}
	cout<<size(out)<<'\n';
	for(int i: out)
		cout<<i<<' ';
	cout<<'\n';
}