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
const int MM = 1e6+5;

int h, j, n, psa[MM], dis[MM];

int main(){
	scan(h, j, n);
	for(int i = 0,a,b; i < n; i++){
		scan(a, b);
		psa[a]++;
		psa[b+1]--;
	}
	for(int i = 1; i <= h; i++){
		psa[i] += psa[i-1];
	}

	int l = 1;

	queue<int> q;
	memset(dis, 0x3f, sizeof dis);
	dis[0] = 0;
	q.emplace(0);
	while(size(q)){
		int cur = q.front(); q.pop();
		{
			int u = min(h, cur+j);
			if(!psa[u] and dis[cur]+1 < dis[u]){
				dis[u] = dis[cur]+1;
				q.emplace(u);
			}
		}
		while(l <= cur){
			int u = l;
			if(!psa[u] and dis[cur]+1 < dis[u]){
				dis[u] = dis[cur]+1;
				q.emplace(u);
			}
			l++;
		}
	}
	print(dis[h] < 1e9 ? dis[h] : -1);
}