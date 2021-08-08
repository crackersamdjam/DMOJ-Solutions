#include <bits/stdc++.h>
using namespace std;
#define MM 100002
int par[MM],N,M;
vector<int> inf;
int find(int x){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
    }return x;
}
void merge(int x, int y){
    par[find(x)] = find(y);
}
inline void init(){
    for(int i = 1; i <= N; i++)
        par[i] = i;
}
int main(){
    scanf("%d%d",&N,&M);
    init();
    for(int i = 0,K,rep,cur; i < M; i++){
        scanf("%d",&K);
        if(!K) continue;
        scanf("%d",&rep);
        K--;
        while(K--){
            scanf("%d",&cur);
            merge(cur, rep);
        }
    }
    int in = find(1);
    inf.push_back(1);
    for(int i = 2; i <= N; i++){
        if(find(i) == in)
            inf.push_back(i);
    }
    sort(inf.begin(), inf.end());
    printf("%lu\n",inf.size());
    for(const int& i: inf)
        printf("%d ", i);
    return 0;
}