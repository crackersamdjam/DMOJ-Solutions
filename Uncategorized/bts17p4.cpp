#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
typedef pair<int, int> pii;
const int MM = 1e5+2;

int N, M, J, t[MM];
deque<pii> q;

int main(){
    
    scan(N, M, J);
    
    memset(t, 0x3f, sizeof t);
    t[0] = t[N+1] = 0;
    
    for(int i = 0,p,tm; i < M; i++){
        scan(p, tm);
        t[p] = tm;
    }
    
    q.push_front({0, 0});
    
    for(int i = 1; i <= N+1; i++){
        while(!q.empty() && q.front().first + J < i)
            q.pop_front();
        
        t[i] = max(q.front().second, t[i]);
    
        while(!q.empty() && t[i] <= q.back().second)
            q.pop_back();
    
        q.push_back({i, t[i]});
    }
    
    print(t[N+1] == 0x3f3f3f3f? -1: t[N+1]);
    
    return 0;
}