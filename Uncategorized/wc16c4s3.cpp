#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 2e5+5;

int n, k;
array<int, 2> a[MM];

set<array<int, 2>> st;
set<int> vis;

void rs(int r, array<int, 2> p){
	auto it = st.upper_bound(p);
	while(it != st.end() and (*it)[0] <= p[0]+r and (*it)[1] > p[1]){
		rs(r, *it);
		vis.insert((*it)[1]);
		it = st.erase(it);
	}
}

void ls(int r, array<int, 2> p){
	auto it = st.lower_bound(p);
	while(it != st.begin()){
		it--;
		if((*it)[0] >= p[0]-r and (*it)[1] > p[1]){
			ls(r, *it);
			vis.insert((*it)[1]);
			it = st.erase(it);
		}
		else break;
	}
}

bool go(int r){
	st.clear();
	vis.clear();
	int cnt = 0;
	for(int i = 0; i < n; i++)
		st.insert(a[i]);

	for(int i = 0; i < n; i++){
		if(!vis.count(a[i][1])){
			if(++cnt > k)
				return 0;
			rs(r, a[i]);
			ls(r, a[i]);
			auto it = st.lower_bound(a[i]);
			assert(it != st.end() and *it == a[i]);
			vis.insert(a[i][1]);
			st.erase(it);
		}
	}
	return 1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	for(int i = 0; i < n; i++)
		cin>>a[i][1]>>a[i][0];
	sort(a, a+n);
	for(int i = 0; i < n; i++)
		swap(a[i][0], a[i][1]);

	int l = 0, m, r = 1e9;
	while(l <= r){
		m = l+r>>1;
		if(go(m))
			r = m-1;
		else
			l = m+1;
	}
	cout<<l<<'\n';
}