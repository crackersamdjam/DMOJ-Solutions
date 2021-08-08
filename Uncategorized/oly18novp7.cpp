#include <bits/stdc++.h>
#define MM (100002<<1)
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int dis[MM], A, B;
queue<int> q;
int main(){
    sc(A); sc(B);
    if(A == B){
        printf("0\n");
        return 0;
    }
    memset(dis,0x3f,sizeof dis);
    dis[A] = 0;
    q.push(A);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(dis[cur]+1 < dis[cur+1]){
            dis[cur+1] = dis[cur]+1;
            q.push(cur+1);
        }
        if(cur-1 >= 0 && dis[cur]+1 < dis[cur-1]){
            dis[cur-1] = dis[cur]+1;
            q.push(cur-1);
        }
        if((cur<<1) < MM && dis[cur]+1 < dis[cur<<1]){
            dis[cur<<1] = dis[cur]+1;
            q.push(cur<<1);
        }
    }
    printf("%d\n", dis[B]);
    return 0;
}