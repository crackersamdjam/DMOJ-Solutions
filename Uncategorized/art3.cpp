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
const int MM = 305;

int n, m, k, q, g[MM];
vector<int> adj[MM];
bool vis[MM];
vector<vector<int>> v;
bool dp[MM][16][16][MM*2];
int op[MM][16][16][MM*2];
int pre[MM][16][16][MM*2];

void dfs(int cur){
	vis[cur] = 1;
	v.back().emplace_back(cur);
	for(int u: adj[cur]){
		if(!vis[u])
			dfs(u);
	}
}

int cnt(int i, int a, int f){
	int ret = 0;
	for(int j: v[i]){
		int t = g[j];
		if(f == 1)
			t++;
		else if(f == 2)
			t *= 2;
		else if(f == 3)
			t ^= 15;

		ret += t == a;
	}
	return ret;
}

int main(){
	scan(n, m, k, q);
	for(int i = 1; i <= n; i++)
		scan(g[i]);
	for(int i = 0,a,b; i < m; i++){
		scan(a, b);
		adj[a].emplace_back(b);
		adj[b].emplace_back(a);
	}
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			v.emplace_back();
			dfs(i);
			sort(all(v.back()));
		}
	}
	//want v with smallest v[0] at end
	sort(all(v), [](auto &x, auto &y){
		return x[0] > y[0];
	});
	v.insert(v.begin(), vector<int>());

	for(int a = 1; a <= k; a++)
		for(int b = 1; b <= k; b++)
			dp[0][a][b][MM] = 1;

	for(int i = 1; i < (int)size(v); i++){
		for(int a = 1; a <= k; a++){
			for(int b = 1; b <= k; b++){
				for(int t = 3; t >= 0; t--){ //prefer lexico least
					int val = cnt(i, a, t) - cnt(i, b, t);

					// if(a == 1 and b == 3){
						// print(i, t, val);
					// }

					for(int j = 0; j < MM*2; j++){
						if(j+val >= 0 and j+val < MM*2 and dp[i-1][a][b][j+val]){
							dp[i][a][b][j] = 1;
							op[i][a][b][j] = t;
							pre[i][a][b][j] = j+val;
						}
						// if(j-val >= 0 and dp[i-1][a][b][j-val]){
						// 	dp[i][a][b][j] = 1;
						// 	op[i][a][b][j] = t;
						// 	pre[i][a][b][j] = j-val;
						// }
					}
				}
			}
		}
	}
	int ed = (int)size(v)-1;
	while(q--){
		int x, y, z;
		scan(x, y, z);
		int fa = dp[ed][x][y][MM+z], fb = dp[ed][x][y][MM-z];
		if(fa|fb){
			vector<int> out = {99999999};
			if(fa){
				vector<int> out1(n+1, 0);
				fill(all(out1), 0);
				for(int t = ed, val = MM+z; t; t--){
					for(int j: v[t]){
						out1[j] = op[t][x][y][val];
					}
					val = pre[t][x][y][val];
				}
				out = min(out, out1);
			}
			if(fb){
				vector<int> out1(n+1, 0);
				fill(all(out1), 0);
				for(int t = ed, val = MM-z; t; t--){
					for(int j: v[t]){
						out1[j] = op[t][x][y][val];
					}
					val = pre[t][x][y][val];
				}
				out = min(out, out1);
			}

			puts("YES");
			for(int i = 1; i <= n; i++)
				printf("%d ", out[i]);
			pc(10);
		}
		else{
			puts("NO");
		}
	}

	// for(int i = 0; i <= ed; i++){
	// 	for(int j = MM-n; j <= MM+n; j++)
	// 		cout<<dp[i][1][3][j]<<' ';
	// 	cout<<endl;
	// }
}