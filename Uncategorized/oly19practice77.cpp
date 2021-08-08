#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;

ll ans;
int n, m;
map<int, int> mp;

int main(){
    
    scan(n, m);
    mp[0] = -1;
    mp[m] = 1;
    //as if 0 to m is empty, would have to ride to m anyway
    
    for(int i = 0,a,b; i < n; i++){
        scan(a, b);
        ans += abs(a-b);
        mp[a]++;
        mp[b]--;
    }
    
    ll last = 0, ps = 0;
    for(auto i: mp){
        ans += (i.first-last)*abs(ps);
        //print(i.first, i.first-last, abs(ps));
        ps += i.second;
        last = i.first;
    }
    
    print(ans);
    
    return 0;
}