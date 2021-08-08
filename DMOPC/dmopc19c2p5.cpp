#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using ll = long long;
const int MM = 3e5+1;

int n, cent, par[MM], subcent[MM], subid[MM];
std::vector<int> adj[MM];
ll p[MM], sz[MM], tpsz[MM], total, dp1[MM], dp2[MM], dep[MM], out = LLONG_MAX;

ll getsz(int cur, int pre){
    bool b = 1;
    tpsz[cur] = p[cur];
    for(int u: adj[cur]){
        if(u != pre){
            tpsz[cur] += getsz(u, cur);
            if(tpsz[u] > total/2)
                b = 0;
        }
    }
    if(b && ((total - tpsz[cur]) <= total/2))
        cent = cur;
    return tpsz[cur];
}

void dfs(int cur, int pre){
    
    if(pre == cent)
        subid[cur] = cur;
    else
        subid[cur] = subid[pre];
    //which child of cent cur is from
    
    dep[cur] = dep[pre]+1;
    par[cur] = pre;
    subcent[cur] = cur;
    sz[cur] = p[cur];
    ll most = 0; int id = cur;
    
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        
        dfs(u, cur);
        sz[cur] += sz[u];
        dp1[cur] += dp1[u] + sz[u];
        if(sz[u] > most){
            most = sz[u];
            id = u;
        }
    }
    
    int curcent = subcent[id];
    while(sz[curcent] <= sz[cur]/2){
        curcent = par[curcent];
    }
    
    subcent[cur] = curcent;
}

void dfs2(int cur, int pre){
    if(cur != cent)
        dp2[cur] = dp2[pre] + dp1[pre] - (dp1[cur]+sz[cur]) + (total - sz[cur]);
    
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        dfs2(u, cur);
    }
}

std::vector<int> v1, v2;

int main(){
    
    scan(n);
    
    for(int i = 1; i <= n; i++){
        scan(p[i]);
        total += p[i];
    }
    
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    getsz(1, 0);
    
    dep[0] = -1;
    dfs(cent, 0);
    
    dfs2(cent, 0);
    
    int ch1 = 0, ch2 = 0; ll w1 = 0, w2 = 0;
    for(int u: adj[cent]){
        if(sz[u] > w1)
            ch2 = ch1, w2 = w1, ch1 = u, w1 = sz[u];
        else if(sz[u] > w2)
            ch2 = u, w2 = sz[u];
    }
    
    int c = subcent[ch1];
    while(c != cent){
        v1.push_back(c);
        c = par[c];
    }
    v1.push_back(cent);
    
    if(!ch2) goto nx;
    c = subcent[ch2];
    while(c != cent){
        v2.push_back(c);
        c = par[c];
    }
    nx:;
    v2.push_back(cent);
    
    for(int u = 1; u <= n; u++){
        if(u == cent)
            continue;
        c = subcent[u];
        ll ans = dp1[c] + dp2[c] - dp2[u] - (total - sz[u])*(dep[c] - dep[u]);
        //last one is above travelling down to c
        
        if(subid[u] == ch1){
    
            ll newtot = total - sz[u];
            
            int l = 0, m, r = v2.size()-1;
            while(l < r-1){ //when l = r-1, can stop and try both
                m = (l+r)/2;
                ll s1 = sz[v2[m]] - p[v2[m]], s2 = newtot-sz[v2[m]];
                if(s1 < s2)
                    l = m;
                else
                    r = m;
            }
            l = v2[l], r = v2[r];
            ll ans2 = dp2[l] + dp1[l] - dp1[u] - sz[u]*(dep[u] + dep[l]);
            ans2 = std::min(ans2, dp2[r] + dp1[r] - dp1[u] - sz[u]*(dep[u] + dep[r]));
            out = std::min(out, ans+ans2);
            
        }
        else{
            ll newtot = total - sz[u];
            
            int l = 0, m, r = v1.size()-1;
            while(l < r-1){ //when l = r-1, can stop and try both
                m = (l+r)/2;
                ll s1 = sz[v1[m]] - p[v1[m]], s2 = newtot-sz[v1[m]];
                if(s1 < s2)
                    l = m;
                else
                    r = m;
            }
            l = v1[l], r = v1[r];
            
            ll ans2 = dp2[l] + dp1[l] - dp1[u] - sz[u]*(dep[u] + dep[l]);
            ans2 = std::min(ans2, dp2[r] + dp1[r] - dp1[u] - sz[u]*(dep[u] + dep[r]));
            
            out = std::min(out, ans+ans2);
        }
    }
    
    print(out);
    
    return 0;
}