#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e5+1;

int N, M, K, par[MM];
unordered_set<int> cnt;

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

int main(){
    
    scan(N, M, K);
    
    for(int i = 1; i <= N; i++)
        par[i] = i;
    
    for(int i = 0,a,b; i < M; i++){
        scan(a, b);
        int fa = find(a), fb = find(b);
        par[fa] = fb;
    }
    
    for(int i = 1; i <= N; i++)
        cnt.insert(find(i));
    
    print(max(0, (int)cnt.size() - 1 - min(K, M - (N-(int)cnt.size()))));
    
    return 0;
}
/*
 * number of disjoint sets
 *
 * 1 fewer comp = 1 less pipe
 * M - (N-#) = extra
 *
 * ans = comps-1 - min(0, min(K, extra))
 *
 */