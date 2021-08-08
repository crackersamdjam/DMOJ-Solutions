#include <bits/stdc++.h>
#define MM 10002
using namespace std;
vector<int> adj[MM];
int in[MM], N, M;
queue<int> q;
int main(){
    scanf("%d%d",&N,&M);
    for(int i = 0,a,b; i < M; i++){
        scanf("%d%d",&a,&b);
        adj[a].push_back(b);
        in[b]++;
    }
    for(int i = 1; i <= N; i++){
        if(!in[i])
            q.push(i);
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int &u: adj[cur]){
            if(!--in[u])
                q.push(u);
        }
    }
    bool b = 1;
    for(int i = 1; i <= N; i++){
        if(in[i]){
            b = 0;
            break;
        }
    }
    printf(b? "Y\n": "N\n");
    return 0;
}