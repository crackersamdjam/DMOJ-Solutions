#include <bits/stdc++.h>
using namespace std;
const int maxn = 20;

int dis[1<<maxn], N, M, S, L, R, I;
char str[maxn+2];
queue<int> q;

int main(){
    
    memset(dis, 0x3f, sizeof dis);
    
    scanf("%d%d%d%d%d%d", &N, &M, &S, &L, &R, &I);
    
    scanf("%s", str);
    int start = 0;
    for(int i = 0; i < N; i++){
        start = (start<<1) | (str[i] == 'B');
    }
    
    dis[start] = 0;
    
    q.push(start);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < N; i++){
            int nx = cur ^ (1<<i);
            if(dis[cur] + S <= M && dis[cur] + S < dis[nx]){
                dis[nx] = dis[cur] + S;
                q.push(nx);
            }
        }
        
        int nx = cur<<1;
        nx |= (nx>>N);
        if(nx >> N){
            nx ^= (1 << N);
        }
        
        if(dis[cur] + L <= M && dis[cur] + L < dis[nx]){
            dis[nx] = dis[cur] + L;
            q.push(nx);
        }
        
        
        nx = cur;
        int last = nx&1;
        nx |= (last << N);
        nx >>= 1;
    
        if(dis[cur] + R <= M && dis[cur] + R < dis[nx]){
            dis[nx] = dis[cur] + R;
            q.push(nx);
        }
        
        nx = (~cur)&((1<<N)-1);
        if(dis[cur] + I <= M && dis[cur] + I < dis[nx]){
            dis[nx] = dis[cur] + I;
            q.push(nx);
        }
    }
    
    int cnt = 0;
    
    for(int i = 0; i < (1<<N); i++)
        cnt += (dis[i] <= M);
    
    printf("%d\n", cnt);
    
    return 0;
}