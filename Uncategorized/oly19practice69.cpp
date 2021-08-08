#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e5+2;

int n, a[MM], b[MM];
set<int> st;
vector<int> low, high;

int main(){
    
    scan(n);
    
    for(int i = 1; i <= n; i++)
        scan(b[i]);
    
    for(int i = 1; i < 2*n; i++)
        st.insert(i);
    
    a[1] = b[1];
    st.erase(b[1]);
    
    for(int i = 2; i <= n; i++){
        if(b[i] > b[i-1]){
            a[i*2-2] = *prev(st.end());
            st.erase(prev(st.end()));
            if(st.count(b[i])){
                a[i*2-1] = b[i];
                st.erase(b[i]);
            }
            else{
                a[i*2-1] = *prev(st.end());
                st.erase(prev(st.end()));
            }
        }
        else if(b[i] < b[i-1]){
            a[i*2-2] = *st.begin();
            st.erase(st.begin());
            if(st.count(b[i])){
                a[i*2-1] = b[i];
                st.erase(b[i]);
            }
            else{
                a[i*2-1] = *st.begin();
                st.erase(st.begin());
            }
        }
        else{
            a[i*2-2] = *prev(st.end());
            st.erase(prev(st.end()));
            a[i*2-1] = *st.begin();
            st.erase(st.begin());
        }
    }
    
    for(int i = 1; i < 2*n; i++)
        printf("%d ", a[i]);
    
    return 0;
}