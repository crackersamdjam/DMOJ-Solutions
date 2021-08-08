#include <bits/stdc++.h>
#define MM 5001
using namespace std;
int K, cnt = 1, e = 0;
int adj[MM], add[MM];
int main(){
    scanf("%d",&K);
    for(int n = 5000; n > 1; n--){
        int num = n*(n-1)/2;
        while(num <= K){
            //printf("%d\n",n);
            K -= num;
            if(e){
                add[cnt] = 1;
                e++;
            }
            adj[cnt+n-1] = cnt;
            e++;
            for(int i = cnt; i < cnt+n-1; i++){
                adj[i] = i+1;
                e++;
            }
            cnt += n;
        }
    }
    printf("%d %d\n",cnt-1,e);
    for(int i = 1; i < MM; i++){
        if(adj[i])
            printf("%d %d\n",i,adj[i]);
        if(add[i])
            printf("%d 1\n",i);
    }
    return 0;
}
/*
 * graph must still be connected
 */