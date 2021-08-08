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
typedef pair<int, int> pii;

int n;
ll ans;
map<pii, int> pt;

int main(){
    
    scan(n);
    
    while(n--){
        int a, b;
        scan(a, b);
        pt[{a, b}] = 1;
    }
    
    for(auto i: pt){
        for(auto j: pt){
            if(pt.count({i.first.first, j.first.second}) && pt.count({j.first.first, i.first.second}))
                ans = max(ans, abs((ll)(i.first.first - j.first.first) * (i.first.second - j.first.second)));
        }
    }
    
    print(ans);
    
    return 0;
}