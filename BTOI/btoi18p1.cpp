#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+5;

int n, x, in[MM], indeg[MM], par[MM];
map<string, int> mp;
vector<int> adj[MM], adjr[MM];
bool vis[MM];
int dp[MM][2], ans, no;
// 0 = nopar, 1 = par

void dfs0(int cur){
	for(int u: adj[cur]){
		if(!--indeg[u])
			dfs0(u);
	}
	indeg[cur] = -1;
}

void dfs(int cur, int pre){
	dp[cur][0] = 1;
	dp[cur][1] = 0;
	if(adjr[cur].empty())
		return;
	int mx = 0;
	for(int u: adjr[cur]){
		if(u == pre || u == no)
			continue; //cut off edge

		dfs(u, cur);
		dp[cur][1] += dp[u][0];
		mx = min(mx, dp[u][1]-dp[u][0]);
	}
	dp[cur][0] = dp[cur][1] + mx + 1;
}

void fill(int cur){
	vis[cur] = 1;
	for(int u: adjr[cur])
		if(!vis[u])
			fill(u);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if(n%2)
		return cout<<"-1\n", 0;
	for(int i = 0,a,b; i < n; i++){
		string s, t;
		cin>>s>>t;
		a = mp[s] = mp[s] ? mp[s] : ++x;
		b = mp[t] = mp[t] ? mp[t] : ++x;
		if(a == b)
			continue;

		par[a] = b;
		adj[a].emplace_back(b);
		indeg[b]++;

		adjr[b].emplace_back(a);
		in[a]++;
	}
	for(int i = 1; i <= n; i++){
		if(par[par[i]] == i){
			vis[i] = 1;
			for(int j: adj[i])
				indeg[j]--;
			for(int j: adjr[i])
				in[j]--;
			adj[i].clear();
			adjr[i].clear();
		}
	}

	for(int i = 1; i <= n; i++){
		if(!indeg[i])
			dfs0(i);
	}
	for(int i = 1; i <= n; i++){
		if(!in[i] and !vis[i]){
			dfs(i, 0);
			ans += dp[i][0];
			fill(i);
		}
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i] and indeg[i] > 0 and indeg[par[i]] > 0){
			// i is in a cycle

			// adjr has edge par[i] -> i
			// disallow this edge
			int u = par[i];
			no = i;
			dfs(i, 0);
			int add = dp[i][0];

			//disallow another edge (to allow the previous one)
			for(int j: adjr[i]){
				if(indeg[j] > 0){
					u = j;
					break;
				}
			}

			if(u != par[i]){
				// i -> u
				no = u;
				dfs(u, 0);
				add = min(add, dp[u][0]);
			}

			ans += add;
			fill(i);
		}
	}
	cout<<ans<<'\n';
}