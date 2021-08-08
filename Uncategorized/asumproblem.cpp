#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4,popcnt,abm,mmx,tune=native")

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

int n;
long long sum;
std::vector<int> vv = {0, 52, 17, 1, 9, 95, 10000000};

inline int ask(int i){
#ifdef ONLINE_JUDGE
    printf("? %d\n", i);
    fflush(stdout);
#endif
    int k = 0;
#ifndef ONLINE_JUDGE
    for(int j: vv)
        if(j >= i)
            k++;
    return k;
#endif
    scanf("%d", &k);
    return k;
}

void go(int l, int r, int cnt, int adj){
    //print(l, r, cnt);
    if(!cnt) return;
    if(l == r){
        //printf("add %d*%d\n", l, cnt);
        sum += (long long)l*cnt;
        return;
    }
    int m = (l+r+1)/2;
    int k = ask(m)-adj;
    //print(m, k);
    go(l, m-1, cnt-k, adj+k);
    go(m, r, k, adj);
}

int main(){

#ifndef ONLINE_JUDGE
    n = vv.size();
#else
    scanf("%d", &n);
#endif
    go(0, 1e7, n, 0);
    
    printf("! %lld\n", sum);
    fflush(stdout);
    
    return 0;
}