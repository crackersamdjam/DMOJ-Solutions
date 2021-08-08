#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e6+5;

int N, dest[MM];
char a[MM];
set<pair<int,int>> let;
long long ans, bit[MM];

inline void update(int i){
    for(++i; i < MM; i += i&-i)
        bit[i]++;
}

inline ll query(int i){
    ll ret = 0;
    for(++i; i; i -= i&-i)
        ret += bit[i];
    return ret;
}

int main(){
    
    scan(N);
    
    for(int i = 0; i < N; i++)
        a[i] = gc;
    
    for(int i = 0, n = gc; i < N; i++){
        n = gc;
        let.insert({n, i});
    }
    
    for(int i = 0; i < N; i++){
        auto pos = let.lower_bound({a[i], 0});
        dest[i] = pos->second;
        let.erase(pos);
    }
    
    for(int i = N-1; i >= 0; i--){
        ans += query(dest[i]);
        update(dest[i]);
    }
    
    print(ans);
    
    return 0;
}