#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
const int MM = 2e5+5;

int n, m;
vector<int> adj[MM], v[MM];
int vis[MM], no, in[MM];

void dfs(int cur){
	vis[cur] = 1;
	for(int u: adj[cur]){
		if(!vis[u])
			dfs(u);
		else if(vis[u] == 1)
			no = 1;
	}
	vis[cur] = 2;
}

bool go(int lim){
	adj[0].clear();
	no = 0;
	for(int i = 1; i <= n; i++){
		adj[i].clear();
		adj[0].emplace_back(i);
		vis[i] = 0;
		in[i] = 1;
	}

	for(int i = 1; i <= lim; i++){
		for(int j = (int)size(v[i])-1; j; j--){
			adj[v[i][j-1]].emplace_back(v[i][j]);
			in[v[i][j]]++;
		}
	}

	dfs(0);
	return !no;
}

int main(){
	scan(n, m);
	for(int i = 1,k; i <= m; i++){
		scan(k);
		v[i].resize(k);
		for(int &j: v[i])
			scan(j);
	}
	int l = 1, r = m;
	while(l <= r){
		int lim = l+r>>1;
		if(go(lim))
			l = lim+1;
		else
			r = lim-1;
	}
	go(r); //to get the graph built

	priority_queue<int, vector<int>, greater<int>> q;
	q.emplace(0);
	vector<int> ans;
	while(size(q)){
		int cur = q.top(); q.pop();
		ans.emplace_back(cur);
		for(int u: adj[cur]){
			if(!--in[u]){
				q.emplace(u);
			}
		}
	}

	ans.erase(ans.begin());
	for(int i: ans)
		printf("%d ", i);
}