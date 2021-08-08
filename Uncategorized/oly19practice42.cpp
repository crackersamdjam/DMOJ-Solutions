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
const int MM = 5e5+5;
ll base = 131, mod = 1685518853;

int T;
ll hs[MM], tg, p[MM];
string s, t;
vector<pair<int, int>> v;

int main(){
    
    p[0] = 1;
    for(int i = 1; i < MM; i++)
        p[i] = p[i-1]*base % mod;
    
    cin >> T;
    
    while(T--){
        
        cin >> s >> t;
        int n = s.size(), m = t.size();
        
        hs[0] = s[0];
        for(int i = 1; i < n; i++){
            hs[i] = (hs[i-1]*base + s[i]) % mod;
        }
        tg = t[0];
        for(int i = 1; i < m; i++){
            tg = (tg*base + t[i]) % mod;
        }
        
        bool pos = 0;
        int sub = (n-m+1)/2;
        v.clear();
        
        for(int i = 0; i <= n-m; i++){
            //cout << i << ' ' << s.substr(i, m) << '\n';
            ll val = hs[i+m-1] - ((hs[i-1]*p[m])%mod);
            val = ((val % mod) + mod) % mod;
            //if(s.substr(i, m) == t){
                //print(i, val, tg);
                //fflush(stdout);
                //assert(val == tg);
            //}
            if(val == tg){
                v.push_back({i, i+m-1});
                pos = 1;
            }
        }
        
        for(int i = 0; i < v.size(); i++){
            
            int ll = v[i].first, rr = ((i == v.size()-1) ? (100000000) : (n-1-v[i+1].second));
            //getting length
            
            if(sub > ll+rr+1){ //both
                pos = 0;
                break;
            }
        }
        
        if(!v.empty()){
            int ll = v.back().first, rr = n-1-v[0].second;
            if(sub > ll || sub > rr){
                pos = 0;
            }
        }
        
        if(!pos)
            puts("Andrew");
        else
            puts("William");
    }
    
    return 0;
}