#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
constexpr int MM = 4e5+5, LOG = 19;

int n, q, dep[MM], sp[LOG][MM], in[MM], t;
vector<int> adj[MM];

int val[LOG][MM]; //O(1) rmq

int query(int l, int r){
	if(l > r) swap(l, r);
	int k = __lg(r-l+1);
	return min(val[k][l], val[k][r-(1<<k)+1]);
}

void dfs(int cur, int pre){
	dep[cur] = dep[pre]+1;
	sp[0][cur] = pre;
	
	in[cur] = ++t;
	val[0][t] = dep[cur];

	for(int u: adj[cur]){
		if(u != pre){
			dfs(u, cur);
			val[0][++t] = dep[cur];
		}
	}
}

int getlca(int u, int v){
	if(dep[u] < dep[v])
		swap(u, v);
	for(int i = LOG-1; i >= 0; i--)
		if(~sp[i][u] && dep[sp[i][u]] >= dep[v])
			u = sp[i][u];
	if(u == v) return u;
	for(int i = LOG-1; i >= 0; i--)
		if(~sp[i][u] && ~sp[i][v] && sp[i][u] != sp[i][v])
			u = sp[i][u], v = sp[i][v];
	return sp[0][u];
}

int dist(int a, int b){
	int tmp = query(in[a], in[b]);
	// print(a, b, tmp, dep[getlca(a, b)]);
	return dep[a]+dep[b]-2*tmp;
}

int kth(int a, int b, int k){
	if(dep[a]-query(in[a], in[b]) >= k){
		//jump a k times
		for(int i = __lg(k); i >= 0; i--)
			if(k&(1<<i))
				a = sp[i][a];
		return a;
	}
	else{		
		//jump b dist(a, b)-k times
		k = dist(a, b)-k;
		for(int i = __lg(k); i >= 0; i--)
			if(k&(1<<i))
				b = sp[i][b];
		return b;
	}
}

int main(){
	scan(n, q);
	for(int i = 0,a,b; i < n-1; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	memset(sp, -1, sizeof sp);
	memset(val, 0x3f, sizeof val);
	dfs(1, 0);
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= n; j++){
			int u = sp[i-1][j];
			if(~u) sp[i][j] = sp[i-1][u];
		}
	}
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j+(1<<i)-1 <= n+n+3; j++){
			val[i][j] = min(val[i-1][j], val[i-1][j+(1<<(i-1))]);
		}
	}

	while(q--){
		int a, b, c, d;
		scan(a, b, c, d);

		int tar = dist(c, d);
		int mx = min(dist(a, b), tar)-1;

		int l = 0, m, r = mx, ans = 1e9;
		while(l <= r){
			m = (l+r)/2;
			int id1 = kth(a, b, m), id2 = kth(a, b, m+1);
			//see if on and closer/farther
			int d1 = dist(id1, c) + dist(id1, d);
			int d2 = dist(id2, c) + dist(id2, d);

			//check time
			int toa = dist(a, id1);
			int toc = dist(c, id1);
			if(toa == toc and d1 == tar){
				ans = min(ans, m);
			}
			// print(m, id1, id2, d1, d2);
			
			if(d1 != d2){
				if(d1 < d2)
					r = m-1;
				else
					l = m+1;
				continue;
			}
			if(toa < toc) //too soon
				l = m+1;
			else
				r = m-1;
		}
		print(ans == 1e9 ? -1: ans);
	}
}