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
using pii = pair<int, int>;
#define f first
#define s second
const int MM = 4005;

int n, m, ans;
int mx[] = {1, -1, 0, 0}, my[] = {0, 0, 1, -1};
char a[MM][MM];
bool vis[MM][MM];

queue<pii> cur, nx;

int main(){
	scan(n, m);
	for(int i = 1; i <= n; i++){
		scanf("%s", a[i]+1);
	}
	nx.emplace(1, 1);
	vis[1][1] = 1;
	while(nx.size()){
		ans++;
		swap(cur, nx);
		// print(ans);
		while(cur.size()){
			pii p = cur.front(); cur.pop();
			// print(p.f, p.s);
			for(int k = 0; k < 4; k++){
				pii r = {p.f+mx[k], p.s+my[k]};
				if((a[r.f][r.s] == 'R' or a[r.f][r.s] == 'F') and !vis[r.f][r.s]){
					vis[r.f][r.s] = 1;
					if(a[r.f][r.s] == a[p.f][p.s]){
						cur.emplace(r);
					}
					else{
						nx.emplace(r);
					}
				}
			}
		}
	}
	print(ans);
}