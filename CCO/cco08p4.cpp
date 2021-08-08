#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 1001;

int N, M, dfn[MM][MM], cnt, ans;
char adj[MM][MM];
bool vis[MM][MM];
map<char, pii> dir;

int main(){
    
    dir['N'] = {-1, 0};
    dir['S'] = {1, 0};
    dir['W'] = {0, -1};
    dir['E'] = {0, 1};
    
    scanf("%d%d",&N,&M);
    
    for(int i = 0; i < N; i++)
        scanf("%s", adj[i]);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!vis[i][j]){
                pii cur = {i, j};
                cnt++;
                do{
                    vis[cur.first][cur.second] = 1;
                    dfn[cur.first][cur.second] = cnt;
                    cur = {cur.first + dir[adj[cur.first][cur.second]].first, cur.second + dir[adj[cur.first][cur.second]].second};
                    
                } while(!vis[cur.first][cur.second]);
                
                if(dfn[cur.first][cur.second] == cnt)
                    ans++;
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}