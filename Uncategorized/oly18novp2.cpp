#include <bits/stdc++.h>
#define MM 1000002
#define f first
#define s second
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef pair<int,int> pii;
pii a[MM];
int N,ans, par[MM];
//disjoint set
inline int find(int x){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
        if(x == 0)
            return -1;
    }
    return x;
}
int main(){
    sc(N);
    for(int i = 1; i <= N; i++){
        par[i] = i;
        sc(a[i].f);
        sc(a[i].s);
    }
    sort(a+1, a+N+1, [](pii &as, pii &bs){return as.s > bs.s;});
    for(int i = 1; i <= N; i++){
        if(find(a[i].f) != -1){
            par[find(a[i].f)] = par[find(a[i].f)-1];
            ans += a[i].s;
        }
    }
    printf("%d\n", ans);
    return 0;
}