#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;

int N, K;
vector<pair<int, int>> a, b;
ll ans;

int main(){
    
    scan(N, K);
    
    for(int i = 0,x,m; i < N; i++){
        scan(x, m);
        if(x > 0)
            a.push_back({x, m});
        else
            b.push_back({-x, m});
    }
    
    a.push_back({0, 1e9});
    sort(a.begin(), a.end());
    
    int sub = 0;
    
    while(a.size() > 1){
        
        ll n = max(0, (a.back().second-1-sub)/K+1);
        
        ans += a.back().first*2*n;
        
        a.back().second -= n*K;
        
        while(a.back().second <= 0){
            int t = a.back().second;
            a.pop_back();
            a.back().second += t;
        }
    }
    
    
    a = b;
    a.push_back({0, 1e9});
    sort(a.begin(), a.end());
    
    sub = 0;
    
    while(a.size() > 1){
        
        ll n = max(0, (a.back().second-1-sub)/K+1);
        
        ans += a.back().first*2*n;
        
        a.back().second -= n*K;
        
        while(a.back().second <= 0){
            int t = a.back().second;
            a.pop_back();
            a.back().second += t;
        }
    }
    
    print(ans);
    
    return 0;
}