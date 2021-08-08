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
const int MM = 2002;

int n, m, ps[MM];
char a[MM][MM];
stack<pair<int, int>> st;
ll ans;

ll f(ll x){
    return (x+2)*(x+1)*x/6;
}

int main(){
    
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; i++){
        scanf("%s", a[i]+1);
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m+1; j++){
            if(a[i][j] == '.')
                ps[j]++;
            else
                ps[j] = 0;
            
            while(!st.empty() && ps[j] <= st.top().first){
                auto last = st.top(); st.pop();
                int loc = st.empty() ? 1 : (st.top().second + 1);
                int sub = max(st.empty() ? 0 : st.top().first, ps[j]);
                
                ll len = j-1 - loc+1;
                ll h = (ll)(last.first+sub+1)*(last.first-sub)/2;
                
                ans += f(len)*h;
            }
            st.push({ps[j], j});
        }
        st.pop();
        assert(st.empty());
    }
    
    print(ans);
    
    return 0;
}