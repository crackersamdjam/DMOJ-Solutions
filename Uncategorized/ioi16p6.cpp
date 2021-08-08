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

#define max(x, y) ((x) > (y) ? (x) : (y))
#define sq(x) (x)*(x)

using ll = long long;
using ld = long double;
using pii = std::pair<int, int>;
const int MM = 1e5+2;
const ld eps = 1e-4;

int n, q[MM], cnt[MM], K, ab, bb;
ld dp[MM];
pii a[MM], b[MM];

inline bool cmp(pii x, pii y){
    if(x.first != y.first)
        return x.first < y.first;
    return x.second > y.second;
}

inline ld eval(int l, int i){
    return dp[l] + sq((ll)(a[i].second - a[l+1].first + 1)) - sq((ll)max(0, a[l].second - a[l+1].first + 1));
    //p[j] + (x[i] - y[j+1])^2 - (x[j] - y[j+1])^2
}

inline int inter(int i, int f, int s){
    static int l, m, r;
    l = i+1, r = n;
    while(l <= r){
        m = (l+r)/2;
        if(eval(f, m) < eval(s, m))
            l = m+1;
        else
            r = m-1;
    }
    //find first when f gives higher (or equal), will never use f again
    return l;
}

inline void run(ld cost){
    static int l, r, i;
    for(i = 1, l = r = 0; i <= n; i++){
        
        while(r-l >= 1 && (eval(q[l], i) >= eval(q[l+1], i)))
            l++;
        
        dp[i] = eval(q[l], i) + cost;
        cnt[i] = cnt[q[l]] + 1;
        
        while(r-l >= 1 && inter(i, q[r-1], q[r]) >= inter(i, q[r], i))
            r--;
        
        q[++r] = i;
    }
}

long long take_photos(int Ln, int M, int Lk, int *R, int *C){
    
    n = Ln, K = Lk;
    
    for(int i = 0; i < n; i++){
        if(R[i] < C[i])
            b[bb++] = {R[i], C[i]};
        else
            b[bb++] = {C[i], R[i]};
    }
    
    sort(b, b+bb, cmp);
    
    //add filter to remove points with points top-right of it
    a[ab++] = {-1, -1};
    
    int high = -1;
    for(const auto &i: b){
        if(i.second > high){
            high = i.second;
            a[ab++] = i;
        }
    }
    
    n = ab-1;
    
    if(n < K)
        K = n;
    
    ld l = 0, m, r = 1e12+1;
    while(r-l >= eps){
        m = (l+r)/2;
        run(m);
        
        if(cnt[n] == K)
            return round(dp[n] - m*K);
        
        if(cnt[n] > K)
            l = m;
        else
            r = m;
    }
    
    run(r);
    
    return (ll)round(dp[n] - r*K);
}

#ifndef ONLINE_JUDGE

int main(){
    
    freopen("in.txt", "r", stdin);
    
    int i1, i2, i3;
    scan(i1, i2, i3);
    int a1[i1], a2[i1];
    for(int i = 0; i < i1; i++)
        scan(a1[i], a2[i]);
    print(take_photos(i1, i2, i3, a1, a2));
    
    /*
    int a1[] = {0, 4, 4, 4, 4}, a2[] = {3, 4, 6, 5, 6},
    a3[] = {1, 4}, a4[] = {4, 1};
    print(take_photos(5, 7, 2, a1, a2));
    //print(take_photos(2, 6, 2, a3, a4));
    */
    return 0;
}

#endif


/*
 * n^2 k sol
 * dp[k][i] = min{dp[k-1][j] + (x[i] - y[j+1])^2 - (x[j] - y[j+1])^2}
 * (x is down, y is right)
 *(max(0, x[j] - y[j+1]))^2   --may not need to subtract
 *
 * dp[j] + (x[i] - y[j+1])^2 - (x[j] - y[j+1])^2 <= dp[k] + (x[i] - y[k+1])^2 - (x[k] - y[k+1])^2  ;  j < k
 *
 */