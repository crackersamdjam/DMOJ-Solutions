#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

typedef long long ll;
constexpr int MM = 1e5+2, SQ = 1000, inf = 1e9;

int n, q, m, a[MM], id[MM], nx[MM], slow[MM], dis[MM];
//dis to exit the block

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)
    ll tree[MM*3];
    
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
        if(nl == nr)
            return nl;
        if(rem >= tree[lc])
            return query(rem-tree[lc], nm+1, nr, rc);
        return query(rem, nl, nm, lc);
    }
#undef lc
#undef rc
#undef nm
} seg;

inline int nxone(int i){
    return seg.query(seg.sum(1, i-1)+m);
}

#define max(a, b) ((a) > (b) ? (a) : (b))

int main(){
    scan(n, q, m);
    for(int i = 1,add=1; i <= n; i++, add++){
        scan(a[i]);
        id[i] = id[i-1];
        if(add == SQ){
            id[i]++;
            add = 0;
        }
    }
    a[n+1] = inf+5;
    id[n+1] = inf;
    nx[n+1] = n+1;
    int r = n;
    ll sum = 0;
    for(int i = n; i; i--){
        sum += a[i];
        ll rem = m-a[i];
        if(rem < 0){
            nx[i] = slow[i] = -1;
            dis[i] = inf;
            continue;
        }
        while(sum > m)
            sum -= a[r--];
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
    
    seg.build();
    
    char op;
    for(int t = 0,l,ans; t < q; t++){
        op = gc;
        scan(l, r);
        if(op == 'Q'){
            ans = 0;
            int cnt = 0;
            while(~nx[l] && l <= r){
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
            out:;
            print(ans);
        }
        else{
            int lo = max(1, id[l]*SQ);
            a[l] = r;
            seg.update(l);
            r = nxone(l)-1; //r is before
            sum = seg.sum(l+1, r); // l about to be added in the loop
            r = max(r, l);
            
            for(int i = l; i >= lo; i--){
                sum += a[i];
                ll rem = m-a[i];
                if(rem < 0){
                    nx[i] = slow[i] = -1;
                    continue;
                }
                while(sum > m)
                    sum -= a[r--];
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
        }
    }
    return 0;
}