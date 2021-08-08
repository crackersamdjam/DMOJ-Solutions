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
using ld = double;
const int MM = 301;

int t, n, k, v[MM];
ld c[MM][MM], ans;
map<int, int> mp;
int dis[MM][MM];
bool in[MM];

int main(){
	c[0][0] = 1;
	for(int i = 1; i < MM; i++){
		c[i][0] = 1;
		for(int j = 1; j < MM; j++)
			c[i][j] = c[i-1][j] + c[i-1][j-1];
	}
	cout<<fixed<<setprecision(9);
	scan(t);
	while(t--){
		scan(n, k);
		memset(dis, 0x3f, sizeof dis);
		for(int i = 0,a,b; i < n-1; i++){
			scan(a, b);
			dis[a][b] = dis[b][a] = 1;
		}
		map<int, int> mp; //cord comp
		for(int i = 1; i <= n; i++){
			scan(v[i]);
			mp[v[i]] = 0;
			dis[i][i] = 0;
		}
		int x = 0;
		for(auto &i: mp)
			i.second = ++x;
		for(int i = 1; i <= n; i++)
			v[i] = mp[v[i]];

		for(int m = 1; m <= n; m++){
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					dis[i][j] = min(dis[i][j], dis[i][m]+dis[m][j]);
				}
			}
		}

		for(int a = 1; a <= n; a++){
			for(int b = a+1; b <= n; b++){
				int cnt = 0, sz = 0;
				for(int i = 1; i <= n; i++){
					if(dis[a][i] > dis[a][b] or (dis[a][i] == dis[a][b] and i < b)) continue;
					if(dis[b][i] > dis[b][a] or (dis[b][i] == dis[b][a] and i < a)) continue;
					
					//can be taken
					cnt++;
					
					//on the path
					if(dis[a][i]+dis[i][b] == dis[a][b]){
						if(!in[v[i]]){
							in[v[i]] = 1;
							sz++;
						}
					}
				}
				ans += sz*c[cnt-2][k-2];
				memset(in, 0, sizeof in);
			}
		}
		ans /= c[n][k];
		cout<<ans<<'\n';
		ans = 0;
	}
}

/*
every pair of endpoints, get dist of all other nodes to one of these
count how many do not make it longer than diameter or by tiebreak condition
add (cnt-2 choose k-2) to ans
*/