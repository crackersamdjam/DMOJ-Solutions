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
using ll = long long;
const int MM = 501, MN = 3001, MAXN = 6502; //MAXN only needs to be MN*2

int N, Q, F, K, ptr, Time;
ll dp[MAXN][MN], ans[MAXN];

vector<int> adj[MAXN];
stack<int> last[MM];
vector<ll> v;

struct st{
    
    int l, r, i, f, a, b, id;
    
    bool operator<(const st &o) const{return l < o.l;}
    
    void update(){
        ptr++;
        for(int j = 0; j < f; j++)
            dp[ptr][j] = -1e12;
        for(int j = f; j <= F; j++)
            dp[ptr][j] = dp[ptr-1][j-f] + a;
        
        for(ll k: v){
            for(ll j = F; j >= k*f; j--){
                if(dp[ptr][j-k*f] + k*b > dp[ptr][j]){
                    dp[ptr][j] = dp[ptr][j-k*f] + k*b;
                }
            }
        }
        for(int j = 0; j <= F; j++)
            dp[ptr][j] = max(dp[ptr][j], dp[ptr-1][j]);
    }
} all[MAXN];
vector<st> q, rq[MAXN];

void dfs(int i){
    int num = all[i].i;
    if(!last[num].empty()){
        //end last one
        int pre = last[num].top();
        all[pre].r = Time;
        q.push_back(all[pre]);
    }
    //start this one
    last[num].push(i);
    all[i].l = ++Time;
    for(int u: adj[i])
        dfs(u);
    
    //end this one
    all[i].r = Time;
    q.push_back(all[i]);
    last[num].pop();
    
    if(!last[num].empty()){
        //restart prevous one
        int pre = last[num].top();
        all[pre].l = ++Time;
    }
}

void solve(int l, int r){
    if(l == r){
        
        int ct = 0;
        q[l].update();
        for(auto i: rq[l]){
            i.update();
            ct++;
        }
    
        //only gets updated first time
        if(ans[q[l].id] == -1)
            ans[q[l].id] = dp[ptr][F];
        
        ptr--;
        ptr -= ct;
    }
    if(l >= r) return;
    int m = l+(r-l)/2, cursz = ptr;
    
    for(int i = m+1; i <= r; i++){
        //looping by right endpt
        for(auto j: rq[i]){
            if(j.l < l)
                j.update();
        }
    }
    solve(l, m);
    ptr = cursz;
    
    for(int i = l; i <= m; i++){
        if(q[i].r > r){
            q[i].update();
        }
    }
    solve(m+1, r);
    ptr = cursz;
}

int main(){
    
    memset(ans, -1, sizeof ans);
    
    scan(N, Q, F, K);
    
    int rem = K-1;
    for(ll j = 1; j <= rem; j *= 2){
        v.push_back(j);
        rem -= j;
    }
    if(rem) v.push_back(rem);
    
    for(int i = 1,f,a,b; i <= N; i++){
        scan(f, a, b);
        adj[i-1].push_back(i);
        all[i] = {0, -1, i, f, a, b, 0};
    }
    
    for(int i = 1,j,x,a,b; i <= Q; i++){
        scan(j, x, a, b);
        adj[j+N].push_back(i+N);
        all[i+N] = {0, -1, x, all[x].f, a, b, i};
    }
    
    q.push_back({}); //1-indexed
    
    dfs(1);
    
    //sort by time
    sort(q.begin(), q.end());
    
    for(auto i: q){
        if(i.l != i.r)
            rq[i.r].push_back(i);
        //don't conut twice
    }
    
    solve(1, q.size()-1);
    
    for(int i = 1; i <= Q; i++)
        print(ans[i]);
    
    return 0;
}