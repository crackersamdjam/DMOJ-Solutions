#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

map<int, int> nums;
map<pii, int> idk;
int N;

int main(){
    
    scan(N);
    
    ll ans = (ll)N*(N-1)/2;
    
    for(int i = 0,a,b; i < N; i++){
        scan(a, b);
        idk[{a, b}]++;
        nums[a]++;
    }
    
    for(auto i: nums){
        int n = i.second;
        ans -= (ll)n*(n-1)/2;
    }
    
    for(auto i: idk){
        int n = i.second;
        ans += (ll)n*(n-1)/2;
    }
    
    print(ans);
    
    return 0;
}