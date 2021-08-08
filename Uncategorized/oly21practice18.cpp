#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 2e5+5, NN = 400, SZ = 500, LOG = 18;

struct query{
	int t, l, r, id;
	bool operator<(const query &o) const{
		return t < o.t;
	}
} q[MM];

int n, qs;
ll a[MM], ans[MM], sp[LOG][MM];

ll qu(int l, int r){
	int k = __lg(r-l+1);
	return max(sp[k][l], sp[k][r-(1<<k)+1]);
}

stack<pair<int, ll>> st;
vector<pair<int, ll>> slope[NN];
ll curslope[NN], cursum[NN];
//at time i, slope changes by x
//changes sum by something

int ls[MM], rs[MM];
//rs how far will cover
//ls how far until covered

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>qs;

	for(int i = 1; i <= n; i++){
		cin>>a[i];
		sp[0][i] = a[i];
		while(size(st) and st.top().second <= a[i]){
			auto [j, v] = st.top();
			st.pop();
			rs[j] = i;
		}

		if(size(st)){
			auto [j, v] = st.top();
			ls[i] = j;
		}

		st.emplace(i, a[i]);
	}

	while(size(st)){
		auto [j, v] = st.top();
		st.pop();
		rs[j] = n+1;
	}

	for(int i = 1; i <= n; i++){
		//this one overwrites
		int id = i/SZ;
		int rid = rs[i]/SZ;

		slope[id].emplace_back(i-i, a[i]);
		slope[rid].emplace_back(rs[i]-i, -a[i]);
		for(int j = id; j <= rid; j++){
			if(j != id)
				slope[j].emplace_back(j*SZ-i, a[i]);
			
			if(j != rid)
				slope[j].emplace_back(j*SZ+SZ-i, -a[i]);
		}

		//when another starts to cover a[i]
		//and when it ends covering a[i]
		// i-ls[i] to rs[i]-ls[i]

		if(!ls[i])
			continue;

		slope[id].emplace_back(i-ls[i], -a[i]);
		slope[rid].emplace_back(rs[i]-ls[i], a[i]);
		for(int j = id; j <= rid; j++){
			if(j != id)
				slope[j].emplace_back(j*SZ-ls[i], -a[i]);
			
			if(j != rid)
				slope[j].emplace_back(j*SZ+SZ-ls[i], a[i]);
		}
	}

	for(int k = 1; k <= __lg(n); k++){	
		for(int i = 1; i+(1<<k)-1 <= n; i++){
			sp[k][i] = max(sp[k-1][i], sp[k-1][i+(1<<(k-1))]);
		}
	}

	for(int i = 0; i <= n/SZ; i++){
		sort(all(slope[i]), greater<pair<int, ll>>());
	}
	
	for(int i = 0; i < qs; i++){
		cin>>q[i].t>>q[i].l>>q[i].r;
		q[i].id = i;
	}
	sort(q, q+qs);
	int t = -1;
	for(int tt = 0; tt < qs; tt++){
		auto [nt, l, r, qi] = q[tt];

		for(int j = t+1; j <= nt; j++){
			for(int i = 0; i <= n/SZ; i++){
				while(size(slope[i]) and slope[i].back().first <= j){
					curslope[i] += slope[i].back().second;
					slope[i].pop_back();
				}
				cursum[i] += curslope[i];
			}
		}
		t = nt;

		r++;
		int li = ((l+SZ-1)/SZ), ri = ((r)/SZ);

		if(li >= ri){
			for(int i = l; i < r; i++)
				ans[qi] += qu(max(1, i-t), i);
		}
		else{
			for(int i = l; i < li*SZ; i++)
				ans[qi] += qu(max(1, i-t), i);

			for(int i = ri*SZ; i < r; i++)
				ans[qi] += qu(max(1, i-t), i);

			for(int i = li; i < ri; i++)
				ans[qi] += cursum[i];
		}
	}

	for(int i = 0; i < qs; i++)
		cout<<ans[i]<<'\n';
}