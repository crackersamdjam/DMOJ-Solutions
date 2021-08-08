#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using pii = pair<int, int>;
const int MM = 2e5+2;

#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)>>1)

struct node{
    pii val;
} tree[MM*3];

inline void push_up(int rt){
    tree[rt].val = max(tree[lc].val, tree[rc].val);
}

void build(int l, int r, int rt = 1){
    int nl = l, nr = r;
    if(l == r){
        tree[rt].val = {0, -1};
        return;
    }
    build(l, nm, lc);
    build(nm+1, r, rc);
    push_up(rt);
}

void update(int l, pii val, int nl = 1, int nr = MM-1, int rt = 1){
    if(nl == nr){
        tree[rt].val = max(tree[rt].val, val);
        return;
    }
    if(l <= nm) update(l, val, nl, nm, lc);
    else update(l, val, nm+1, nr, rc);
    push_up(rt);
}

pii query(int l, int r, int nl = 1, int nr = MM-1, int rt = 1){
    if(r < nl || l > nr)
        return {0, -1};
    if(l <= nl && r >= nr)
        return tree[rt].val;
    return max(query(l, r, nl, nm, lc), query(l, r, nm+1, nr, rc));
}

set<pii> all[MM];
pii v[MM];
int n, t, bt;
map<int, int> mp;
struct st{
    int op, a, b;
} in[MM];

int main(){
    
    //min b, then a
    //bsearch for lowest b with high enough a
    //same b, store set of a's, store max in segtree
    //loop through afterwards to see if a can be lowered
    //cord-comp b
    scan(n);
    for(int i = 1; i <= n; i++){
        in[i].op = gc;
        scan(in[i].a);
        if(in[i].op == 'D'){
            scan(in[i].b);
            mp[in[i].b] = 0;
        }
    }
    
    for(auto &x: mp)
        x.second = ++bt;
    
    for(int i = 1,a,b; i <= n; i++){
        a = in[i].a, b = mp[in[i].b];
        if(in[i].op == 'D'){
            update(b, {a, ++t});
            v[t] = {a, b};
            all[b].insert({a, t});
        }
        else{
            //first check same b
            auto it = all[v[a].second].lower_bound({v[a].first, a+1});
            if(it != all[v[a].second].end()){
                //printf("same b ");
                print(it->second);
                continue;
            }
            
            int l = v[a].second+1, m, r = MM-1;
            while(l <= r){
                m = (l+r)/2;
                if(query(v[a].second+1, m).first < v[a].first)
                    l = m+1;
                else
                    r = m-1;
            }
            
            //printf("l %d, %d\n", l, r);
            
            if(l > MM-1){
                puts("NE");
                continue;
            }
            
            assert(all[l].lower_bound({v[a].first, 0}) != all[l].end());
            int ans = all[l].lower_bound({v[a].first, 0})->second;
            print(ans);
        }
    }
    
    
    return 0;
}