#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define f first
#define s second

using namespace std;
using pii = pair<int, int>;
const int MM = 150005, TWO = 1e8, inf = 1e9;

int n, m, p, k;
vector<pii> in[MM];
pii nx[MM][2];
int dis[MM][2], f[MM], s[MM], len, id, cnt[MM], cnta[MM], cntb[MM];
bool vis[MM][2];
//0 = go to best next one
//1 = go to second best one

#ifndef ONLINE_JUDGE
void answer(int X){
	print(X);
}
#endif

void go(int cur, bool f, int d){
	vis[cur][f] = 1;
	int u, w;
	tie(u, w) = nx[cur][f];
	if(u == p){
		len = d+1;
		id = w;
		return;
	}
	if(!vis[u][w])
		go(u, w, d+1);
}

int dfs(int cur, bool f){
	if(~dis[cur][f])
		return dis[cur][f];
	dis[cur][f] = inf;
	return dis[cur][f] = dfs(nx[cur][f].first, nx[cur][f].second)+1;
}

void count_routes(int N, int M, int P, int R[][2], int Q, int G[]){
	n = N, m = M, p = P, k = Q;
	for(int i = 0; i < m; i++){
		in[R[i][0]].emplace_back(i, R[i][1]);
		in[R[i][1]].emplace_back(i, R[i][0]);
	}
	for(int i = 0; i < n; i++){
		sort(all(in[i]));
		// assert(size(in[i]));
		if(size(in[i]) == 1)
			in[i].emplace_back(in[i][0]);
		else
			in[i].resize(2);
	}
	for(int i = 0,u,w; i < n; i++){
		tie(w, u) = in[i][0];
		nx[i][0] = {u, (w == in[u][0].first)};
		tie(w, u) = in[i][1];
		nx[i][1] = {u, (w == in[u][0].first)};
	}
	//find "final" cycle distances
	memset(vis, 0, sizeof vis);
	len = inf, id = -1;
	go(p, 0, 0);
	int lena = len, ida = id;

	memset(vis, 0, sizeof vis);
	len = inf, id = -1;
	go(p, 1, 0);
	int lenb = len, idb = id;

	// either no cycle, 0/1 itself cycle, lead into other cycle, or large cycle with both...

	int moda, offa, modb, offb;
	if(ida == -1){
		moda = inf;
		offa = inf;
	}
	else if(ida == 0){
		moda = lena;
		offa = 0;
	}
	else{
		moda = lenb;
		offa = lena;
	}

	if(idb == -1){
		modb = inf;
		offb = inf;
	}
	else if(idb == 1){
		modb = lenb;
		offb = 0;
	}
	else{
		modb = lena;
		offb = lenb;
	}
	int mod2 = (moda+modb);

	if(ida == 1 and idb == 0){
		//large cycle with both
		// abort();
	}

	memset(dis, -1, sizeof dis);
	dis[p][0] =  0;
	dis[p][1] = TWO; //to tell apart
	
	for(int i = 0; i < N; i++){
		dfs(i, 0);
	}

	for(int i = 0; i < Q; i++){
		int v = G[i], ans = 0;
		for(int j = 0; j < n; j++){
			// int l = dfs(j, 0);
			int l = dis[j][0];
			if(l >= inf or l == -1) continue;

			//large cycle with both
			if(ida == 1 and idb == 0){
				if(l >= TWO){
					l -= TWO;
					if(l <= v){
						if((l-v)%mod2 == 0 or (l+offb-v)%mod2 == 0)
							ans++;
					}
				}
				else{
					if(l <= v){
						if((l-v)%mod2 == 0 or (l+offa-v)%mod2 == 0)
							ans++;
					}
				}
				continue;
			}
			
			if(l >= TWO){
				l -= TWO;
				//second cycle
				if(l == v or (l+offb <= v and (l+offb-v)%modb == 0))
					ans++;
			}
			else{
				if(l == v or (l+offa <= v and (l+offa-v)%moda == 0))
					ans++;
			}
		}
		answer(ans);
	}
}

#ifndef ONLINE_JUDGE
int main(){
	int N, M, P;
	scan(N, M, P);
	int R[M][2];
	for(int i = 0; i < M; i++){
		scan(R[i][0], R[i][1]);
		// print(R[i][0], R[i][1], i);
	}
	int Q;
	scan(Q);
	int G[Q];
	for(int i = 0; i < Q; i++)
		scan(G[i]);
	count_routes(N, M, P, R, Q, G);

	if(0){
		int G[] = {3};
		int R[][2] = {{1, 2}, {0, 1}, {0, 3}, {3, 4}, {4, 5}, {1, 5}};
		count_routes(6, 6, 0, R, 1, G);
	}
	if(0){
		int G[] = {3, 1};
		int R[][2] = {{1, 0}, {1, 2}, {3, 2}, {1, 3}, {4, 2}};
		count_routes(5, 5, 2, R, 2, G);
	}
}
#endif