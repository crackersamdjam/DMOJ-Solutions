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

ll n, m, last = 1000000, day, ans;
map<ll, ll> cnt, best;
int q;

int main(){
    
    scan(n, m, q);
    
    day = n;
    best[n] = last;
    
    while(q--){
        ll d, p;
        scan(d, p);
        if(d == day){
            best[d] = min(best[d], p);
        }
        else{
            cnt[last] += (day-d-1);
            best[d] = min(last, p);
        }
        day = d, last = p;
    }
    
    cnt[last] += day-1;
    
    for(auto i: best)
        cnt[i.second]++;
    
    for(auto i: cnt){
        ll sub = min(m, i.second);
        m -= sub;
        ans += sub*i.first;
        if(!m)
            break;
    }
    
    print(ans);
    
    return 0;
}