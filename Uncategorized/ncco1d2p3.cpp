#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e6+1;

int n, a[MM], best[MM], mx;
long long ans;
stack<int> st;

int main(){
    
    scan(n);
    
    for(int i = 0; i < n; i++){
        scan(a[i]);
        best[i] = 2e9;
        
        while(!st.empty() && st.top() < a[i])
            st.pop();
        if(!st.empty())
            best[i] = st.top();
        st.push(a[i]);
    }
    
    while(!st.empty())
        st.pop();
    
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && st.top() <= a[i])
            st.pop();
        if(!st.empty())
            best[i] = min(best[i], st.top());
        st.push(a[i]);
    }
    
    for(int i = 0; i < n; i++){
        ans += best[i];
        mx = max(mx, best[i]);
    }
    
    ans -= mx;
    
    print(ans);
    
    return 0;
}