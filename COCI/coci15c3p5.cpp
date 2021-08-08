#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e5+1, inf = 0x3f3f3f3f;

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

int n, k, m, a[MM];

struct node{
    int ans = inf;
    vector<pair<int, ll>> pre, suf;
} tree[MM*3];

bool cmp(ll f, ll s){
    return (~f)&s;
}

void push_up(int rt){
    
    tree[rt].ans = min(tree[lc].ans, tree[rc].ans);
    
    tree[rt].pre = tree[lc].pre;
    int l = tree[rt].pre.size();
    
    for(auto i: tree[rc].pre){
        if(l >= 50)
            break;
        
        if(cmp(tree[rt].pre[l-1].second, i.second)){
            tree[rt].pre.push_back(i); //rip
            tree[rt].pre[l].second |= tree[rt].pre[l-1].second;
            l++;
        }
    }
    
    tree[rt].suf = tree[rc].suf;
    l = tree[rt].suf.size();
    
    for(auto i: tree[lc].suf){
        if(l >= 50)
            break;
        
        if(cmp(tree[rt].suf[l-1].second, i.second)){
            tree[rt].suf.push_back(i);
            tree[rt].suf[l].second |= tree[rt].suf[l-1].second;
            l++;
        }
    }
    
    int r = tree[rc].pre.size()-1;
    
    for(auto i: tree[lc].suf){
        again:;
        if(r < 0)
            break;
        
        if((i.second | tree[rc].pre[r].second) == ((1LL<<k)-1)){
            tree[rt].ans = min(tree[rt].ans, (tree[rc].pre[r].first - i.first + 1));
            r--;
            goto again;
        }
    }
}

void build(int l = 1, int r = n, int rt = 1){
    int nl = l, nr = r;
    
    tree[rt].pre.reserve(min(50, r-l+1));
    tree[rt].suf.reserve(min(50, r-l+1));
    
    if(l == r){
        tree[rt].pre.push_back({l, 1LL<<a[l]});
        tree[rt].suf.push_back({l, (1LL<<a[l])});
        return;
    }
    build(l, nm, lc);
    build(nm+1, r, rc);
    push_up(rt);
}

void update(int l, int nl = 1, int nr = n, int rt = 1){
    if(nl == nr){
        assert(l == nl);
        tree[rt].pre[0] = tree[rt].suf[0] = {l, 1LL<<a[l]};
        return;
    }
    if(l <= nm)
        update(l, nl, nm, lc);
    else
        update(l, nm+1, nr, rc);
    push_up(rt);
}

int main(){
    
    scan(n, k, m);
    
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        a[i]--;
    }
    
    build();
    
    int op, l, v;
    while(m--){
        scan(op);
        if(op == 1){
            scan(l, v);
            a[l] = v-1;
            update(l);
        }
        else{
            /*
            if(k == 1){
                puts("1");
                continue;
            }
            */
            print(tree[1].ans == inf? -1: tree[1].ans);
        }
    }
    
    return 0;
}