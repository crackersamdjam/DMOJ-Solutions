#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+1;

vector<int> a;
int n, x, v[MM], dp[MM], bit[MM<<1];
map<int, int> mp;

void add(int i, int k){
    for(; i < (MM<<1); i += i&-i)
        bit[i] = max(bit[i], k);
}

int query(int i){
    int ret = 0;
    for(; i; i -= i&-i)
        ret = max(ret, bit[i]);
    return ret;
}

int main(){
    
    scan(n, x);
    
    for(int i = 1; i <= n; i++){
        scan(v[i]);
        mp[v[i]] = mp[v[i]+x] = 0;
    }
    
    int t = 0;
    for(auto &x: mp)
        x.second = ++t;
    
    a.push_back(0);
    
    for(int i = 1; i <= n; i++){
        
        dp[i] = query(mp[v[i]+x]-1);
        
        if(mp[v[i]] > a.back())
            a.push_back(mp[v[i]]);
        else
            *lower_bound(a.begin(), a.end(), mp[v[i]]) = mp[v[i]];
        
        add(mp[v[i]], lower_bound(a.begin(), a.end(), mp[v[i]]) - a.begin() + 1);
    }
    
    int ans = 0;
    
    a.clear();
    a.push_back(INT_MAX);
    
    for(int i = n; i; i--){
        if(mp[v[i]] < a.back())
            a.push_back(mp[v[i]]);
        else
            *lower_bound(a.begin(), a.end(), mp[v[i]], greater<>()) = mp[v[i]];
    
        ans = max((long)ans, dp[i] + lower_bound(a.begin(), a.end(), mp[v[i]], greater<>()) - a.begin() - 1);
    }
    
    print(ans);
    
    return 0;
}