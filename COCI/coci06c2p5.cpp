#include <bits/stdc++.h>
#define gc getchar_unlocked
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int MM = 401;
int R,C, a[MM][MM];
int main(){
    scanf("%d%d",&R,&C);
    for(int i = 1; i <= R; i++){
        gc();
        for(int j = 1; j <= C; j++){
            a[i][j] = a[i][j-1] + (gc() == 'X');
        }
    }
    int ans = 0, sum, best;
    for(int l = 1; l <= C; l++){
        for(int r = l; r <= C; r++){
            sum = 0, best = 0;
            for(int i = 1; i <= R; i++){
                if(a[i][r] == a[i][l-1])
                    best = max(best, ++sum);
                else
                    sum = 0;
            }
            if(best)
                ans = max(ans, (best+(r-l+1))*2-1);
        }
    }
    printf("%d\n", ans);
    return 0;
}