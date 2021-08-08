#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using ll = long long;
const int MM = 4e5+5;
int mod;
inline int rm(int a){
    if(a < 0)
        a += mod;
    if(a >= mod)
        a -= mod;
    return a;
}
inline void mm(int &a){
    a = rm(a);
}

int n, nx[MM], g[MM], psa[MM], st[MM], ed[MM];
ll ans[MM], tot;

std::set<std::pair<int, int>> ele;
//last y, id

int main(){
    memset(nx, -1, sizeof nx);
    scan(n, mod);
    for(int i = 0; i < n; i++){
        scan(g[i], st[i]);
        g[i] %= mod;
        st[i] %= mod;
    }
    for(int i = 1; i < n; i++){
        scan(psa[i]);
        tot += psa[i];
        psa[i] = (psa[i] + psa[i-1]) % mod;
    }
    for(int i = 0; i < n; i++){
        ll l = rm(rm(rm(-psa[i]-st[i])));
        ll r = rm(l + g[i]);
        //change to when blocked
        st[i] = r;
        ed[i] = l; //ed is when blocking stops
        
        ele.insert({rm(st[i]-1), n+i});
    }
    
    for(int i = 0; i < n; i++){
        if(st[i] <= ed[i]){
            for(auto it = ele.lower_bound({st[i], 0}); it != ele.end() and it->first <= ed[i]; it = ele.erase(it)){
                nx[it->second] = i;
                ans[it->second] = rm(ed[i] - it->first);
            }
        }
        else{
            for(auto it = ele.begin(); it != ele.end() and it->first <= ed[i]; it = ele.erase(it)){
                nx[it->second] = i;
                ans[it->second] = rm(ed[i] - it->first);
            }
            for(auto it = ele.lower_bound({st[i], 0}); it != ele.end(); it = ele.erase(it)){
                nx[it->second] = i;
                ans[it->second] = rm(ed[i] - it->first);
            }
        }
        ele.insert({ed[i], i});
    }
    
    for(int i = n-1; i >= 0; i--){
        if(~nx[i])
            ans[i] += ans[nx[i]];
    }
    ll best = 1e16;
    for(int i = 2*n-1; i >= n; i--){
        if(~nx[i])
            ans[i] += ans[nx[i]];
        if(ans[i] < best)
            best = ans[i];
    }
    
    print(tot+best);
    
    return 0;
}