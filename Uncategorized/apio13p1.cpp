#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}
#define f first
#define s second

using namespace std;
typedef pair<int, int> pii;
constexpr int N = 9, MM = 502, inf = 0x3f3f3f3f;

int dp[N][N][MM][MM];
pii nx[MM][MM][4], st[10];
int n, m, k;
char a[MM][MM];
int mx[] = {-1, 0, 1, 0};
int my[] = {0, 1, 0, -1};

queue<pii> q;
vector<pii> inq, cnt[MM*MM]; //counting sort

inline void bfs(int l, int r){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(dp[l][r][i][j] < inf)
				cnt[dp[l][r][i][j]].emplace_back(i, j);
			
	for(int i = n*m; i >= 0; i--){
		inq.insert(inq.end(), all(cnt[i]));
		cnt[i].clear();
	}

	while(q.size() or inq.size()){
		int i, j, d, ni, nj;
		if(q.size() and (inq.empty() or dp[l][r][q.front().f][q.front().s] <= dp[l][r][inq.back().f][inq.back().s]))
			tie(i, j) = q.front(), q.pop();
		else
			tie(i, j) = inq.back(), inq.pop_back();

		d = dp[l][r][i][j];
		for(int p = 0; p < 4; p++){
			tie(ni, nj) = nx[i][j][p];
			if(d+1 < dp[l][r][ni][nj]){
				dp[l][r][ni][nj] = d+1;
				q.emplace(ni, nj);
			}
		}
	}
}

int main(){
	scan(k, m, n);
	memset(a, 'x', sizeof a);
	for(int i = 1; i <= n; i++){
		scanf("%s", a[i]+1);
		a[i][m+1] = 'x';
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i][j] == 'x')
				continue;
			if(a[i][j] >= '1' and a[i][j] <= '9')
				st[a[i][j]-'1'] = {i, j};

			for(int p = 0; p < 4; p++){
				int ni = i, nj = j, pp = p;
				while(a[ni][nj] != 'x'){
					if(a[ni][nj] == 'C')
						pp = (pp+1)&3;
					if(a[ni][nj] == 'A')
						pp = (pp+3)&3;
					
					nx[i][j][p] = {ni, nj};
					ni += mx[pp], nj += my[pp];
				}
			}
		}
	}

	memset(dp, 0x3f, sizeof dp);

	for(int l = 0; l < k; l++){
		dp[l][l][st[l].f][st[l].s] = 0;
		bfs(l, l);
	}

	for(int len = 0; len < k; len++){
		for(int l = 0; l+len < k; l++){
			int r = l+len;
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= m; j++)
					for(int mid = l; mid < r; mid++)
						dp[l][r][i][j] = min(dp[l][r][i][j], dp[l][mid][i][j] + dp[mid+1][r][i][j]);
			bfs(l, r);
		}
	}

	int ans = inf;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			ans = min(ans, dp[0][k-1][i][j]);

	print(ans == inf ? -1 : ans);
}