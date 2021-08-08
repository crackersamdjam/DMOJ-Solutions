#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 100001;

int n, m, k, ds[3][MM];
int a[MM], b[MM], t[MM];
set<int> s[2];

int find(int i, int x){
    while(x != ds[i][x])
        x = ds[i][x], ds[i][x] = ds[i][ds[i][x]];
    return x;
}

int main(){
    
    scan(n, m, k);
    
    for(int i = 1; i <= n; i++)
        ds[0][i] = ds[1][i] = ds[2][i] = i;
    
    for(int i = 0; i < m; i++){
        scan(a[i], b[i], t[i]);
        int fa = find(t[i], a[i]), fb = find(t[i], b[i]);
        ds[t[i]][fa] = fb;
    }
    
    for(int i = 0; i < m; i++){
        int fa = find(!t[i], a[i]), fb = find(!t[i], b[i]);
        int ga = find(2, a[i]), gb = find(2, b[i]);
        //other edge type can not connect these
        if(fa != fb and ga != gb){
            s[t[i]].insert(i);
            ds[!t[i]][fa] = fb;
            ds[2][ga] = gb;
        }
    }
    
    for(int i = 0; i < m; i++){
        int fa = find(2, a[i]), fb = find(2, b[i]);
        if(fa == fb || s[0].count(i) || s[1].count(i)) continue;
        if(s[0].size() < k && !t[i]){
            s[0].insert(i);
            ds[2][fa] = fb;
        }
        if(s[1].size() < n-k-1 && t[i]){
            s[1].insert(i);
            ds[2][fa] = fb;
        }
    }
    
    if(s[0].size() != k || s[1].size() != n-k-1)
        return 0*puts("no solution");
    
    for(int i: s[0])
        print(a[i], b[i], t[i]);
    for(int i: s[1])
        print(a[i], b[i], t[i]);
    
    return 0;
}