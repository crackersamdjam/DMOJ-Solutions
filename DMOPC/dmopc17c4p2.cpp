#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
using namespace std;
const int MM = 1002;

char _;
vector<int> adj[MM];
int N, Q, val[MM], op, st, ed;
vector<int> path;
bool ret;
void dfs(int cur, int pre){
    path.push_back(val[cur]);
    if(ret)
        return;
    if(cur == ed){
        ret = 1;
        if(op == 1){
            double ans = 0;
            for(int &i: path)
                ans += i;
            printf("%d\n", (int)(ans/path.size() + 0.5));
        }
        else if(op == 2){
            sort(path.begin(), path.end());
            int mid = path.size()/2;
            if(path.size()&1)
                printf("%d\n", path[mid]);
            else
                printf("%d\n", (int)((path[mid] + path[mid-1])/2.0 + 0.5));
        }
        else{
            sort(path.begin(), path.end());
            int cnt = 1, ans = 1, num = path[0];
            for(int i = 1; i < path.size(); i++){
                if(path[i] == path[i-1]){
                    if(++cnt > ans){
                        ans = cnt;
                        num = path[i];
                    }else if(cnt == ans){
                        num = min(num, path[i]);
                    }
                }
                else
                    cnt = 1;
            }
            printf("%d\n", num);
        }
        return;
    }
    for(int &u: adj[cur]){
        if(u != pre)
            dfs(u, cur);
    }
    path.pop_back();
}


int main(){
    sc(N); sc(Q);
    for(int i = 1; i <= N; i++)
        sc(val[i]);
    for(int i = 0,a,b; i < N-1; i++){
        sc(a); sc(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < Q; i++){
        sc(op); sc(st); sc(ed);
        ret = 0;
        path.clear();
        dfs(st, -1);
    }
    return 0;
}