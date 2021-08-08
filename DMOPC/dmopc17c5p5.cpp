#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#ifndef ONLINE_JUDGE
template<typename T>
void printerr(T a){std::cout<<a<<std::endl;}
template<typename T,typename... Args>
void printerr(T a, Args... args) {std::cout<<a<<' ',printerr(args...);}
#else
template<typename... Args>
void printerr(Args... args){}
#endif

using namespace std;
const int MM = 2e5+5;

int n, m, q, a[MM], par[MM];

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

void go(int i, vector<int> &v){
    
    if(v.empty())
        return;
    if(i == -1){
        for(int j: v)
            par[find(j)] = find(v[0]);
        return;
    }
    vector<int> vl, vr;
    for(int j: v){
        if(a[j]&(1<<i))
            vl.emplace_back(j);
        else
            vr.emplace_back(j);
    }
    
    if(m&(1<<i)){
        if(vl.size())
            for(int j: vl)
              par[find(j)] = find(vl[0]);
        if(vr.size())
            for(int j: vr)
                par[find(j)] = find(vr[0]);
    
        vl.clear();
        vl.shrink_to_fit();
        vr.clear();
        vr.shrink_to_fit();
        go(i-1, v);
    }
    else{
        v.clear();
        v.shrink_to_fit();
        go(i-1, vl);
        go(i-1, vr);
    }
    vl.clear();
    vl.shrink_to_fit();
    vr.clear();
    vr.shrink_to_fit();
    v.clear();
    v.shrink_to_fit();
}

int main(){
    vector<int> v;
    scan(n, m, q);
    for(int i = 1; i <= n; i++){
        par[i] = i;
        scan(a[i]);
        v.emplace_back(i);
    }
    go(30, v);
    
    for(int i = 0,x,y; i < q; i++){
        scan(x, y);
        puts((find(x) == find(y)) ? "YES" : "NO");
    }
    
    return 0;
}