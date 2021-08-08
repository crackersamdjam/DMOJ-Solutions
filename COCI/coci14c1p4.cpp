#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+1;

int N, a[MM], in[MM];
bool vis[MM], mob[MM];


int main(){
    
    scanf("%d", &N);
    
    for(int i = 1; i <= N; i++){
        scanf("%d", a+i);
        in[a[i]]++;
    }
    
    for(int i = 1; i <= N; i++){
        
        if(!vis[i] && !in[i]){
            int cur = i, last = 0;
            
            //dfs, break when has other incoming cycles
            while( !vis[cur] && (last || !in[cur])){
                //printf("cur %d\n", cur);
                vis[cur] = 1;
                if(!last)
                    mob[cur] = 1;
                else
                    in[a[cur]]--;
                
                //civil. edge does not matter
                
                last ^= 1;
                cur = a[cur];
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(!vis[i]){
            //cycle
            int cur = i, last = 1;
            //start with civilian
            while(!vis[cur]){
                vis[cur] = 1;
                if(!last)
                    mob[cur] = 1;
                else
                    in[a[cur]]--;
                
                last ^= 1;
                cur = a[cur];
            }
        }
    }
    
    int cnt = 0;
    for(int i = 1; i <= N; i++){
        if(mob[i])
            cnt++;
    }
    
    printf("%d\n", cnt);
    
    for(int i = 1; i <= N; i++){
        //printf("%d ", mob[i]);
    }
    
    return 0;
}
/*
 * dfs()
 * if cur is civilian, remove edge
 * if no incoming edges to next node, then it is mobster
 *
 * loop though
 *      if not vis and no incoming dfs
 *
 * then you are left with at most 1 cycle (since one can only accuse one other)
 *
 * for the cycle, loop through mobster, civilian
 */