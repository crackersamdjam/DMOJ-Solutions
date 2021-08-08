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
const int MM = 1e5+2;

int n, m, k;
map<int, ll> mp[MM];
vector<int> ch[MM];
pair<int, ll> add[MM];

void dfs(int cur){
    //printf("cur1 %d\n", cur);
    for(int u: ch[cur]){
        dfs(u);
        
        if(mp[u].size() > mp[cur].size())
            swap(mp[u], mp[cur]);
        
        for(auto i: mp[u])
            mp[cur][i.first] += i.second;
    }
    
    if(add[cur].first){
        //printf("insert "); print(cur, add[cur].first, add[cur].second);
        mp[cur][add[cur].first] += add[cur].second;
        ll rem = add[cur].second;
        for(auto it = mp[cur].upper_bound(add[cur].first); it != mp[cur].end() && rem; it++){
            ll sub = min(rem, it->second);
            it->second -= sub;
            rem -= sub;
        }
    }
    
    /*
    printf("cur %d\n", cur);
    for(auto i: mp[cur]){
        print(i.first, i.second);
    }
    pc(10);
     */
}


int main(){
    
    scan(n, m, k);
    
    for(int i = 2,p; i <= n; i++){
        scan(p);
        ch[p].push_back(i);
        //print(p, i);
    }
    
    while(m--){
        int u, d, w;
        scan(u, d, w);
        add[u] = {d, w};
        //print(u, d, w);
    }
    
    dfs(1);
    
    ll ans = 0;
    for(auto i: mp[1])
        ans += i.second;
    
    print(ans);
    
    return 0;
}