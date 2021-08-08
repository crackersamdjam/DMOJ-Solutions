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

ll A, B, K;
vector<ll> vec;

int main(){
    
    scan(A, B, K);
    
    for(ll i = 2; i*i <= A; i++){
        if(A % i == 0){
            if(B % i == 0)
                vec.push_back(i);
            
            ll j = A/i;
            if(j != i && B % j == 0)
                vec.push_back(j);
        }
    }
    
    vec.push_back(1);
    ll m = A;
    if(m != 1 && A % m == 0 && B % m == 0)
        vec.push_back(m);
    
    sort(vec.begin(), vec.end());
    
    if(vec.size() < K)
        puts("-1");
    else
        print(vec[vec.size() - K]);
    
    return 0;
}