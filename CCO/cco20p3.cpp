#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#define INPUT_SIZE (5<<23)
int _i0=0;
char _,_i[INPUT_SIZE+5];
#define su(x) do{for(x=_i[_i0++]-48;47<(_=_i[_i0++]);x=x*10+_-48);}while(0)

using std::max;
typedef std::pair<int, int> pii;

constexpr int MM = 5e5+1, LOG = 20, inf = 0x3f3f3f3f;

int n, m, ans, dep[MM], sp[LOG][MM], val1[LOG][MM], val2[LOG][MM], val3[LOG][MM], val4[LOG][MM], val5[LOG][MM];
std::vector<int> adj[MM];
struct st1{ int a, b, c;} add[MM*4];

int dpup1[MM], dpup2[MM], dpup3[MM];
//dp up only ch of par, dpup2 is all above, dpup3 combines all above

pii dp1[MM], dp2[MM], dp3[MM];
//longest up, 1st down, 2nd down, 3rd down
int dpdown[MM];
//dp down (longest)
int dpmax[MM]; //max len in subtree
int dpbest[MM]; //best of par's ch's dpmax excluding cur
int dpl[MM]; //left side to exclude current while looping others in dfs2

int getvalres[4];
inline void getval(int lca, int a, int b, bool f=0){
	//exclude ch a and b
	// for(int i = LOG-1; i >= 0; i--){
	// 	if(~sp[i][a] && dep[sp[i][a]] > dep[lca])
	// 		a = sp[i][a];
	// 	if(~sp[i][b] && dep[sp[i][b]] > dep[lca])
	// 		b = sp[i][b];
	// }
	// assert(!a or a == lca or sp[0][a] == lca);
	// assert(!b or b == lca or sp[0][b] == lca);
	// getvalres[0] = getvalres[1] = getvalres[2] = getvalres[3] = 0;
	int t = 0;
	if(!f)
		getvalres[t++] = dpup2[lca];
	if(dp1[lca].second != a and dp1[lca].second != b)
		getvalres[t++] = dp1[lca].first;
	if(dp2[lca].second != a and dp2[lca].second != b)
		getvalres[t++] = dp2[lca].first;
	if(dp3[lca].second != a and dp3[lca].second != b)
		getvalres[t++] = dp3[lca].first;
	sort(getvalres, getvalres+t, std::greater<int>());
}

void dfs(int cur, int pre){
	dep[cur] = dep[pre]+1;
	sp[0][cur] = pre;
	for(int u: adj[cur]){
		if(u != pre){
			dfs(u, cur);
			dpdown[cur] = max(dpdown[cur], dpdown[u]+1);
			dpmax[cur] = max(dpmax[cur], dpmax[u]);
			pii tmp = {dp1[u].first+1, u};
			if(tmp > dp1[cur]){
				dp3[cur] = dp2[cur];
				dp2[cur] = dp1[cur];
				dp1[cur] = tmp;
			}
			else if(tmp > dp2[cur]){
				dp3[cur] = dp2[cur];
				dp2[cur] = tmp;
			}
			else if(tmp > dp3[cur]){
				dp3[cur] = tmp;
			}
		}
	}
	dpmax[cur] = max(dpmax[cur], dp1[cur].first+dp2[cur].first);
}
int mx, mx2, best, hi, sec;
void dfs2(int cur, int pre){
	// int mx = 0, mx2 = dpup2[cur], best = 0, hi = 0, sec = 0;
	mx = 0, mx2 = dpup2[cur], best = 0, hi = 0, sec = 0;

	//dpup2 for all above too
	for(int u: adj[cur]){
		if(u != pre){
			dpup1[u] = max(dpup1[u], mx+1);
			mx = max(mx, dp1[u].first+1);

			dpup2[u] = max(dpup2[u], mx2+1);
			mx2 = max(mx2, dp1[u].first+1);

			dpup3[u] = max(dpup3[cur], hi+max(sec, dpup2[cur]));

			dpl[u] = max(dpl[u], hi);
			dpbest[u] = max(hi+sec, best);
			best = max(best, dpmax[u]); //best subtree
			int v = dp1[u].first+1;
			if(v > hi)
				sec = hi, hi = v;
			else if(v > sec)
				sec = v;
		}
	}

	reverse(all(adj[cur]));
	mx = 0, mx2 = dpup2[cur], best = 0, hi = 0, sec = 0;
	for(int u: adj[cur]){
		if(u != pre){
			dpup1[u] = max(dpup1[u], mx+1);
			mx = max(mx, dp1[u].first+1);

			dpup2[u] = max(dpup2[u], mx2+1);
			mx2 = max(mx2, dp1[u].first+1);

			dpup3[u] = max(dpup3[u], hi+max(dpl[u], max(sec, dpup2[cur])));

			dpbest[u] = max(dpbest[u], max(dpl[u]+hi, max(hi+sec, best)));
			best = max(best, dpmax[u]); //best subtree
			int v = dp1[u].first+1;
			if(v > hi)
				sec = hi, hi = v;
			else if(v > sec)
				sec = v;
		}
	}
	//I need to consider hi on both sides... with more dp arrays

	for(int u: adj[cur]){
		if(u != pre)
			dfs2(u, cur);
	}

	val1[0][cur] = dpup1[cur]-1-dep[cur];
	val2[0][cur] = dpup1[cur]-1+dep[cur];
	getval(pre, cur, cur, 1);
	val4[0][cur] = getvalres[0]+getvalres[1];
	val5[0][cur] = dpbest[cur];
}

inline int getlca(int u, int v){
	if(dep[u] < dep[v])
		std::swap(u, v);
	for(int i = LOG-1; i >= 0; i--){
		if(~sp[i][u] && (dep[sp[i][u]] >= dep[v]))
			u = sp[i][u];
	}
	if(u == v)
		return u;

	for(int i = LOG-1; i >= 0; i--){
		if(~sp[i][u] && ~sp[i][v] && (sp[i][u] != sp[i][v])){
			u = sp[i][u];
			v = sp[i][v];
		}
	}
	return sp[0][u];
}

int ret1a, ret1b, ret3a, ret3b, ret4, ret5, aa, bb;

inline void query(int lca, int a, int b){
	ret1a = -inf, ret1b = -inf, ret3a = -inf, ret3b = -inf, ret4 = -inf, ret5 = -inf;

	if(a != lca){
		ret1a = dpdown[a]-1-dep[a];
		getval(a, -1, -1, 1);
		ret4 = getvalres[0]+getvalres[1];
		ret5 = dpmax[a];
	}
	if(b != lca){
		ret1b = dpdown[b]-1-dep[b];
		getval(b, -1, -1, 1);
		ret4 = max(ret4, getvalres[0]+getvalres[1]);
		ret5 = max(ret5, dpmax[b]);
	}

	for(int i = LOG-1; i >= 0; i--){
		if(dep[a] > dep[lca]+(1<<i)){ //don't query the node right under lca

			ret3a = max(ret3a, ret1a+val2[i][a]); //this way val1 lower than val2
			ret3a = max(ret3a, val3[i][a]); //precalc'ed during build

			ret1a = max(ret1a, val1[i][a]);
			ret4 = max(ret4, val4[i][a]);
			ret5 = max(ret5, val5[i][a]);
			a = sp[i][a];
		}
	}
	for(int i = LOG-1; i >= 0; i--){
		if(dep[b] > dep[lca]+(1<<i)){

			ret3b = max(ret3b, ret1b+val2[i][b]);
			ret3b = max(ret3b, val3[i][b]);

			ret1b = max(ret1b, val1[i][b]);
			ret4 = max(ret4, val4[i][b]);
			ret5 = max(ret5, val5[i][b]);
			b = sp[i][b];
		}
	}
	aa = a, bb = b;
}

int main(){
	fread(_i,1,INPUT_SIZE,stdin);
	
	memset(sp, -1, sizeof sp);
	// memset(val3, -0x3f, sizeof val3);
	int tt = 0;

	su(n); su(m);
	for(int i = 0,a,b,c; i < m; i++){
		su(a); su(b); su(c);
		a++, b++;
		if(c == 1){
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		else
			add[tt++] = {a, b, c};
	}
	dfs(1, 0);
	dfs2(1, 0);
	
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= n; j++){
			int u = sp[i-1][j];
			if(~u){
				sp[i][j] = sp[i-1][u];
				val1[i][j] = max(val1[i-1][j], val1[i-1][u]);
				val2[i][j] = max(val2[i-1][j], val2[i-1][u]);
				val4[i][j] = max(val4[i-1][j], val4[i-1][u]);
				val5[i][j] = max(val5[i-1][j], val5[i-1][u]);
				val3[i][j] = max(max(val3[i-1][j], val3[i-1][u]),
					val2[i-1][u] + val1[i-1][j]); //merge, val1 lower than val2
			}
		}
	}
	for(int i = 1; i <= n; i++){
		getval(i, -1, -1);
		ans = max(ans, getvalres[0]+getvalres[1]);
	}

	int a, b, c, lca, len;
	while(tt--){
		a = add[tt].a, b = add[tt].b, c = add[tt].c;
		lca = getlca(a, b);
		len = dep[a]+dep[b]-2*dep[lca];
		query(lca, a, b);
		getval(lca, aa, bb);

		//case 1.1 (make cycle and diameter is *on* lca)
		ans = max(ans, getvalres[0]+getvalres[1]+len-c);

		//case 1.2 (make cycle and diameter is *above lca)
		ans = max(ans, len-c+dpup3[lca]);

		// case 2 one inside critical path, one above
		// max dist(par[x], b)+dpup1[x]
		// max dep[b]-(dep[x]-1)+dpup1[x]
		// max dep[b]+1+{dpup1[x]-dep[x]}
		ans = max(ans, getvalres[0]-c+2+len+dep[lca]+1+max(ret1a, ret1b));

		// case 3.1 on opposite sides of lca
		// dia = max{dp[x]+dist(x, a)+dist(b, y)+dp[y]} (c involved, but subtract after)
		// dia = max{dp[x] + dep[a]-dep[x] + dep[b]-dep[y] + dp[y]}
		// dia = dep[a]+dep[b] + max{dp[x]-dep[x] -dep[y]+dp[y]}
		// dia = dep[a]+dep[b] + max{dp[x]-dep[x]} + max{dp[y]-dep[y]}}
		ans = max(ans, -c+2+dep[a]+dep[b] + ret1a + ret1b+2); //(two edge depth issue)

		// case 3.2 (both on same side of lca)
		// get max{dp[x]+dp[y]-dist(x, y)}
		// WLOG dep[x] > dep[y], so x below y (val1 lower than val2)
		// max{dp[x]+dp[y] - (dep[x]-dep[y])}
		// max{dp[x]-dep[x] + dp[y]+dep[y])}
		// max{dp[x]-dep[x]} + max{dp[y]+dep[y])}
		// max{val1} + max{val2}
		ans = max(ans, len-c+2+max(ret3a, ret3b));

		// case 3.3 (both with contact to same node of critical cycle (one start, one end))
		ans = max(ans, len-c+ret4);

		// case 3.4 (longest path is entirely contained in a subtree)
		ans = max(ans, len-c+ret5);
	}
	printf("%d\n", 2*(n-1) - ans);
}