#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 101;

int N, Q;
ll dis[MM][MM][MM];

int main(){
    
    memset(dis, 0x3f, sizeof dis);
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++){
        for(int j = 0,v; j < N; j++){
            scanf("%d", &v);
            if(v || i == j)
                dis[1][i][j] = v;
        }
    }
    
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                dis[1][i][j] = min(dis[1][i][j], dis[1][i][k] + dis[1][k][j]);
            }
        }
    }
    
    for(int t = 2; t <= N; t++){
        for(int k = 0; k < N; k++){
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    dis[t][i][j] = min(dis[t][i][j], max(dis[t-1][i][k], dis[1][k][j]));
                }
            }
        }
    }
    
    scanf("%d", &Q);
    
    for(int i = 0,a,b,c; i < Q; i++){
        scanf("%d%d%d", &a, &b, &c);
        printf("%lld\n", dis[c][a-1][b-1] == 0x3f3f3f3f3f3f3f3f? 0: dis[c][a-1][b-1]);
    }
    
    return 0;
}