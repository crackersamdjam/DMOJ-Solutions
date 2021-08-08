#include <bits/stdc++.h>
using namespace std;
int main() {
    for(int i = 0; i < 5; i++){
        char map[10][11];
        queue<pair<int, int>> q;
        for(int j = 0; j < 10; j++){
            scanf("%s", map[j]);
            for(int k = 0; k < 10; k++){
                if(map[j][k] == 'F'){
                    q.push(make_pair(j, k));
                }
            }
        }
        int dis[10][11];
        memset(dis, -1, sizeof(dis[0][0])*10*11);
        int maxT = -1;
        while(!q.empty()){
            pair<int, int> cur = q.front(); q.pop();
            if(dis[cur.first][cur.second] > maxT) maxT = dis[cur.first][cur.second];
            if(cur.first > 0 && map[cur.first-1][cur.second] == 'T' && dis[cur.first-1][cur.second] == -1){
                dis[cur.first-1][cur.second] = dis[cur.first][cur.second] + 1;
                q.push(make_pair(cur.first-1, cur.second));
            }
            if(cur.second < 9 && map[cur.first][cur.second+1] == 'T' && dis[cur.first][cur.second+1] == -1){
                dis[cur.first][cur.second+1] = dis[cur.first][cur.second] + 1;
                q.push(make_pair(cur.first, cur.second+1));
            }
            if(cur.second > 0 && map[cur.first][cur.second-1] == 'T' && dis[cur.first][cur.second-1] == -1){
                dis[cur.first][cur.second-1] = dis[cur.first][cur.second] + 1;
                q.push(make_pair(cur.first, cur.second-1));
            }
            if(cur.first < 9 && map[cur.first+1][cur.second] == 'T' && dis[cur.first+1][cur.second] == -1){
                dis[cur.first+1][cur.second] = dis[cur.first][cur.second] + 1;
                q.push(make_pair(cur.first+1, cur.second));
            }
        }
        bool visAll = true;
        for(int j = 0; j < 10 && visAll; j++)
            for(int k = 0; k < 10; k++)
                if(map[j][k] == 'T' && dis[j][k] == -1){visAll = false; break;}
        printf("%d\n", visAll ? maxT + 1 : -1);
        char skip[11];
        scanf("%s", skip);
    }
    return 0;
}