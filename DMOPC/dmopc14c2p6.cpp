#include <bits/stdc++.h>
#define MM 100002
using namespace std;
int tree[MM],out[MM],N,Q,sum;
//value, type, index     for updates 0
//value, type a, b       for queries 1
struct st{
    int a,b,c,d;
}qs[MM*2];
inline bool cmp(st a, st b){
    if(a.a == b.a)
        return a.b < b.b; //type 0 queries come first
    return a.a > b.a;
}
inline void update(int ind, int val){
    for(int i = ind; i <= N; i += i & -i)
        tree[i] += val;
}
inline int query(int ind){
    sum = 0;
    for(int i = ind; i > 0; i -= i & -i)
        sum += tree[i];
    return sum;
}
int main(){
    scanf("%d",&N);
    for(int i = 1,m; i <= N; i++){
        scanf("%d",&m);
        qs[i] = {m,i,i,0};
    }
    scanf("%d",&Q);
    for(int i = N+1,a,b,q; i <= N+Q; i++){
        scanf("%d%d%d",&a,&b,&q);
        qs[i] = {q,i,a,b};
    }
    sort(qs+1,qs+N+Q+1,cmp);
    for(int i = 1; i <= N+Q; i++){
        if(qs[i].b <= N)
            update(qs[i].c,qs[i].a);
        else
            out[qs[i].b-N] = query(qs[i].d+1) - query(qs[i].c);
    }
    for(int i = 1; i <= Q; i++)
        printf("%d\n",out[i]);
    return 0;
}