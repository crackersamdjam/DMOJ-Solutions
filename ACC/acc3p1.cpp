#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
int N,K,a[MM],mp[MM];
int main(){
    sc(N); sc(K);
    for(int i = 0; i < N; i++){
        sc(a[i]);
    }
    mp[a[0]]++;
    int val = 1, l = 0, r = 0;
    ll ans = 0;
    while(l < N){
        if(r == N-1){
            if(val >= K)
                ans++;
            
            if(--mp[a[l++]] == 0)
                val--;
            
        }else if(val >= K){
            ans += N-r;
            if(--mp[a[l++]] == 0)
                val--;
            
        }else{
            if(++mp[a[++r]] == 1)
                val++;
        }
    }
    printf("%lld\n", ans);
    return 0;
}