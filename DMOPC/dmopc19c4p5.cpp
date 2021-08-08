#define ONLINE_JUDGE

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void printerr(T a){std::cout<<a<<std::endl;}
template<typename T,typename... Args>
void printerr(T a, Args... args) {std::cout<<a<<' ',printerr(args...);}
#else
template<typename... Args>
void printerr(Args... args){}
#endif

using namespace std;
using ll = long long;
const int MM = 3e5+2, LOG = 21;

vector<int> adj[MM];
int n, m, q, dep[MM], lca[LOG][MM], a[MM];
ll psa[MM];

void dfs(int cur, int pre){
    lca[0][cur] = pre;
    dep[cur] = dep[pre]+1;
    for(int u: adj[cur])
        dfs(u, cur);
}

set<pair<ll, int>, greater<pair<ll, int>>> st;
int fr[MM];

int main(){
    
    scan(n, m, q);
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        psa[i] = a[i] + psa[i-1];
    }
    psa[n+1] = LLONG_MIN/4;
    for(int i = 1; i <= n+1; i++){
        st.insert({psa[i-1], i-1});
        while(st.size() and psa[i] - st.begin()->first < 0){
            int id = st.begin()->second;
            printerr("nx", id, i);
            adj[i].push_back(id);
            st.erase(st.begin());
        }
    }
    
    st.clear();
    for(int i = 1; i <= n+1; i++){
        st.insert({psa[i-1]-m, i-1});
        while(st.size() and psa[i] - st.begin()->first < 0){
            int id = st.begin()->second;
            fr[id] = i;
            printerr("fr", id, i);
            st.erase(st.begin());
        }
    }
    
    memset(lca, -1, sizeof lca);
    dfs(n+1, -1);
    for(int i = 1; i < LOG; i++){
        for(int j = 1; j <= n; j++){
            if(~lca[i-1][j])
                lca[i][j] = lca[i-1][ lca[i-1][j] ];
        }
    }
    
    for(int z = 0,l,r; z < q; z++){
        scan(l, r);
        printerr("qu", l, r, fr[l-1]);
        if(fr[l-1] > r){
            print(m + psa[r] - psa[l-1], 0);
            continue;
        }
        int f = fr[l-1], cnt = 1;
        
        for(int i = LOG-1; i >= 0; i--){
            if(~lca[i][f] and lca[i][f] <= r){
                cnt += (1<<i);
                f = lca[i][f];
            }
        }
        
        print(psa[r] - psa[f], cnt);
    }
    
    return 0;
}