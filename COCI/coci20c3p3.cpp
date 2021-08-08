#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;
constexpr int MM = 2005;
constexpr ll mod = 1e9+7, base = 131;

int n, m;
char s[MM][MM];
ll a[MM][MM], b[MM][MM];
ll p[MM*MM];
//a just row
//b is row (cutoff length at m) then col

ll getrow(int i, int l, int r){
	return (a[i][r] - a[i][l]*p[r-l]%mod+mod)%mod;
}

ll getrows(int l, int r, int i){
	return (b[r][i] - b[l][i]*p[(r-l)*m]%mod+mod)%mod;
}

int main(){
	scanf("%d%d", &n, &m);
	p[0] = 1;
	for(int i = 1; i <= n*m; i++){
		p[i] = p[i-1]*base%mod;
	}
	for(int i = 1; i <= n; i++){
		scanf("%s", s[i]+1);
		for(int j = m+1; j <= 2*m; j++)
			s[i][j] = s[i][j-m];
		for(int j = 1; j <= 2*m; j++){
			s[i+n][j] = s[i][j];
		}
	}

	for(int i = 1; i <= 2*n; i++){
		for(int j = 1; j <= 2*m; j++){
			b[i][j] = a[i][j] = (a[i][j-1]*base + s[i][j])%mod;
			if(j > m){
				b[i][j] = (b[i][j] - a[i][j-m]*p[m]%mod +mod)%mod;
			}
		}
	}

	for(int i = 1; i <= 2*n; i++){
		for(int j = 1; j <= 2*m; j++){
			b[i][j] = (b[i-1][j]*p[m] + b[i][j])%mod;
		}
	}

	array<int, 2> best = {0, 0}, cur;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cur = {i, j};
			int l = 1, r = n;
			while(l <= r){
				int k = l+r>>1;
				ll va = getrows(best[0], best[0]+k, best[1]+m);
				ll vb = getrows(cur[0], cur[0]+k, cur[1]+m);
				if(va != vb)
					r = k-1;
				else
					l = k+1;
			}
			int row = l;

			l = 1, r = m;
			while(l <= r){
				int k = l+r>>1;
				ll va = getrow(best[0]+row, best[1], best[1]+k);
				ll vb = getrow(cur[0]+row, cur[1], cur[1]+k);
				if(va != vb)
					r = k-1;
				else
					l = k+1;
			}
			int col = l;
			if(s[cur[0]+row][cur[1]+col] < s[best[0]+row][best[1]+col]){
				best = cur;
			}
		}
	}
	for(int i = best[0]+1; i <= best[0]+n; i++){
		for(int j = best[1]+1; j <= best[1]+m; j++){
			printf("%c", s[i][j]);
		}
		printf("\n");
	}
}