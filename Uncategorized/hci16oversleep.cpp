#include <bits/stdc++.h>
#define MM 1002
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
int N,M;
pii st,ed,cur,nx;
char c;
int dis[MM][MM];
bool vis[MM][MM];
int v[] = {1,-1,0,0}, h[] = {0,0,1,-1};
queue<pii> q;
int main(){
    scanf("%d%d",&N,&M);
    for(int i = 0; i < N; i++){
        scanf("%c",&c);
        for(int j = 0; j < M; j++){
            scanf("%c",&c);
            dis[i][j] = (c == '.') ? 0 : -1;
            if(c == 's'){
                st = {i,j};
                dis[i][j] = 0;
            }else if(c == 'e'){
                ed = {i,j};
                dis[i][j] = INT_MAX;
            }
        }
    }
    vis[st.f][st.s] = 1;
    q.push(st);
    while(!q.empty()){
        cur = q.front(); q.pop();
        if(cur == ed)
            break;
        for(int i = 0; i < 4; i++){
            nx = {cur.f + v[i], cur.s + h[i]};
            if(nx.f >= 0 && nx.f < N && nx.s >= 0 && nx.s < M &&
                    !vis[nx.f][nx.s] && dis[nx.f][nx.s] != -1){
                vis[nx.f][nx.s] = 1;
                dis[nx.f][nx.s] = dis[cur.f][cur.s] + 1;
                q.push(nx);
            }
        }
    }
    printf("%d\n", dis[ed.f][ed.s] == INT_MAX ? -1 : dis[ed.f][ed.s]-1);
    return 0;
}