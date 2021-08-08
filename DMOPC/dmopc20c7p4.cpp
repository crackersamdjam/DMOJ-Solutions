#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 2e5+2, LOG = 18;

int n, q, dep[MM], sp[LOG][MM], t, in[MM], out[MM], bit[MM*2], on[MM];
vector<int> adj[MM];

void update(int i, int x){
	for(; i < MM*2; i += i&-i)
		bit[i] += x;
}

int query(int i){
	int x = 0;
	for(; i; i -= i&-i)
		x += bit[i];
	return x;
}

int getlca(int u, int v){
	if(dep[u] < dep[v])
		swap(u, v);
	for(int i = LOG-1; i >= 0; i--){
		if(~sp[i][u] and dep[sp[i][u]] >= dep[v])
			u = sp[i][u];
	}
	if(u == v)
		return u;
	for(int i = LOG-1; i >= 0; i--){
		if(~sp[i][u] and ~sp[i][v] and sp[i][u] != sp[i][v]){
			u = sp[i][u];
			v = sp[i][v];
		}
	}
	return sp[0][u];
}

void dfs(int cur, int pre){
	dep[cur] = dep[pre]+1;
	sp[0][cur] = pre;
	in[cur] = ++t;
	for(int u: adj[cur]){
		if(u != pre)
			dfs(u, cur);
	}
	out[cur] = ++t;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	
	cin>>n>>q;
	for(int i = 0,a,b; i < n-1; i++){
		cin>>a>>b;
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	
	memset(sp, -1, sizeof sp);
	
	dfs(1, 0);
	
	for(int i = 1; i < LOG; i++){
		for(int j = 1; j <= n; j++){
			if(~sp[i-1][j]){
				sp[i][j] = sp[i-1][ sp[i-1][j] ];
			}
		}
	}
	
	for(int z = 0,op,a,b; z < q; z++){
		cin>>op>>a;
		if(op == 1){
			int v = on[a] ? -1 : 1;
			on[a] ^= 1;
			a = sp[0][a]; //update parent
			if(a){
				update(in[a], v);
				update(out[a], -v);
			}
		}
		else{
			cin>>b;
			int l = getlca(a, b), ans;
			if(in[a] > in[b])
				swap(a, b);
			
			ans = query(in[b]) + query(in[a]) - query(in[l]) - query(in[l]-1) + on[l] + on[sp[0][l]];
			//down to b, down to a, subtract but also include in[l]'out value (its children), on[l], par of l
			
			cout<<ans<<'\n';
		}
	}
}