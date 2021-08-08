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
const int MM = 1e5+2;

int n;
ll k, v[MM];
set<string> rm, out;
set<pair<ll, string>> st;
string s[MM];

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> s[i] >> v[i];
        st.insert({v[i], s[i]});
    }
    
    for(int i = 0; i < n; i++){
        if(st.lower_bound({v[i]-k, ""}) != st.end() && *st.lower_bound({v[i]-k, ""}) < make_pair(v[i], s[i]))
            rm.insert(s[i]);
        string ed = "}";
        if(st.upper_bound({v[i], s[i]}) != st.end() && *st.upper_bound({v[i], s[i]}) < make_pair(v[i]+k, ed))
            rm.insert(s[i]);
    }
    
    for(int i = 0; i < n; i++){
        if(!rm.count(s[i]))
            out.insert(s[i]);
    }
    
    for(auto i: out)
        cout << i << ' ';
    
    return 0;
}