#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
const int MM = 1e5+5;

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

ll sum[MM*4], val[MM];
int sz[MM*4];
map<int, int, greater<int>> mp;
int ptr;
//coord comp on values
	
void pull(int rt){
	sum[rt] = sum[lc] + sum[rc];
	sz[rt] = sz[lc] + sz[rc];
}

void update(int i, int v, int nl, int nr, int rt){
	if(nl == nr){
		sum[rt] += val[nl]*v;
		sz[rt] += v;
		return;
	}
	i <= nm ? update(i, v, nl, nm, lc) : update(i, v, nm+1, nr, rc);
	pull(rt);
}

ll query(int k, int nl, int nr, int rt){
	if(nl == nr)
		return min(k, sz[rt])*val[nl];
	if(k < sz[lc])
		return query(k, nl, nm, lc);
	return sum[lc] + query(k-sz[lc], nm+1, nr, rc);
}

int n, st, days;
int *att;
ll ans;
int ls, rs;

void go(int ld, int rd, int l, int r){
	if(l > r) return;
	int m = l+r>>1;
	while(rs < m)
		update(att[++rs], 1, 1, ptr, 1);
	while(rs > m)
		update(att[rs--], -1, 1, ptr, 1);
	while(ls > rd+1)
		update(att[--ls], 1, 1, ptr, 1);
	while(ls < rd+1)
		update(att[ls++], -1, 1, ptr, 1);

	//try all decision points
	int md = rd; ll v = 0;
	for(int i = rd; i >= ld; i--){
		update(att[--ls], 1, 1, ptr, 1);
		int rem = days-(m-st)-(st-i)-min(m-st, st-i);
		if(rem < 0) break;
		ll ret = query(rem, 1, ptr, 1);
		if(ret > v){
			v = ret;
			md = i;
		}
	}
	ans = max(ans, v);
	go(ld, md, l, m-1);
	go(md, rd, m+1, r);
}

ll findMaxAttraction(int _n, int _st, int _days, int _att[]){
	n = _n; st = _st; days = _days; att = _att;
	ans = 0;
	ptr = 0;
	for(int i = 0; i < n; i++)
		mp[att[i]] = 0;
	for(auto &it: mp){
		it.second = ++ptr;
		val[ptr] = it.first;
	}
	for(int i = 0; i < n; i++)
		att[i] = mp[att[i]];

	ls = st;
	rs = st-1;
	go(0, st, st, n-1);
	return ans;
}

#ifdef LOCAL
int main(){
	int _n, _st, _days;
	cin>>_n>>_st>>_days;
	int _att[_n];
	for(int i = 0; i < _n; i++)
		cin>>_att[i];
	cout<<findMaxAttraction(_n, _st, _days, _att)<<'\n';
}
#endif
/*
5 2 7
10 2 20 30 1
*/