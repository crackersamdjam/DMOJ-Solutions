#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 3e5+5;

int n, q, ans[MM], tt;
char s[MM];
set<int> st;
int bit[MM];
vector<int> rm;

int qu(int i){
	int v = 0;
	for(; i; i -= i&-i){
		v += bit[i];
		rm.emplace_back(i);
	}
	return v;
}

void up(int i, int v){
	for(; i < MM; i += i&-i){
		bit[i] += v;
		rm.emplace_back(i);
	}
}

void clear(){
	for(int i: rm)
		bit[i] = 0;
	rm.clear();
}

struct stc{
	int op, x, y, v;
};

void go(int l, int r, vector<stc> &v){
	if(v.empty()) return;
	int m = l+r>>1;
	vector<stc> lv, rv;

	clear();

	for(auto i: v){
		if(!i.op){
			if(i.x <= m){
				up(i.y, i.v);
				lv.push_back(i);
			}
			else
				rv.push_back(i);
		}
		else{
			if(i.x < m){
				lv.push_back(i);
			}
			else{
				ans[i.v] += qu(i.y);
				rv.push_back(i);
			}
		}
	}
	v.clear();
	v.shrink_to_fit();

	if(l < r) go(l, m, lv), go(m+1, r, rv);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>q;
	for(int i = 1; i <= n; i++){
		cin>>s[i];
		s[i] -= '0';
		if(!s[i])
			st.insert(i);
	}
	st.insert(0);
	st.insert(n+1);

	vector<stc> v;
	string op;
	for(int t = 1,l,m,r; t <= q; t++){
		cin>>op;
		if(op[0] == 'q'){
			cin>>l>>r;
			r--;
			if(*st.lower_bound(l) > r)
				ans[tt] += t;
			v.push_back({1, l, r, tt++});
		}
		else{
			cin>>m;
			auto it = st.upper_bound(m);
			r = *it;
			if(*--it == m)
				--it;
			l = *it;

			int f;
			if(s[m]){
				st.insert(m);
				f = 1;
			}
			else{
				st.erase(++it);
				f = -1;
			}

			v.push_back({0, l+1, m, t*f});
			v.push_back({0, l+1, r, -t*f});

			v.push_back({0, m+1, m, -t*f});
			v.push_back({0, m+1, r, t*f});
			s[m] ^= 1;
		}
	}

	go(1, n+1, v);

	for(int i = 0; i < tt; i++)
		cout<<ans[i]<<'\n';
}