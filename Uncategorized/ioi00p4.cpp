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
const int MM = 303;

int m, n, k, has[MM], f[MM][MM], s[MM][MM];
bool vis[MM], done[MM];
vector<int> in[MM], adj[MM];

int main(){
	scan(m, n, k);
	for(int i = 1,a; i <= k; i++){
		scan(a);
		has[a] = 1;
	}
	for(int i = 1,l; i <= m; i++){
		scan(l);
		in[i].resize(l);
		for(int j = 0; j < l; j++)
			scan(in[i][j]);
		in[i].emplace_back(in[i][0]);
		for(int j = 1; j <= l; j++){
			int a = in[i][j-1], b = in[i][j];
			if(a > b) swap(a, b);
			if(!f[a][b])
				f[a][b] = i;
			else
				s[a][b] = i;
		}
		// in[i].pop_back();
	}
	pair<int, int> ans = {1e9, -1};
	for(int st = 1; st <= m; st++){
		//start at st
		int sum = 0;
		memset(vis, 0, sizeof vis);
		memset(done, 0, sizeof done);
		queue<pair<int, int>> q;
		q.emplace(st, 0);
		while(size(q)){
			int cur, curd;
			tie(cur, curd) = q.front(); q.pop();
			// pr("bfs", cur, curd);
			for(int j = 1; j < (int)size(in[cur]); j++){
				int a = in[cur][j-1], b = in[cur][j];
				if(!done[a] and has[a]){
					sum += curd;
					done[a] = 1;
				}
				if(a > b) swap(a, b);
				if(cur == f[a][b])
					swap(f[a][b], s[a][b]);
				int u = f[a][b];
				if(u and !vis[u]){
					vis[u] = 1;
					q.emplace(u, curd+1);
				}
			}
		}
		ans = min(ans, {sum, st});
		// pr("st", st, sum, size(in[st]));
	}
	print(ans.first, ans.second);
}