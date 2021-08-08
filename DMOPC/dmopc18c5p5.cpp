#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+1, MAX = 1e6+1;

int N, a[MM], b[MM];
ll psa[MM], dp[MM];

struct node{
    int l, r;
    ll val;
} tree[2][4*MAX];

void build(int l, int r, int rt){
    tree[0][rt].l = tree[1][rt].l = l;
    tree[0][rt].r = tree[1][rt].r = r;
    tree[0][rt].val = tree[1][rt].val = 1e9;
    if(l == r)
        return;
    int mid = (l+r)>>1;
    build(l, mid, rt<<1);
    build(mid+1, r, rt<<1|1);
}

void update(int t, int pos, ll val, int rt){

    if(tree[t][rt].l == tree[t][rt].r){
        tree[t][rt].val = val;
        return;
    }
    int m = (tree[t][rt].l + tree[t][rt].r)>>1;
    if(pos <= m)
        update(t, pos, val, rt<<1);
    else
        update(t, pos, val, rt<<1|1);

    tree[t][rt].val = min(tree[t][rt<<1].val, tree[t][rt<<1|1].val);
}

ll query(int t, int l, int r, int rt){

    if(tree[t][rt].l == l && tree[t][rt].r == r)
        return tree[t][rt].val;

    int m = (tree[t][rt].l + tree[t][rt].r)>>1;

    if(r <= m)
        return query(t, l, r, rt<<1);
    else if(l > m)
        return query(t, l, r, rt<<1|1);
    else
        return min(query(t, l, m, rt<<1), query(t, m+1, r, rt<<1|1));
}

int main(){

    scanf("%d", &N);

    build(0, MAX, 1);

    scanf("%d%d", a+1, b+1);
    psa[1] = a[1];
    update(0, a[1], 0, 1);
    update(1, a[1], -psa[1]-a[1], 1);
    dp[1] = abs(a[1] - b[1]);

    for(int i = 2; i <= N; i++){
        scanf("%d%d", a+i, b+i);
        psa[i] = psa[i-1] + abs(a[i] - b[i-1]);
        update(0, a[i], dp[i-1]-psa[i]+a[i], 1);
        update(1, a[i], dp[i-1]-psa[i]-a[i], 1);
        //find a[j] >= b[i]
        dp[i] = psa[i] - b[i] + query(0, b[i], MAX, 1);
        //find a[j] < b[i]
        dp[i] = min(dp[i], psa[i]+b[i]+query(1, 0, b[i]-1, 1));
    }

    printf("%lld\n", dp[N]);

    return 0;
}