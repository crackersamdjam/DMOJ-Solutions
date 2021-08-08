#include <bits/stdc++.h>
#define MM 1000002
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef pair<double,int> pii;
pii arr[MM];
int N, P, rk[MM], tree[MM];
inline void update(int ind){
    for(int i = ind; i < MM; i += i&-i)
        tree[i]++;
}
inline int query(int ind){
    int sum = 0;
    for(int i = ind; i > 0; i -= i&-i)
        sum += tree[i];
    return sum;
}
int main(){
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        scanf("%lf",&arr[i].f);
        arr[i].s = i;
    }
    scanf("%d",&P);
    for(int i = 1; i <= N; i++){
        arr[i].f += arr[i-1].f - P;
        //printf("%d ",arr[i].f);
    }
    //printf("\n");
    arr[0] = {0,0};
    sort(arr,arr+N+1);
    int cnt = 1;
    for(int i = 0; i <= N; i++){
        if(i != 0 && arr[i].f > arr[i-1].f)
            cnt++;
        rk[arr[i].s] = cnt;
    }
#ifdef def
    for(int i = 1; i <= N; i++){
        printf("%d ",rk[i]);
    }
    printf("\n");
#endif
    ll ans = 0;
    update(rk[0]);
    for(int i = 1; i <= N; i++){
        ans += query(rk[i]);
        update(rk[i]);
        //query how many before
        //push into bit
    }
    printf("%lld\n",ans);
    return 0;
}
/*
 * inversion
 * virtual ranking
 * query how many less than/equal
 * add that to ans
 * push into tree
 * psa of sum of elements before
 *
 * just like pinball ranking
 * count number of inversions
 */