#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) {scan(arg);scan(rest...);}

using namespace std;
const int MM = 1e6+1;

int N, K, a[MM];
bool b[MM];
stack<int> st;

int main(){
    
    scan(N, K);
    
    for(int i = 0,k; i < K; i++){
        scan(k);
        b[k] = 1;
    }
    
    for(int i = 1,k; i <= K+1; i++){
        scan(k);
        a[k] = i;
    }
    
    for(int i = 1; i < MM; i++){
        if(a[i])
            st.push(a[i]);
        if(b[i] && !st.empty()){
            st.pop();
            b[i] = 0;
        }
    }
    
    for(int i = 1; i < MM; i++){
        if(b[i]){
            st.pop();
            b[i] = 0;
        }
    }
    
    print(st.top());
    
    return 0;
}