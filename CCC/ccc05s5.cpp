#include <bits/stdc++.h>
#define MM 100002
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
pii q[MM];
int tree[MM],N,sum;
double ans = 0;
inline void update(int ind, int val){
    for(int i = ind; i < MM; i += i & -i)
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
    for(int i = 1; i <= N; i++){
        scanf("%d",&q[i].f);
        q[i].s = i;
    }
    sort(q+1,q+N+1);
    for(int i = 1; i <= N; i++){
        update(q[i].s,1);
        ans += q[i].s - query(q[i].s-1);
    }
    printf("%.2f\n", ans/N);
    return 0;
}