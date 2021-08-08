#include <bits/stdc++.h>
#define MM 300002
#define MN 18
using namespace std;
int N, dep[MM], lca[MN][MM], mp[MM];
inline void update(int j, int v){
    lca[0][j] = v;
    for(int i = 1; i < MN; i++){
        if(lca[i-1][j] != -1)
            lca[i][j] = lca[i-1][ lca[i-1][j]];
    }
}
//binary lifting
inline int query(int u, int v){
    if(dep[u] < dep[v])
        swap(u, v);
    for(int i = MN-1; i >= 0; i--){
        if((lca[i][u] != -1) && (dep[lca[i][u]] >= dep[v]))
            u = lca[i][u];
    }
    if(u == v)
        return u;
    for(int i = MN-1; i >= 0; i--){
        if((lca[i][u] != -1) && (lca[i][v] != -1) && (lca[i][u] != lca[i][v])){
            u = lca[i][u];
            v = lca[i][v];
        }
    }
    return lca[0][u];
}
int main(){
    memset(lca,-1,sizeof lca);
    scanf("%d",&N);
    char op;
    for(int i = 1,v,w; i <= N; i++){
        scanf(" %c%d",&op,&v);
        v = mp[v];
        if(op == 'a'){
            mp[i] = i;
            dep[i] = dep[v]+1;
            update(i,v);
        }
        else if(op == 'b'){
            printf("%d\n", v);
            //use parent of v
            mp[i] = lca[0][v];
        }
        else{
            //copy v
            mp[i] = v;
            
            scanf("%d",&w);
            w = mp[w];
            //find lca of v, w
            //ans is distance from 0 to lca
            printf("%d\n", dep[ query(v,w)]);
        }
    }
    return 0;
}