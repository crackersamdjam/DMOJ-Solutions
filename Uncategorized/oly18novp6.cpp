#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

using ll = long long;
const int MM = 1e5+1;
int n, m;
ll bit[MM];
map<int, int> mp;

void up(int i, int v){
    for(; i < MM; i += i&-i)
        bit[i] += v;
}
ll qu(int i){
    ll r = 0;
    for(; i; i -= i&-i)
        r += bit[i];
    return r;
}

int main(){
    init();
    scan(n);
    for(int i = 1,a; i <= n; i++){
        scan(a);
        mp[i] = a;
        up(i, a);
    }

    scan(m);
    while(m--){
        int op, l, r;
        scan(op, l, r);
        if(op == 1){
            print(qu(r) - qu(l-1));
        }
        else{
            for(auto it = mp.lower_bound(l); it != mp.end() and it->first <= r;){
                //print(it->first, it->second);
                up(it->first, -it->second);
                it->second = sqrt(it->second);
                up(it->first, it->second);
                if(it->second < 2)
                    it = mp.erase(it);
                else
                    it++;
            }
        }
    }
    
    return 0;
}