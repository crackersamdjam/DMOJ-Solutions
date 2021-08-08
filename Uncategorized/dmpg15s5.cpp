#include <bits/stdc++.h>
using namespace std;
#define MM 10002
bool dif[MM][MM];
int main() {
    int N,M; scanf("%d%d",&N,&M);
    for(int i = 0,x,y,w,h; i < M; i++){
        scanf("%d%d%d%d",&x,&y,&w,&h);
        x++; y++;
        dif[x][y] ^= 1;
        dif[x][y+h] ^= 1;
        dif[x+w][y] ^= 1;
        dif[x+w][y+h] ^= 1;
    }
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dif[i][j] ^= dif[i-1][j] ^ dif[i][j-1] ^ dif[i-1][j-1];
            if(dif[i][j])
                cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}