#include <bits/stdc++.h>
using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

const int MM = 1e5+2;
int n, m, k, dp[MM][26], dis[26][26], sum[MM][26];
string s;

int main(){
    init();
    cin >> n >> m >> k >> s;
    for(char &c: s)
        c -= 'a';
    s = " "+s;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++)
            cin >> dis[i][j];
    }

    for(int k = 0; k < m; k++){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }

    memset(dp, 0x3f, sizeof dp);
    for(int i = 1; i <= n; i++){
        for(int c = 0; c < m; c++)
            sum[i][c] = sum[i-1][c] + dis[s[i]][c];
    }

    for(int c = 0; c < m; c++)
        dp[k][c] = sum[k][c], dp[0][c] = 0;

    for(int i = k+1; i <= n; i++){
        for(int c = 0; c < m; c++){
            dp[i][c] = dp[i-1][c] + sum[i][c] - sum[i-1][c];
            for(int cc = 0; cc < m; cc++){
                dp[i][c] = min(dp[i][c], dp[i-k][cc] + sum[i][c] - sum[i-k][c]);
            }
        }
    }

    cout << *min_element(dp[n], dp[n]+m) << '\n';
    
    return 0;
}
/*
dp[i][c]
valid seq ending at index i with character c
dp[i][c] = max(max{dp[i-k][cc] + sum[i] - sum[i-k]}, dp[i-1][c] + dis[a[i]][c])
sum[i][c] = sum of costs to get prefix i to character c
*/