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
const int MM = 1e5+5;

int n, maxd[MM], mind[MM], dep[MM];
vector<int> adj[MM];
int lc[MM], rc[MM];

void dfs(int cur, int pre){
	if(cur == 0){
		maxd[cur] = mind[cur] = dep[cur] = dep[pre]+1;
		return;
	}
	mind[cur] = 1e9;
	dep[cur] = dep[pre]+1;

	for(int u: adj[cur]){
		dfs(u, cur);
		maxd[cur] = max(maxd[cur], maxd[u]);
		mind[cur] = min(mind[cur], mind[u]);
	}
}
int ans;
void go(int cur){
	if(cur == 0)
		return;
	int l = lc[cur], r = rc[cur];
	go(l);
	go(r);
	// print(cur, l, r, maxd[l], mind[l], maxd[r], mind[r]);

	if(maxd[cur]-mind[cur] > 1 || maxd[l]-mind[l]+maxd[r]-mind[r] > 1){
		print(-1);
		exit(0);
	}

	if(!l or !r){
		if(!l and r){
			ans++;
			// print(cur, ans);
		}
		return;
	}
	if(maxd[l] == mind[l] and maxd[r] == mind[r]){
		if(maxd[r] > maxd[l]){
			ans++;
		}
		return;
	}
	//either all l same or all r same
	if((maxd[r] == mind[r] and mind[l] < mind[r]) or (maxd[l] == mind[l] and maxd[r] > maxd[l])){
		ans++;
		// print(cur, ans);
	}
}

int main(){
	scan(n);
	for(int i = 1,a,b; i <= n; i++){
		scan(a, b);
		if(a == -1)
			a = 0;
		if(b == -1)
			b = 0;
		adj[i].emplace_back(a);
		adj[i].emplace_back(b);
		lc[i] = a, rc[i] = b;
	}
	dfs(1, 0);
	go(1);
	print(ans);
}