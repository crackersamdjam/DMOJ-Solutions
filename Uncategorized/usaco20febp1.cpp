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

int dp[MM], n, k, pos, rt;
vector<int> adj[MM];

void dfs(int cur, int pre){
    multiset<int> st;
    for(int u: adj[cur]){
        if(u == pre)
            continue;
        dfs(u, cur);
        if(!pos)
            return;
        st.insert(dp[u]);
    }
    int last = 0; //edge case, last < k
    while(st.size()){
        int f = *st.begin();
        if(f < k)
            last = f;
        if(f >= k)
            break;
        st.erase(st.lower_bound(f));
        auto s = st.lower_bound(k-f);
        if(s == st.end()){
            if(dp[cur]){
                //can not match or go up
                pos = 0;
                return;
            }
            dp[cur] = f+1;
            //going up this left
        }
        else{
            int vs = *s;
            st.erase(st.lower_bound(vs));
        }
    }
    if(!dp[cur]){
        st.insert(0);
        dp[cur] = (*(--st.end())) + 1;
        dp[cur] = max(dp[cur], last+1); //last one < k goes up instead of pairing with one >= k
    }
}

bool go(){
    memset(dp, 0, sizeof dp);
    pos = 1;
    dfs(rt, 0);
    if(dp[rt] > 1 && dp[rt] <= k) // <= because one extra added when up
        pos = 0;
    return pos;
}

int main(){
//    freopen("deleg.in", "r", stdin); freopen("deleg.out", "w", stdout);
    scan(n);
    for(int i = 0,a,b; i < n-1; i++){
        scan(a, b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }
    for(int i = 1; i <= n; i++)
        if(adj[i].size() == 1)
            rt = i;
    
    int l = 1, r = n-1;
    while(l <= r){
        k = (l+r)/2;
        if(go())
            l = k+1;
        else
            r = k-1;
    }
    print(r);
    
    return 0;
}
/*
6
1 2
1 3
1 4
1 5
1 6

7
1 2
1 3
1 4
1 5
1 6
1 7
 */