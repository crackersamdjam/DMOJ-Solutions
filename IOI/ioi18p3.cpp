#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+5, LOG = 18;

int n, m, dsu[MM], spmax[LOG][MM], spmin[LOG][MM];
vector<int> adj[MM], adjmax[MM], adjmin[MM];
//max node at top, min node at top

int bit[MM], firstmax[MM], lastmax[MM], firstmin[MM], lastmin[MM], tmax, tmin;

void update(int i){
    for(; i < MM; i += i&-i)
        bit[i]++;
}

int query(int i){
    int ret = 0;
    for(; i; i -= i&-i)
        ret += bit[i];
    return ret;
}

struct qu{
    int op, x, ly, ry, id;
    //op 0 add point, op 1 query add, op 2 query subtract
    qu(int _op, int _x = 0, int _ly = 0, int _ry = 0, int _id = 0): op(_op), x(_x), ly(_ly), ry(_ry), id(_id) {}
    bool operator< (const qu &o) const{
        if(x == o.x)
            return op < o.op;
        return x < o.x;
    }
};
vector<qu> q;

void init(){
    for(int i = 0; i < n; i++)
        dsu[i] = i;
}

int find(int x){
    while(x != dsu[x])
        x = dsu[x], dsu[x] = dsu[dsu[x]];
    return x;
}

void dfsmax(int cur, int pre){
    firstmax[cur] = ++tmax;
    spmax[0][cur] = pre;
    for(int u: adjmax[cur]){
        if(u != pre)
            dfsmax(u, cur);
    }
    lastmax[cur] = tmax;
}

void dfsmin(int cur, int pre){
    firstmin[cur] = ++tmin;
    spmin[0][cur] = pre;
    for(int u: adjmin[cur]){
        if(u != pre)
            dfsmin(u, cur);
    }
    lastmin[cur] = tmin;
}

vector<int> check_validity(int _n, vector<int> a, vector<int> b, vector<int> st, vector<int> ed, vector<int> l, vector<int> r){
    n = _n, m = st.size();
    vector<int> ans(m);
    for(int i = 0; i < a.size(); i++){
        adj[a[i]].emplace_back(b[i]);
        adj[b[i]].emplace_back(a[i]);
    }
    init();
    for(int i = 0; i < n; i++){
        for(int u: adj[i]){
            u = find(u);
            if(u < i){
                dsu[u] = i;
                adjmax[u].push_back(i);
                adjmax[i].push_back(u);
            }
        }
    }
    init();
    for(int i = n-1; i >= 0; i--){
        for(int u: adj[i]){
            u = find(u);
            if(u > i){
                dsu[u] = i;
                adjmin[u].push_back(i);
                adjmin[i].push_back(u);
            }
        }
    }
    
    memset(spmax, -1, sizeof spmax);
    memset(spmin, -1, sizeof spmin);
    
    dfsmax(n-1, -1);
    dfsmin(0, -1);
    
    for(int i = 1; i < LOG; i++){
        for(int j = 0; j < n; j++){
            if(~spmax[i-1][j])
                spmax[i][j] = spmax[i-1][ spmax[i-1][j] ];
            if(~spmin[i-1][j])
                spmin[i][j] = spmin[i-1][ spmin[i-1][j] ];
        }
    }
    
    for(int i = 0; i < m; i++){
        int na = ed[i], nb = st[i];
        
        for(int j = LOG-1; j >= 0; j--){
            if(~spmax[j][na] and spmax[j][na] <= r[i])
                na = spmax[j][na];
            if(~spmin[j][nb] and spmin[j][nb] >= l[i])
                nb = spmin[j][nb];
        }
        q.emplace_back(1, firstmax[na]-1, firstmin[nb], lastmin[nb], i);
        q.emplace_back(2, lastmax[na], firstmin[nb], lastmin[nb], i);
    }
    
    for(int i = 0; i < n; i++)
        q.emplace_back(0, firstmax[i], firstmin[i]);
    
    sort(q.begin(), q.end());
    
    for(auto v: q){
        if(v.op == 0)
            update(v.ly);
        else if(v.op == 1)
            ans[v.id] -= query(v.ry) - query(v.ly-1);
        else
            ans[v.id] += query(v.ry) - query(v.ly-1);
    }
    
    for(int &i: ans)
        i = i > 0;
    
    return ans;
}

#ifndef ONLINE_JUDGE
int main(){
    vector<int> zz = check_validity(6, {5,1,1,3,3,5}, {1,2,3,4,0,2}, {4,4,5}, {2,2,4}, {1,2,3}, {2,2,4});
    for(int i: zz)
        printf("%d ", i);
    
    return 0;
}
#endif