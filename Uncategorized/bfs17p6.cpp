#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define _CRT_SECURE_NO_WARNINGS
#endif
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef unsigned long long ll;
const int maxn = 100001, maxsz = 5001;

int N, pre[maxn];
ll bit[maxsz][maxsz], dp[maxn];
vector<int> vec;

struct st{
    int l,w,h,id;
    ll p;
    friend bool operator<(const st &x, const st &y){
        if(x.h == y.h){
            if(x.l == y.l)
                return x.w < y.w;
            return x.l < y.l;
        }
        return x.h < y.h;
    }
} a[maxn];

inline ll query(int x, int y){
    ll ret = 0;
    for(int i = x; i; i -= i&-i){
        for(int j = y; j; j -= j&-j){
            if(bit[i][j] > ret){
                ret = bit[i][j];
                //id = pre[i][j];
            }
        }
    }
    return ret;
}
inline void update(int x, int y, ll val){
    for(int i = x; i < maxsz; i += i&-i){
        for(int j = y; j < maxsz; j += j&-j){
            if(val > bit[i][j]){
                bit[i][j] = val;
                //pre[i][j] = id;
            }
        }
    }
}

int main(){
    
    scan(N);
    for(int i = 1; i <= N; i++){
        scan(a[i].l, a[i].w, a[i].h, a[i].p);
        if(a[i].l < a[i].w)
            swap(a[i].l, a[i].w);
        a[i].id = i;
    }
    
    sort(a+1, a+N+1);
    
    for(int i = 1; i <= N; i++){
        
        ll ans = query(a[i].l, a[i].w);
        dp[i] = ans + a[i].p;
        
        update(a[i].l, a[i].w, dp[i]);
    }
    
    int st;
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        //printf("%lld %lld\n", dp[i], a[i].p);
        if(dp[i] > ans){
            ans = dp[i];
            st = i;
        }
    }
    
    print(ans);
    
    while(st > 0){
        for(int i = st-1; i >= 0; i--){
            if(dp[st] - a[st].p == dp[i]){
                vec.push_back(a[st].id);
                st = i;
                break;
            }
        }
    }
    
    print(vec.size());
    
    for(int i: vec){
        printf("%d ", i);
    }
    
    return 0;
}