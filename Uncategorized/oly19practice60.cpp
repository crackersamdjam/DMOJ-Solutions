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
const int MM = 1e6+2;

ll ans;
int n, a[MM], low[MM];
stack<int> st;

int main(){
    
    memset(low, 0x3f, sizeof low);
    
    scan(n);
    
    for(int i = 0; i < n; i++){
        scan(a[i]);
        while(!st.empty() and st.top() < a[i])
            st.pop();
        if(!st.empty())
            low[i] = st.top();
        st.push(a[i]);
    }
    while(!st.empty()) st.pop();
    
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() and st.top() <= a[i])
            st.pop();
        if(!st.empty())
            low[i] = min(st.top(), low[i]);
        st.push(a[i]);
    }
    
    for(int i = 0; i < n; i++){
        if(low[i] != 0x3f3f3f3f)
            ans += low[i];
    }
    print(ans);
    
    return 0;
}