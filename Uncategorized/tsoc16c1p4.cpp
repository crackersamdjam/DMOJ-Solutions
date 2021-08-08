#include <bits/stdc++.h>
#define MM 52
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
char arr[MM][MM];
int R, C, ans;
pii mv[] = {{1,0},{-1,0},{0,1},{0,-1}};
bool vis[MM][MM];
vector<pii> vec;
void dfs(pii cur){
    pii u;
    for(int i = 0; i < 4; i++){
        u.f = cur.f + mv[i].f, u.s = cur.s + mv[i].s;
        if(arr[u.f][u.s] && arr[u.f][u.s] != '#' && !vis[u.f][u.s]){
            vis[u.f][u.s] = 1;
            dfs(u);
        }
    }
}
int main(){
    scanf("%d %d",&R,&C);
    for(int i = 1; i <= R; i++){
        getchar_unlocked();
        for(int j = 1; j <= C; j++){
            arr[i][j] = getchar_unlocked();
            if(arr[i][j] == 'M')
                vec.push_back({i,j});
        }
    }
    for(pii &st: vec){
        if(!vis[st.f][st.s]){
            ans++;
            vis[st.f][st.s] = 1;
            dfs(st);
        }
    }
    printf("%d\n", ans);
    return 0;
}