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

const int MM = 1005;

int n, m, k, psa[MM][MM];

inline int val(int a, int b, int c, int d){
	a--, b--, c += a, d += b;
	return psa[c][d]-psa[c][b]-psa[a][d]+psa[a][b];
}

struct st{
	int x, y, l, w, op, cmp;
} all[MM];
int cmp[MM], X, Y;
std::pair<int, std::pair<int, int>> ans = {-1, {-1, -1}};

int main(){
	scan(n, m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scan(psa[i][j]);
			psa[i][j] += psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1];
		}
	}
	scan(X, Y);
	scan(k);
	for(int t = 0; t < k; t++){
		scan(all[t].x, all[t].y, all[t].l, all[t].w, all[t].op, all[t].cmp);
	}
	for(int i = 1; i+X-1 <= n; i++){
		for(int j = 1; j+Y-1 <= m; j++){
			int cnt = 0;
			for(int t = 0; t < k and cnt+k-t > ans.first; t++){
				int ix = i+all[t].x-1, iy = j+all[t].y-1;
				//horizon
				if(!all[t].op)
					cnt += (val(ix, iy, all[t].l, all[t].w) < val(ix, iy+all[t].w, all[t].l, all[t].w) != all[t].cmp);
				else
					cnt += (val(ix, iy, all[t].l, all[t].w) < val(ix+all[t].l, iy, all[t].l, all[t].w) != all[t].cmp);
			}
			ans = std::max(ans, {cnt, {i, j}});
		}
	}
	print(ans.second.first, ans.second.second);
}