#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
#ifndef ONLINE_JUDGE
#define peek(x) cout << #x << ' ' << x << endl
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}
#else
#define peek(x) (x)
template<typename First, typename ... Ints> void print(First arg, Ints... rest){}
#endif
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 2e5+1;

int n;
ll a[MM], dp[MM], sz[MM], ans, ANS, SUM, total;
vector<int> adj[MM], vec;

ll getsz(int cur, int pre){
    bool b = 1;
    sz[cur] = a[cur];
    for(int u: adj[cur]){
        if(u != pre){
            sz[cur] += getsz(u, cur);
            if(sz[u] > total/2)
                b = 0;
        }
    }
    if(b && ((total - sz[cur]) <= total/2))
        vec.push_back(cur);
    return sz[cur];
}

void dfs(int cur, int pre){
    
    dp[cur] = a[cur];
    
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        
        dfs(u, cur);
        ans += a[cur]*dp[u];
        dp[cur] += dp[u];
    }
}

vector<ll> v1, v2, st;

void run(int cent){
    
    ans = 0;
    v1.clear();
    v2.clear();
    st.clear();
    
    dfs(cent, 0);
    
    for(int u: adj[cent])
        v1.push_back(dp[u]);
    
    int nn = v1.size()/2;
    
    v2.insert(v2.end(), v1.begin()+nn, v1.end());
    v1.resize(nn);
    
    ll s1 = 0, s2 = 0;
    for(ll i: v1)
        s1 += i;
    for(ll i: v2)
        s2 += i;
    
    int m = v2.size();
    for(ll i = 0; i < (1<<nn); i++){
        ll s = 0;
        for(int j = 0; j < nn; j++){
            if((i>>j)&1)
                s += v1[j];
        }
        st.push_back(s);
    }
    
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    
    ll val = 0;
    
    for(ll i = 0; i < (1<<m); i++){
        ll s = 0;
        for(int j = 0; j < m; j++){
            if((i>>j)&1)
                s += v2[j];
        }
        auto v = upper_bound(st.begin(), st.end(), max(0LL, (s1+s2)/2-s));
        if(v != st.end()){
            ll f = *v + s;
            ll se = s1+s2 - f;
            val = max(val, f*se);
        }
        if(v != st.begin()){
            ll f = *--v+s;
            ll se = s1+s2-f;
            val = max(val, f*se);
        }
    }
    
    ANS = max(ANS, ans+val+SUM);
}

int main(){

    scan(n);
    
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        total += a[i];
        SUM += (ll)a[i]*(a[i]-1);
    }
    
    for(int i = 2,p; i <= n; i++){
        scan(p);
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    
    getsz(1, 0);
    
    for(int i: vec)
        run(i);
    
    printf("%lld\n", ANS);
    
    return 0;
}