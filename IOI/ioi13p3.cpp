#ifndef LOCAL
#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("avx2")
#endif

#if !defined(LOCAL) && !defined(ONLINE_JUDGE)
//oj.uz
#include "wombats.h"
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
constexpr int MM = 5001, NN = 201, SZ = 10;

#define nm ((nl+nr)/2)
#define lc (rt<<1)
#define rc (rt<<1|1)
#define npm int nl = 0, int nr = n-1, int rt = 1
#define lpm nl, nm, lc
#define rpm nm+1, nr, rc

int t[MM*3/SZ][NN][NN];
int n, m;
int H[MM][NN];
int V[MM][NN];

void go(int pre[NN], int cur[NN][NN], int res[NN], int l, int r, int ls, int rs){
	if(l > r) return;
	int mm = l+r>>1, id = ls;
	res[mm] = 1e9;
	for(int i = ls; i <= rs; i++){
		int v = pre[i]+cur[i][mm];
		if(v < res[mm]){
			res[mm] = v;
			id = i;
		}
	}
	go(pre, cur, res, l, mm-1, ls, id);
	go(pre, cur, res, mm+1, r, id, rs);
}

void pull(int rt, int nl, int nr){
	for(int st = 0; st < m; st++)
		go(t[lc][st], t[rc], t[rt][st], 0, m-1, 0, m-1);
}

void child(int u, int d, int dp[NN][NN]){
	int pre[NN][NN]; memset(pre, 0x3f, sizeof pre);
	for(int i = 0; i < m; i++)
		pre[i][i] = 0;

	for(int k = u; k <= d; k++){
		for(int i = 0; i < m; i++){
			for(int j = 0; j < m; j++)
				dp[i][j] = pre[i][j] + (k ? V[k-1][j] : 0);

			for(int j = 1; j < m; j++)
				dp[i][j] = min(dp[i][j], dp[i][j-1] + H[k][j-1]);
			for(int j = m-2; j >= 0; j--)
				dp[i][j] = min(dp[i][j], dp[i][j+1] + H[k][j]);

			for(int j = 0; j < m; j++)
				pre[i][j] = dp[i][j];
		}
	}
}

void build(npm){
	if(nr-nl <= SZ){
		child(nl, nr, t[rt]);
		return;
	}
	build(lpm); build(rpm);
	pull(rt, nl, nr);
}

void update(int i, npm){
	if(nr-nl <= SZ){
		child(nl, nr, t[rt]);
		return;
	}
	i <= nm ? update(i, lpm) : update(i, rpm);
	pull(rt, nl, nr);
}

void init(int R, int C, int _H[5000][200], int _V[5000][200]){
	n = R, m = C;
	// assert(n < MM);
	// assert(m < NN);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			H[i][j] = _H[i][j];
			V[i][j] = _V[i][j];
		}
	}
	build();
}

void changeH(int i, int j, int v){
	H[i][j] = v;
	update(i);
}

void changeV(int i, int j, int v){
	V[i][j] = v;
	update(i+1);
}

int escape(int a, int b){
	return t[1][a][b];
}


#ifdef LOCAL

int _H[5000][200], _V[5000][200];

int main(){
	// int aa[5000][200] = {{0,2,5}, {7,1,1}, {0,4,0}};
	// int bb[5000][200] = {{0,0,0,2}, {0,3,4,7}};
	// init(3, 4, aa, bb);
	int _n, _m;
	cin>>_n>>_m;
	for(int i = 0; i < _n; i++){
		for(int j = 0; j < _m-1; j++){
			cin>>_H[i][j];
		}
	}
	for(int i = 0; i < _n-1; i++){
		for(int j=  0; j < _m; j++){
			cin>>_V[i][j];
		}
	}
	init(_n, _m, _H, _V);
	// pr("_____________");
	int _q; cin>>_q;
	while(_q--){
		int a, b, c, d;
		cin>>a>>b>>c;
		if(a == 1){
			cin>>d;
			changeH(b, c, d);
		}
		else if(a == 2){
			cin>>d;
			changeV(b, c, d);
		}
		else if(a == 3){
			cout<<escape(b, c)<<'\n';
		}
		else abort();
	}
	// cout<<escape(2,1)<<'\n';
	// cout<<escape(3,3)<<'\n';
	// changeV(0,0,5);
	// changeH(1,1,6);	
	// cout<<escape(2,1)<<'\n';
}
#endif