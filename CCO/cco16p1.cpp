#include <bits/stdc++.h>
using namespace std;
#define MM 1000002
int par[MM],dep[MM],N,M,K,a,b,sum=0,sev=0;
bool cycle[MM];
inline void init(){
    for(int i = 1; i <= N; i++){
        par[i] = i;
        dep[i] = 1;
    }
}
int find(int x){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
    }return x;
}
void merge(int x, int y){
    int rx = find(x), ry = find(y);
    if(rx == ry){
        cycle[rx] = cycle[ry] = 1;
        return;
    }
    if(dep[rx] < dep[ry]){
        dep[ry] += dep[rx];
        par[rx] = ry;
    }else{
        dep[rx] += dep[ry];
        par[ry] = rx;
    }
}
int main(){
    scanf("%d%d%d",&N,&M,&K);
    init();
    while(M--){
        scanf("%d%d",&a,&b);
        merge(a, b);
    }
    for(int i = 1; i <= N; i++){
        if(find(i) == i){
            if(dep[i] == K){
                sum += K;
            }else if(dep[i] >= K){
                sev += (dep[i]-1) / K;
                if(cycle[i])
                    sev++;
                sum += floor(dep[i] / K) * K;
            }
        }
    }
    printf("%d %d\n",sum,sev);
    return 0;
}
//Each student is friends with at most two other students. (at most one cycle)
//when edges == vertices