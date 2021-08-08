#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 1e5+2;

int n, k, no;
vector<int> adj[MM];

int dfs(int cur, int pre){
    multiset<int> st;
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        int v = dfs(u, cur)+1;
        if(v != k)
            st.insert(v);
    }
    int up = 0;
    while(st.size()){
        int rm = *st.begin();
        st.erase(st.find(rm));
        if(st.find(k-rm) != st.end()){
            st.erase(st.find(k-rm));
        }
        else{
            if(up){
                no = 1;
                return 0;
            }
            up = rm;
        }
    }
    return up;
}

int go(){
    if((n-1)%k)
        return 0;
    no = 0;
    int r = dfs(1, 0);
    return !r and !no;
}

int main(){
    scan(n);
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for(int i = 1; i < n; i++){
        k = i;
        pc('0' + go());
    }
    
    return 0;
}