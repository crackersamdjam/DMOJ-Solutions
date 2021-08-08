#include <bits/stdc++.h>
using namespace std;

int K;
unsigned char dis[1<<25];
queue<int> q;

int main(){
    
    memset(dis, 0xff, sizeof dis);
    
    scanf("%d", &K);
    
    int start = 0;
    
    for(int i = 0,a; i < K; i++){
        scanf("%d", &a);
        if(a)
            start |= (1<<i);
    }
    
    dis[start] = 0;
    q.push(start);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        for(int i = 0; i < K; i++){
            
            if(!(cur&(1<<i))){
    
                int nx = cur|(1<<i), len = 0;
                for(int j = 0; j <= K; j++){
                    if(nx&(1<<j))
                        len++;
                    else if(len >= 4){
                        for(int k = j-len; k < j; k++)
                            nx ^= (1<<k);
                        len = 0;
                    }
                    else
                        len = 0;
                }
                
                if(nx == 0){
                    printf("%d\n", dis[cur] + 1);
                    return 0;
                }
    
                if(dis[cur] + 1 < dis[nx]){
                    dis[nx] = dis[cur] + 1;
                    q.push(nx);
                }
            }
        }
    }
    
    return 0;
}