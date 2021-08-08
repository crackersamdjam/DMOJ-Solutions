#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
using ll = long long;
const int MM = 1e5+2, SQ = 300;

int n, q, m, a[MM], id[MM], nx[MM], slow[MM], dis[MM];
//dis to exit the block

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
    ll tree[MM*4];
    
    inline void push_up(int rt){
        tree[rt] = tree[lc] + tree[rc];
    }
    
    void build(int l = 0, int r = n+2, int rt = 1){
        int nl = l, nr = r;
        if(l == r){
            tree[rt] = a[l];
            return;
        }
        build(nl, nm, lc);
        build(nm+1, nr, rc);
        push_up(rt);
    }
    
    void update(int l, int nl = 0, int nr = n+2, int rt = 1){
        if(nl == nr){
            tree[rt] = a[l];
            return;
        }
        if(l <= nm) update(l, nl, nm, lc);
        else update(l, nm+1, nr, rc);
        push_up(rt);
    }
    
    ll sum(int l, int r, int nl = 0, int nr = n+2, int rt = 1){
        if(l > r)
            return 0;
        if(r < nl || l > nr)
            return 0;
        if(l <= nl && r >= nr)
            return tree[rt];
        return sum(l, r, nl, nm, lc) + sum(l, r, nm+1, nr, rc);
    }
    
    int query(ll rem, int nl = 0, int nr = n+2, int rt = 1){
//        printf("qu %d - %d, %lld %lld\n", nl, nr, rem, tree[lc]);
        if(nl == nr)
            return nl;
        if(rem >= tree[lc])
            return query(rem-tree[lc], nm+1, nr, rc);
        return query(rem, nl, nm, lc);
    }
//#undef lc
//#undef rc
//#undef nm
} seg;

int nxone(int i){
    ll v = seg.sum(1, i-1)+m;
    int u = seg.query(v);
//    assert(u >= i and u <= n+1);
    return u;
}

#define max(a, b) ((a) > (b) ? (a) : (b))

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d%d", &n, &q, &m);
    for(int i = 1; i <= n; i++){
        scanf("%d", a+i);
        id[i] = id[i-1] + (i%SQ == 0);
    }
    a[n+1] = 1e9+5;
    id[n+1] = 1e9;
    nx[n+1] = n+1;
    int r = n;
    ll sum = 0;
    for(int i = n; i; i--){
        sum += a[i];
        ll rem = m-a[i];
        if(rem < 0){
            nx[i] = slow[i] = -1;
            dis[i] = 1e9;
            continue;
        }
        while(sum > m)
            sum -= a[r--];
        //assert(i <= r);
        int u = r+1;
        if(id[u] != id[i]){
            nx[i] = 0; //means jump
            dis[i] = 0;
            slow[i] = 0;
        }
        else{
            nx[i] = nx[u] ? nx[u] : u;
            dis[i] = dis[u]+1;
            slow[i] = u;
        }
    }
    
//    for(int i = 1; i <= n; i++)
//        printf("%d %d %d\n", i, nx[i], dis[i]);
    
    seg.build();
    
    for(int t = 0,l,ans; t < q; t++){
        char op;
        scanf(" %c %d %d", &op, &l, &r);
        if(op == 'Q'){
            ans = 0;
            int cnt = 0;
            while(~nx[l] && l <= r){
//                printf("nx %d\n", l);
                cnt++;
                if(nx[l] == 0){
                    ans++;
                    l = nxone(l);
                    continue;
                }
                if(nx[l] > r+1)
                    break;
                ans += dis[l];
                l = nx[l];
            }
            while(l <= r){
//                printf("slow %d\n", l);
                cnt++;
                if(slow[l] == -1){
                    ans = -1;
                    goto out;
                }
                if(slow[l] == 0){
                    ans++;
                    l = nxone(l);
                    continue;
                }
                ans++;
                l = slow[l];
            }
            assert(cnt < 900);
            out:;
            //assert(ans <= n);
            printf("%d\n", ans);
        }
        else{
            int lo = max(1, id[l]*SQ);
            a[l] = r;
            seg.update(l);
            r = nxone(l)-1; //r is before
            sum = seg.sum(l+1, r); // l about to be added in the loop
            r = max(r, l);
            //cout<<l<<' '<<r<<' '<<sum<<'\n';
            
            for(int i = l; i >= lo; i--){
                sum += a[i];
                ll rem = m-a[i];
                if(rem < 0){
                    //cout<<"skip\n";
                    nx[i] = slow[i] = -1;
                    continue;
                }
                while(sum > m)
                    sum -= a[r--];
                //assert(i <= r);
                //cout<<i<<' '<<r<<' '<<sum<<'\n';
                int u = r+1;
                if(id[u] != id[i]){
                    nx[i] = 0; //means jump
                    dis[i] = 0;
                    slow[i] = 0;
                }
                else{
                    nx[i] = nx[u] ? nx[u] : u;
                    //okay...
                    dis[i] = dis[u]+1;
                    slow[i] = u;
                }
//                printf("new i %d %d\n", i, slow[i]);
            }
        }
    }
    return 0;
}
/*
5 10 4
1 3 2 5 2
Q 1 5
-1
U 4 1
Q 1 5
2
Q 1 4
2
Q 2 5
2
Q 3 5
1
Q 1 3
1

5 3 4
1 3 2 5 2
Q 1 5
U 4 1
Q 1 5
 */