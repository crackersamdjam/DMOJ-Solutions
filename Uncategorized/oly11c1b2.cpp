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

string a, b;

set<ll> ans;

int main(){
    
    cin >> a >> b;
    
    for(int i = 0; i < a.size(); i++){
        string na = a;
        na[i] ^= 1;
        ll v = 0;
        for(int j = 0; j < na.size(); j++){
            v += (na[j]-'0')*(1<<(na.size()-j-1));
        }
        ans.insert(v);
    }
    
    for(int i = 0; i < b.size(); i++){
        string nb = b;
        for(int k = '0'; k < '3'; k++){
            if(b[i] == k)
                continue;
            nb[i] = k;
            
            ll v = 0;
            for(int j = 0; j < nb.size(); j++){
                v += (nb[j]-'0')*(ll)pow(3, b.size()-j-1);
            }
            if(ans.count(v)){
                print(v);
                return 0;
            }
        }
    }
    
    return 0;
}