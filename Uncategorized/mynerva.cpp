#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef pair<int, int> pii;
const int MM = 5e5+5;

int n, m, qq;
vector<pair<int, int>> adj[MM];
int dis[MM], mx[MM], mn[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;

int main(){
	scan(n, m);
	while(m--){
		int a, b, c;
		scan(a, b, c);
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
	memset(dis, 0x3f, sizeof dis);
	q.emplace(dis[1] = 0, 1);
	while(q.size()){
		int cur = q.top().second, d = q.top().first; q.pop();

		for(auto e: adj[cur]){
			int u = e.first;
			if(d+1 < dis[u]){
				q.emplace(dis[u] = d+1, u);
				mx[u] = mx[cur]+e.second;
				mn[u] = mn[cur]+e.second;
			}
			else if(d+1 == dis[u]){
				mx[u] = max(mx[u], mx[cur]+e.second);
				mn[u] = min(mn[u], mn[cur]+e.second);
			}
		}
	}

	scan(qq);
	while(qq--){
		int a; char s[10];
		scan(a); scanf("%s", s);
		print(dis[a], s[0] == 'W' ? mx[a] : mn[a]);		
	}
}