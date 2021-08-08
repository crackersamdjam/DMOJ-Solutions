#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define size(x) ((int)(x).size())

using namespace std;
const int MM = 2e5+5;

#define lc rt<<1
#define rc rt<<1|1
#define nm (nl+nr)/2

int val[MM*4];
int lp[MM*4];

void pull(int rt){
	val[rt] = min(val[lc], val[rc]);
}

void push(int rt){
	val[lc] += lp[rt];
	lp[lc] += lp[rt];
	val[rc] += lp[rt];
	lp[rc] += lp[rt];
	lp[rt] = 0;
}

void update(int l, int r, int v, int nl, int nr, int rt){
	if(l > r)
		return;
	if(nr < l or r < nl)
		return;
	if(l <= nl and nr <= r){
		val[rt] += v;
		lp[rt] += v;
		return;
	}
	push(rt);
	update(l, r, v, nl, nm, lc);
	update(l, r, v, nm+1, nr, rc);
	pull(rt);
}

int query(int l, int r, int nl, int nr, int rt){
	if(nr < l or r < nl)
		return 1e9;
	if(l <= nl and nr <= r){
		return val[rt];
	}
	push(rt);
	return min(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
}

int n, m;
vector<int> adj[MM];
int lo[MM], dp[MM];
int suf[MM];


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>m;

	memset(lo, 0x3f, sizeof lo);
	memset(dp, 0x3f, sizeof dp);

	for(int i = 0,a,b; i < m; i++){
		cin>>a>>b;
		lo[a] = min(lo[a], b);
		lo[b] = min(lo[b], a);
	}

	suf[n+2] = lo[n+2];
	for(int i = n+1; i > 0; i--){
		suf[i] = min(lo[i], suf[i+1]);
	}

	dp[1] = 0;
	for(int i = 2; i <= n+1; i++){

		update(1, lo[i]-1, 1, 1, n+5, 1);

		int r = min(i-1, suf[i+1]-1);
		dp[i] = query(1, r, 1, n+5, 1);

		int prev = query(i, i, 1, n+5, 1);
		update(i, i, dp[i]-prev, 1, n+5, 1);

		// cout<<dp[i]<<' '<<flush;
	}

	// cout<<dp[n+1]-1<<'\n';
	cout<<dp[n]<<'\n';
	assert(dp[n+1]-1 == dp[n]);
}