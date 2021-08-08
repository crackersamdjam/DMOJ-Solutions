#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using ll = long long;
constexpr int MM = 2e5+5;

int n, m, k, x[MM], y[MM];
vector<int> in[MM];
vector<vector<int>> a;
vector<pair<int, vector<int>>> b;

int minn(int i){
	return x[b[i].first];
}
int maxx(int i){
	return y[b[i].first];
}
int nor(int i){
	return (int)size(a[i]);
}

inline bool cmp(const pair<int, vector<int>> &va, const pair<int, vector<int>> &vb){
	return va.second[x[va.first]] < vb.second[x[vb.first]];
}

struct state{
	ll v; int i, j, cnt, maxr; //can not go past next at maxr
	bool operator<(const state &o) const{
		return v > o.v;
	}
};

priority_queue<state> q;
ll base;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>m>>k;
	for(int i = 0,d,c; i < n; i++){
		cin>>d>>c;
		in[d-1].emplace_back(c);
	}
	for(int i = 0; i < m; i++){
		cin>>x[i]>>y[i];
		sort(all(in[i]));
		if((int)size(in[i]) < x[i]){
			while(k--)
				cout<<"-1\n";
			return 0;
		}
		for(int j = 0; j < x[i]; j++){
			base += in[i][j];
		}
		for(int j = (int)size(in[i])-1; j > 0; j--){
			in[i][j] -= in[i][j-1];
		}
		
		if((int)size(in[i]) > x[i] and y[i]){
			a.emplace_back(in[i]);
			b.emplace_back(i, in[i]);
		}
	}
	sort(all(b), cmp);
	for(int i = 0; i < (int)size(a); i++)
		a[i] = b[i].second;
	
	if(!size(b)){
		cout<<base<<'\n';
		k--;
		while(k--)
			cout<<"-1\n";
		return 0;
	}

	m = (int)size(a);
	q.push({base, 0, minn(0)-1, 0, nor(0)}); //cnt is how many on right moved...
	while(size(q)){
		auto [curd, i, j, cnt, maxr] = q.top(); q.pop();
		cout<<curd<<'\n';
		if(!--k) return 0;

		if(j+1 < maxr){
			q.push({curd+a[i][j+1], i, j+1, cnt+!cnt, maxr}); //edge case !cnt
		}
		if(cnt < minn(i)){
			//add and keep moving
			int l = minn(i)-cnt; //new j pos
			if(l < j) //have space for next
				q.push({curd+a[i][l], i, l, cnt+1, j});
		}
		else if(cnt < maxx(i) and j > 0){
			q.push({curd+a[i][0], i, 0, cnt+1, j});
		}
		if(i+1 < m and cnt){ //not first one edge case
			int l = minn(i+1);
			//ignore this list and go to next
			if(j == minn(i) and cnt == 1){
				q.push({curd+a[i+1][l]-a[i][j], i+1, l, 1, nor(i+1)});
			}
			
			//still has stuff from this, but now in next
			q.push({curd+a[i+1][l], i+1, l, 1, nor(i+1)});
		}
	}
	while(k--)
		cout<<"-1\n";
}