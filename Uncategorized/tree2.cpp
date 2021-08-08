#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define f first
#define s second
#define MM 11
int mr[] = {1,-1,0,0}, mc[] = {0,0,1,-1};
int adj[MM][MM], dis[MM][MM], num[MM][MM];
//bool inq[MM][MM];
double dist(int x1, int y1, int x2, int y2){
    return sqrt(pow(0.0+x1-x2,2) + pow(0.0+y1-y2,2));
}
int main() {
    pii start;
    int r, c; scanf("%d%d",&r,&c);
    int high = 0;
    char nl; scanf("%c",&nl);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            char temp, thro;
            scanf("%c",&temp); scanf("%c",&thro);
            if(temp == 'X'){
                start = {i,j};
                adj[i][j] = 0;
            }else if(temp == '.')
                adj[i][j] = 0;
            else
                adj[i][j] = temp-'0';
            high = max(high, adj[i][j]);
        }
    }
    pii dest; double maxd = DBL_MAX;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(adj[i][j] == high && dist(start.f,start.s,i,j) < maxd){
                maxd = dist(start.f,start.s,i,j);
                dest = {i,j};
            }
        }
    }
    memset(dis,0x3f, sizeof(dis));
    queue<pii> q; q.push(start);
    dis[start.f][start.s] = 0;
    num[start.f][start.s] = 0;
    //inq[start.f][start.s] = true;
    while(!q.empty()){
        pii cur = q.front(); q.pop(); //inq[cur.f][cur.s] = false;
        for(int mv = 0; mv < 4; mv++) {
            int i = cur.f + mr[mv], j = cur.s + mc[mv];
            if(i < r && i >= 0 && j < c && j >= 0){
                if(dis[cur.f][cur.s] + adj[i][j] < dis[i][j]){
                    dis[i][j] = dis[cur.f][cur.s] + adj[i][j];
                    num[i][j] = num[cur.f][cur.s] + (adj[i][j] != 0);
                    //if (!inq[i][j]) {
                        //inq[i][j] = true;
                        q.push({i,j});
                    //}
                }
            }
        }
    }
    printf("%d\n",num[dest.f][dest.s]-1);\
    return 0;
}