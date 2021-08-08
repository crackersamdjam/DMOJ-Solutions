#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long lll;
typedef pair<lll, int> pii;
constexpr int MM = 2e5+2;

priority_queue<pii, vector<pii>, greater<pii>> q, pq;
//q for nodes, pq for portals

int n, m, h, w, x[MM], y[MM];
lll dis[MM];

struct segtree{
#define lc (rt<<1)
#define rc (rt<<1|1)
#define nm ((nl+nr)/2)
    
    set<pii> tree[MM*3];
    
    void insert(int l, int ll, int id, int nl = 1, int nr = h, int rt = 1){
        if(l < nl || l > nr)
            return;
        
        tree[rt].insert({ll, id});
    
        if(nl == nr)
            return;
    
        insert(l, ll, id, nl, nm, lc);
        insert(l, ll, id, nm+1, nr, rc);
    }
    
    void remove(int l, int ll, int id, int nl = 1, int nr = h, int rt = 1){
        if(l < nl || l > nr)
            return;
    
        if(tree[rt].count({ll, id}))
            tree[rt].erase({ll, id});
        
        if(nl == nr)
            return;
    
        remove(l, ll, id, nl, nm, lc);
        remove(l, ll, id, nm+1, nr, rc);
    }
    
    void update(int l, int r, int ll, int rr, lll val, int nl = 1, int nr = h, int rt = 1){
        if(r < nl || l > nr)
            return;
        
        if(l <= nl && r >= nr){
            //remove all
            vector<int> rm;
            for(auto it = tree[rt].lower_bound({ll, 0}); it != tree[rt].end() and it->first <= rr; it++){
                dis[it->second] = val;
                q.emplace(val, it->second);
                rm.emplace_back(it->second);
            }
            for(int i: rm)
                remove(x[i], y[i], i);
            return;
        }
        
        update(l, r, ll, rr, val, nl, nm, lc);
        update(l, r, ll, rr, val, nm+1, nr, rc);
    }
    
#undef lc
#undef rc
#undef nm
} ST;

struct pt{
    int d, l, r, ll, rr;
} port[MM];
vector<int> v[MM];

int main(){
    scan(n, m, h, w);
    for(int i = 0; i < n; i++){
        scan(x[i], y[i]);
        if(i) ST.insert(x[i], y[i], i);
    }
    for(int i = 0,id,d,l,r,ll,rr; i < m; i++){
        scan(id, d, l, r, ll, rr);
        port[i] = {d, l, r, ll, rr};
        v[id-1].emplace_back(i);
    }
    memset(dis, 0x3f, sizeof dis);
    dis[0] = 0;
    q.emplace(0, 0);
    int st = 1; //first
    while(pq.size() || st){
        
        if(!st){
            //process best portal
            int cur = pq.top().second; lll curd = pq.top().first; pq.pop();
            auto p = port[cur];
            ST.update(p.l, p.r, p.ll, p.rr, curd);
        }
        st = 0;
        
        //process nodes
        while(q.size()){
            int cur = q.top().second; q.pop();
            for(int i: v[cur]){
                pq.emplace(dis[cur] + port[i].d, i);
            }
        }
    }
    
    for(int i = 1; i < n; i++){
        if(dis[i] == dis[n])
            dis[i] = -1;
        print(dis[i]);
    }
    
    return 0;
}