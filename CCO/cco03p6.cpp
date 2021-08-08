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
using ld = double;
const int MM = 105;

int tc, n, m, f, s;
array<array<array<ld, MM*2>, MM>, MM> dis;
bool inq[MM][MM][MM*2];
queue<array<int, 3>> q;
array<array<ld, MM>, MM> at;

int mx[] = {1, -1, 0, 0};
int my[] = {0, 0, 1, -1};

int main(){
	cin>>tc;
	while(tc--){
		for(auto &i: at)
			i.fill(1e9);
		for(auto &i: dis)
			for(auto &j: i)
				j.fill(1e9);

		cin>>n>>m>>f>>s;
		f = min(f, n+m);

		// pr("in", n, m, f, s);

		while(s--){
			int a, b; ld x;
			cin>>a>>b>>x;
			at[a][b] = min(at[a][b], x);
		}

		dis[1][1][f] = 0;
		q.push({1, 1, f});
		while(size(q)){
			auto [x, y, k] = q.front(); q.pop();
			inq[x][y][k] = 0;
			ld curd = dis[x][y][k];

			// pr(x, y, k, curd, at[x][y]);

			for(int kk = k+1; kk <= f; kk++){
				ld v = curd + (kk-k)*at[x][y];
				if(v < dis[x][y][kk]){
					dis[x][y][kk] = v;
					if(!inq[x][y][kk]){
						q.push({x, y, kk});
						inq[x][y][kk] = 1;
					}
				}
			}
			if(k) for(int t = 0; t < 4; t++){
				int a = x+mx[t], b = y+my[t];
				if(a and b and a <= n and b <= m and curd < dis[a][b][k-1]){
					dis[a][b][k-1] = curd;
					if(!inq[a][b][k-1]){
						q.push({a, b, k-1});
						inq[a][b][k-1] = 1;
					}
				}
			}
		}
		ld ans = 1e9;
		for(int i = 0; i <= f; i++){
			ans = min(ans, dis[n][m][i]);
			// pr("i", i, dis[n][m][i]);
		}
		if(ans == 1e9)
			puts("Stranded on the shoulder");
		else
			printf("%.2lf\n", ans);
	}
}