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
const int MM = 5e5+5;
const ll mod = 1e9+7;

ll sum, p[MM];
int n, m;
char s[MM];
set<int> st;

int main(){
    scanf("%d %d %s", &n, &m, s+1);
    p[n] = 1;
    for(int i = n-1; i; i--)
        p[i] = p[i+1]*2%mod;
    
    for(int i = 1; i <= n; i++){
        if(s[i] == '1'){
            sum = (sum + p[i]) % mod;
        }
        else{
            st.insert(i);
        }
    }
    for(int t = 0,l,r; t < m; t++){
        scan(l, r);
        for(auto it = st.lower_bound(l); it != st.end() and *it <= r; it = st.erase(it)){
            sum = (sum + p[*it]) % mod;
        }
        print(sum);
    }
    
    
    return 0;
}