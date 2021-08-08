#include <bits/stdc++.h>
#define MM 200002
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int N, M, in[MM], in2[MM];
bool arr[MM], vis[MM];
vector<int> adj[MM];
queue<int> q[2];
//one for each type
inline int go(int m){
    for(int i = 0; i < 2; i++){
        while(!q[i].empty())
            q[i].pop();
    }

    int cnt = 0, ans = 1;
    int time = 0; //only first two times is this loop needed

    //O(V + E)
    //each vertex visited once, edge travelled once
    while(cnt < N){
        if(time < 2){
            //linear loop twice at the start
            for(int i = 0; i < N; i++){
                if(arr[i] == m && !in[i] && !vis[i]){
                    vis[i] = 1;
                    q[m].push(i);
                }
            }
            time++;
        }

        //topological sort
        while(!q[m].empty()){
            int cur = q[m].front(); q[m].pop();
            cnt++;
            for(int &u: adj[cur]){
                if(!--in[u] && !vis[u]){
                    vis[u] = 1;
                    q[ arr[u] ].push(u);
                    //push anyways, will be covered next run
                }
            }
        }
        ans++;
        m ^= 1;
    }
    return ans-2;
}
int main(){
    sc(N); sc(M);
    for(int i = 0,t; i < N; i++){
        sc(t);
        arr[i] = t;
        //input works now
    }
    for(int i = 0,a,b; i < M; i++){
        sc(a); sc(b);
        adj[a].push_back(b);
        in[b]++, in2[b]++;
    }
    int ans = go(0);
    memset(vis,0,sizeof(vis));
    for(int i = 0; i < N; i++)
        in[i] = in2[i];
    ans = min(ans, go(1));
    printf("%d\n", ans);
    return 0;
}