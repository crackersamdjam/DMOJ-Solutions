#include <bits/stdc++.h>
#define MM 102
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
pii mv[] = {{2,1},{2,-1},{1,2},{1,-2},{-1,2},{-1,-2},{-2,1},{-2,-1}};
const int inf = 0x3f3f3f3f;
int N,R,C,pr,pc,win,draw;
bool dp[MM][MM][MM];
void go(int move, int r, int c){
    //before pawn moves
    if(r == pr + move && c == pc && pr+move != R){
        win = min(win, move);
        dp[move][r][c] = 1;
        return;
    }
    if(r == pr+move+1 && c == pc){
        draw = min(draw, move);
        dp[move][r][c] = 1;
        return;
    }
    for(int i = 0,nr,nc; i < 8; i++){
        nr = r+mv[i].f, nc = c+mv[i].s;
        if(nr > 0 && nr <= R && nc > 0 && nc <= C && move+pr < R){
            if(!dp[move+1][nr][nc]){
                dp[move+1][nr][nc] = 1;
                go(move+1,nr,nc);
            }
        }
    }
}
int main(){
    int nr,nc;
    scanf("%d",&N);
    while(N--){
        memset(dp,0,sizeof(dp));
        win = draw = inf;
        scanf("%d%d%d%d%d%d",&R,&C,&pr,&pc,&nr,&nc);
        go(0, nr, nc);
        //keep track of how many moves have passed
        //at move i, pawn will be on row pr + i
        if(win < inf)
            printf("Win in %d knight move(s).\n", win);
        else if(draw < inf)
            printf("Stalemate in %d knight move(s).\n",draw);
        else
            printf("Loss in %d knight move(s).\n", R-pr-1);
    }
    return 0;
}