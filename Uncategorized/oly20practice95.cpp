#ifdef ONLINE_JUDGE
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif
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
using pii = pair<int, int>;
const int MM = 2e5+5, LOG = 20;

int tc, n, m, q, dfn[MM], low[MM], t, tt, ttt;
vector<int> adj[MM], adj2[MM], in[MM];
stack<pii> st;
set<int> art;
int dep[MM], sp[LOG][MM], val[LOG][MM];

void dfs2(int cur, int pre){
	dfn[cur] = ++ttt;
	dep[cur] = dep[pre]+1;
	sp[0][cur] = pre;
	val[0][cur] = (cur <= n);
	for(int u: adj2[cur])
		if(u != pre)
			dfs2(u, cur);
}

int getlca(int u, int v){
	if(dep[u] < dep[v])
		swap(u, v);
	for(int i = LOG-1; i >= 0; i--){
		if(~sp[i][u] && dep[sp[i][u]] >= dep[v])
			u = sp[i][u];
	}
	if(u == v)
		return u;
	for(int i = LOG-1; i >= 0; i--){
		if(~sp[i][u] && ~sp[i][v] && sp[i][u] != sp[i][v]){
			u = sp[i][u];
			v = sp[i][v];
		}
	}
	return sp[0][u];
}

int query(int a, int b){
	int lca = getlca(a, b), ret = 0;
	for(int i = LOG-1; i >= 0; i--){
		if(dep[a] >= dep[lca]+(1<<i)){
			ret += val[i][a];
			a = sp[i][a];
		}
	}
	for(int i = LOG-1; i >= 0; i--){
		if(dep[b] >= dep[lca]+(1<<i)){
			ret += val[i][b];
			b = sp[i][b];
		}
	}
	return ret; // + val[0][lca];
}

void process(int u, int v){
	if(st.empty()) return;
	tt++;
	while(st.size()){
		pii e = st.top(); st.pop();
		in[tt].push_back(e.first);
		in[tt].push_back(e.second);
		if(e == pii(u, v))
			break;
	}
}

void dfs(int cur, int pre){
	dfn[cur] = low[cur] = ++t;
	int ch = 0;
	for(int u: adj[cur]){
		if(u == pre) continue;
		if(!dfn[u]){
			ch++;
			st.emplace(cur, u);
			dfs(u, cur);

			low[cur] = min(low[cur], low[u]);
			
			if((pre == -1 && ch > 1) or (pre != -1 && low[u] >= dfn[cur])){
				art.insert(cur);
				process(cur, u);
			}
		}
		else
			low[cur] = min(low[cur], dfn[u]);
	}
}

int main(){
	scan(tc);
	while(tc--){
		scan(n, m);
		for(int i = 0,a,b; i < m; i++){
			scan(a, b);
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		for(int i = 1; i <= n; i++){
			if(!dfn[i]){
				dfs(i, -1);
				process(-1, -1);
			}
		}
		for(int i = 1; i <= tt; i++){
			sort(all(in[i]));
			in[i].erase(unique(all(in[i])), in[i].end());
			for(int u: in[i]){
				adj2[n+i].push_back(u);
				adj2[u].push_back(n+i);
			}
		}
		tt += n;
		// cout<<"graph"<<endl;for(int i = 1; i <= tt; i++)for(int u: adj2[i])print(i, u);cout<<"done"<<endl;

		// cout<<"art ";for(int i: art)cout<<i<<' ';cout<<endl;
		memset(sp, -1, sizeof sp);
		dfs2(1, 0);
		for(int i = 1; i < LOG; i++){
			for(int j = 1; j <= tt; j++){
				int u = sp[i-1][j];
				if(~u){
					sp[i][j] = sp[i-1][u];
					val[i][j] = val[i-1][j] + val[i-1][u];
				}
			}
		}

		scan(q);
		int k, a;
		while(q--){
			scan(k);
			int ans = 0;
			vector<int> v;
			for(int i = 0; i < k; i++){
				scan(a);
				v.emplace_back(a);
			}
			sort(all(v), [](int x, int y){
				return dfn[x] < dfn[y];
			});
			v.emplace_back(v[0]);
			int lca = v[0];
			for(int i = 0; i < k; i++){
				int res = query(v[i], v[i+1]);
				ans += res;
				lca = getlca(lca, v[i]);
				// print(v[i], v[i+1], res);
			}
			if(lca <= n)
				ans += 2;
			ans -= k+k;
			print(ans/2);
		}	

		for(int i = 0; i <= tt; i++){
			adj[i].clear();
			adj2[i].clear();
			in[i].clear();
		}
		t = tt = ttt =0;
		assert(st.empty());
		art.clear();
		memset(val, 0, sizeof val);
		memset(dep, 0, sizeof dep);
		memset(dfn, 0, sizeof dfn);
		memset(low, 0, sizeof low);
		// cout<<"***********"<<endl;
	}
}