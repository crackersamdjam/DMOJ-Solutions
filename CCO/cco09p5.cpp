#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;

int tree[4*MM][16], rw[MM], cl[MM], k[MM], n, q;

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
    void merge(int (&res)[16], int va[16], int vb[16]){
        for(int i = 0; i < 16; i++)
            res[i] = va[vb[i]];
    }
    void push_up(int rt){
        merge(tree[rt], tree[lc], tree[rc]);
    }
    void update(int l, int r, int nl = 1, int nr = n, int rt = 1){
        if(r < nl || l > nr)
            return;
        if(l <= nl && r >= nr){
            int a[4][4], b[4][4];
            for(int i = 0; i < 4; i++)
                for(int j = 0; j < 4; j++)
                    b[i][j] = a[i][j] = i*4+j;
            int u = rw[l]-1, d = u+k[l]-1, ls = cl[l]-1, rs = ls+k[l]-1;
            for(int i = u; i < d; i++)
                b[i][ls] = a[i+1][ls];
            for(int i = ls; i < rs; i++)
                b[d][i] = a[d][i+1];
            for(int i = d; i > u; i--)
                b[i][rs] = a[i-1][rs];
            for(int i = rs; i > ls; i--)
                b[u][i] = a[u][i-1];
            for(int i = 0; i < 16; i++)
                tree[rt][i] = b[i/4][i%4];
            return;
        }
        update(l, r, nl, nm, lc);
        update(l, r, nm+1, nr, rc);
        push_up(rt);
    }
#undef lc
#undef rc
#undef nm
} seg;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i = 1; i <= n; i++){
        cin>>rw[i]>>cl[i]>>k[i];
        seg.update(i, i);
    }
    while(q--){
        int i;cin>>i;
        cin>>rw[i]>>cl[i]>>k[i];
        seg.update(i, i);
        for(int j = 0; j < 4; j++){
            for(int kk = 0; kk < 4; kk++)
                printf("%d%c", tree[1][j*4+kk]+1, " \n"[kk==3]);
        }
    }
    
    return 0;
}