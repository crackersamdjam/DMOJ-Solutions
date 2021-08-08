#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 1e5+5, SQ = 300;

int n, q, id[MM];
ll a[MM], gcd[MM], val[MM];
set<pair<ll, int>> in[MM];

int main(){
    scan(n);
    for(int i = 0,f; i < n; i++){
        f = id[i] = i/SQ;
        scan(a[i]);
        gcd[f] = __gcd(gcd[f], a[i]);
        val[f] ^= a[i];
        
        in[f].insert({val[f], i});
    }
    scan(q);
    for(int t = 0,op,l; t < q; t++){
        ll x;
        scan(op);
        if(op == 1){
            scan(l, x);
            a[l] = x;
            int f = id[l];
            gcd[f] = val[f] = 0;
            in[f].clear();
            
            for(int i = f*SQ; i < (f+1)*SQ; i++){
                gcd[f] = __gcd(gcd[f], a[i]);
                val[f] ^= a[i];
                
                in[f].insert({val[f], i}); //xor so far in the block
            }
        }
        else{
            scan(x);
            int ans = 1e9;
            ll pre = 0, pregcd = 0;
            for(int j = 0; j*SQ < n; j++){
                if(j == 0 or pregcd != __gcd(pregcd, gcd[j])){
                    //loop
                    for(int i = j*SQ; i < (j+1)*SQ; i++){
                        pre ^= a[i];
                        pregcd = __gcd(pregcd, a[i]);
                        if(pre*pregcd == x){
                            ans = i;
                            break;
                        }
                    }
                }
                else{
                    if(x % pregcd == 0){
                        ll tar = (x/pregcd)^pre;
                        auto it = in[j].lower_bound({tar, 0});
                        if(it != in[j].end() and it->first == tar){
                            ans = it->second;
                            break;
                        }
                    }
                    pre ^= val[j];
                    assert(pregcd == __gcd(pregcd, gcd[j]));
                }
            }
            
            print((ans == 1e9)? -1: ans);
        }
    }
    
    return 0;
}