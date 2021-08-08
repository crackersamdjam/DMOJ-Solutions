#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}
template<typename First, typename ... Ints>
void print(First &arg, Ints&... rest) {print(arg);pc(32);print(rest...);pc(10);}

using namespace std;
const int MM = 5e5+1;

int N, a[MM], cnt[MM], ans, l, r;
vector<int> pos[MM<<1];

int main(){
    
    scan(N);
    
    for(int i = 1; i <= N; i++){
        scan(a[i]);
        cnt[i] = cnt[i-1] + (a[i] == i);
        if(i ^ a[i])
            pos[i + a[i]].push_back(abs(i-a[i]));
    }
    
    ans = cnt[N];
    l = 1, r = 1;
    
    for(int i = 0; i <= (N<<1); i++){
        
        sort(pos[i].begin(), pos[i].end());
        
        for(int j = 0; j < pos[i].size(); j++){
            int v = cnt[N] + (j+1) - ((cnt[(i+pos[i][j])>>1]) - cnt[((i-pos[i][j])>>1) - 1]);
            if(v > ans){
                ans = v;
                l = (i-pos[i][j])>>1, r = (i+pos[i][j])>>1;
            }
        }
    }
    
    print(a[l], a[r]);
    
    return 0;
}