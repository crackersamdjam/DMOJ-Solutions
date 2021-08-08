#include <bits/stdc++.h>

using namespace std;
const short MM = 104, SS = 52;

int  X, Y, N;
int mx[] = {0, 1, -1, 0, 0}, my[] = {0, 0, 0, 1, -1};

struct st{
    short x, y, vx, vy;
} start, ed;

queue<st> q;

unsigned short dis[MM][MM][MM][MM];
bool no[MM][MM];


int gcd(int a, int b){
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main(){
    
    memset(dis, 0x7e, sizeof dis);
    memset(no, 0, sizeof no);
    
    unsigned short inf = dis[0][0][0][0];
    //print(inf);
    
    scanf("%d%d%d",&X,&Y,&N);
    scanf("%d%d",&start.x,&start.y);
    scanf("%d%d",&ed.x,&ed.y);
    for(int i = 0,a,b; i < N; i++){
        scanf("%d%d",&a,&b);
        no[a][b] = 1;
    }
    start.vx = start.vy = ed.vx = ed.vy = SS;
    //zero
    dis[start.x][start.y][SS][SS] = 0;
    q.push(start);
    
    while(!q.empty()){
        st cur = q.front(); q.pop();
        short curd = dis[cur.x][cur.y][cur.vx][cur.vy];
        
        for(int k = 0; k < 5; k++){
            st nx;
            nx.vx = cur.vx + mx[k] - SS;
            nx.vy = cur.vy + my[k] - SS;
            
            nx.x = cur.x + nx.vx;
            nx.y = cur.y + nx.vy;
            
            if(nx.x < 0 || nx.x > X || nx.y < 0 || nx.y > Y)
                continue;
            
            //make sure no wind in between
            int slope = abs(gcd(nx.vx, nx.vy));
            if(slope == 0)
                slope = 1;
            
            int ax = nx.vx / slope;
            int ay = nx.vy / slope;
            
            bool flag = 0;
            for(int i = cur.x, j = cur.y; i != nx.x || j != nx.y; i += ax, j += ay){
                /*
                if(i < 0 || i >= MM || j < 0 || j >= MM){
                    puts("why");
                    break;
                }
                 */
                if(no[i][j]){
                    flag = 1;
                    break;
                }
            }
            if(flag)
                continue;
            
            nx.vx += SS;
            nx.vy += SS;
            
            if(nx.vx < 0 || nx.vx >= MM || nx.vy < 0 || nx.vy >= MM)
                continue;
            
            /*
            if(nx.x < 0 || nx.x >= MM || nx.y < 0 || nx.y >= MM || nx.vx < 0 || nx.vx >= MM || nx.vy < 0 || nx.vy >= MM ){
                puts("nope");
                continue;
            }
            */
            
            if(!no[nx.x][nx.y] && (curd+1 < dis[nx.x][nx.y][nx.vx][nx.vy])){
                dis[nx.x][nx.y][nx.vx][nx.vy] = curd+1;
                q.push(nx);
            }
        }
    }
    
    int ans = dis[ed.x][ed.y][SS][SS];
    if(ans == inf)
        ans = -1;
    printf("%d\n", ans);
    
    /*
    for(int i = 0; i <= X; i++){
        for(int j = 0; j <= Y; j++){
            printf("%d ", dis[i][j][SS][SS]);
        }
        printf("\n");
    }
    */
    
    return 0;
}