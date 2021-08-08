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
const int MM = 3005;

pair<int, int> at[MM*MM];
int psa[MM][MM];

int rectangle(int n,int m,int x,int y,int a[3001][3001]){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			at[a[i][j]] = {i, j};
		}
	}
	int tar = x*y/2;
	int l = 1, k, r = n*m;
	
	while(l <= r){
		k = (l+r)/2;
		memset(psa, 0, sizeof psa);
		for(int t = 1,i,j; t <= k; t++){
			tie(i, j) = at[t];
			psa[i][j]++;
			psa[i][min(m, j+y)]--;
			psa[min(n, i+x)][j]--;
			psa[min(n, i+x)][min(m, j+y)]++;
		}
		int ok = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				if(i) psa[i][j] += psa[i-1][j];
				if(j) psa[i][j] += psa[i][j-1];
				if(i and j) psa[i][j] -= psa[i-1][j-1];
				if(psa[i][j] > tar){
					ok = 1;
					break;
				}
			}
		}
		if(ok) r = k-1;
		else l = k+1;
	}
	return l;
}

#ifndef ONLINE_JUDGE
int main(){
	int R,C,H,W,Q[3001][3001],i,j,ans;
   scanf("%d%d%d%d",&R,&C,&H,&W);
   for (i=0;i<R;i++) for (j=0;j<C;j++) scanf("%d",&Q[i][j]);
   ans = rectangle(R,C,H,W,Q);
   printf("%d\n",ans);
   return 0;
}
#endif