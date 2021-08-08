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

int t, n, m;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        map<string, vector<pair<int, int>>> mp;
        cin>>n;
        while(n--){
            cin>>m;
            while(m--){
                string s;
                int a, b;
                cin>>s>>a>>b;
                mp[s].emplace_back(a, b);
            }
        }
        cin>>n;
        int ans = 0;
        while(n--){
            string s; int a;
            cin>>s>>a;
            sort(all(mp[s]));
            for(auto i: mp[s]){
                int sub = min(a, i.second);
                i.second -= sub;
                a -= sub;
                ans += sub*i.first;
            }
        }
        cout<<ans<<'\n';
    }
    
    
    return 0;
}