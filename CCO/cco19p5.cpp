#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
const int M = 1e5+1;

int n, m;
set<int> s[M];
ll ans;

int main(){
    
    scan(n, m);
    
    for(int i = 0,a,b; i < m; i++){
        scan(a, b);
        if(a > b)
            swap(a, b);
        s[a].insert(b);
    }
    
    for(int i = 1; i <= n; i++){
        if(s[i].empty())
            continue;
        ans += s[i].size();
        int u = *s[i].begin();
        s[i].erase(s[i].begin());
        
        if(s[i].size() > s[u].size())
            swap(s[i], s[u]);
        
        s[u].insert(s[i].begin(), s[i].end());
    }
    
    print(ans);
    
    
    return 0;
}