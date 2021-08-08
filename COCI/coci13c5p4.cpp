#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1005;

void go(int &a, int b){
	a = max(a, b);
}

int n, K, dp[MM][MM][8], a[MM][3], ans;
// mask of which ones are free
int vh[MM][8], vv[MM][8];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>K;
	memset(dp, -0x3f, sizeof dp);
	dp[0][0][0] = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < 3; j++){
			cin>>a[i][j];
			for(int t = 0; t < 8; t++){
				if((1<<j)&t){
					vv[i][t] += a[i][j];
					vv[i+1][t] += a[i][j];
				}
			}
		}
		vh[i][1+2] = a[i][0]+a[i][1];
		vh[i][2+4] = a[i][1]+a[i][2];
	}

	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= K; j++){
			for(int m = 0; m < 8; m++){
				go(dp[i][j][7^m], dp[i-1][j][7]);
				for(int h: {0, 1+2, 2+4}){
					if((m&h) != h) continue;

					// remove from free
					int rm = m^h;
					int k = j-!!h;
					int add = vh[i][h];
					if(k >= 0) go(dp[i][j][7^m], dp[i-1][k][rm]+add);

					for(int t = 0; t < 8; t++){
						//which ones to take
						if((rm&t) != t) continue;
						int kk = k-__builtin_popcount(t);
						int add2 = add + vv[i][t];
						if(kk >= 0) go(dp[i][j][7^m], dp[i-1][kk][t]+add2);
					}
				}
			}
			//remove extra free ones
			for(int m = 0; m < 8; m++){
				for(int mm = 0; mm < 8; mm++){
					if((m&mm) == m){
						go(dp[i][j][m], dp[i][j][mm]);
					}
				}
			}
		}
	}
	for(int m = 0; m < 8; m++)
		ans = max(ans, dp[n][K][m]);
	cout<<ans<<'\n';
}