#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int MM = 102, inf = 0x3f3f3f3f;
typedef pair<int,int> pii;
pii st;
vector<pii> camera;
queue<pii> q;
int N, M, dis[MM][MM], mx[] = {1,-1,0,0}, my[] = {0,0,1,-1};
char adj[MM][MM];
bool no[MM][MM];
unordered_map<char, pii> conv;
inline bool isconv(char c){
    return (conv[c].f != 0 || conv[c].s != 0);
}
int main(){
    conv['U'] = {-1, 0};
    conv['D'] = {1, 0};
    conv['L'] = {0, -1};
    conv['R'] = {0, 1};
    memset(dis, 0x3f, sizeof(dis));
    scanf("%d%d",&N,&M);
    for(int i = 0; i < N; i++){
        scanf("%s",adj[i]);
        for(int j = 0; j < M; j++){
            char c = adj[i][j];
            if(c == 'S')
                st.f = i, st.s = j;
            else if(c == 'C'){
                camera.push_back({i, j});
                no[i][j] = 1;
            }else if(c == 'W')
                no[i][j] = 1;
        }
    }
    for(const pii &e: camera){
        for(int k = 0; k < 4; k++){
            int ti = e.f, tj = e.s;
            while(adj[ti][tj] != 'W'){
                if(!isconv(adj[ti][tj]))
                    no[ti][tj] = 1;
                ti += mx[k];
                tj += my[k];
            }
        }
    }
    if(!no[st.f][st.s]){
        dis[st.f][st.s] = 0;
        q.push({st.f, st.s});
    }
    while(!q.empty()){
        pii cur = q.front(); q.pop();
        int i = cur.f, j = cur.s;
        char c = adj[i][j];
        if(c == 'W'){
            dis[i][j] = inf;
            continue;
        }else if(isconv(c)){
            int ti = i + conv[c].f, tj = j + conv[c].s;
            if(!no[ti][tj] && dis[i][j] < dis[ti][tj]){
                dis[ti][tj] = dis[i][j];
                q.push({ti, tj});
            }
        }else{
            for(int k = 0,ti,tj; k < 4; k++){
                ti = i + mx[k], tj = j + my[k];
                if(!no[ti][tj] && dis[i][j] + 1 < dis[ti][tj]){
                    dis[ti][tj] = dis[i][j] + 1;
                    q.push({ti, tj});
                }
            }
        }
    }
    for(int i = 0,val; i < N; i++){
        for(int j = 0; j < M; j++){
            if(adj[i][j] == '.'){
                val = dis[i][j];
                printf("%d\n", (val == inf ? -1 : val));
            }
        }
    }
    return 0;
}