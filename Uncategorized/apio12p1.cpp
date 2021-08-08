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
const int MM = 1e5+1;

int n, m, b[MM];
ll c[MM], l[MM], ans;
priority_queue<ll> s[MM];
vector<int> ch[MM];

void go(int u){
    
    int mx = 0, id = 0;
    
    for(int v: ch[u]){
        if(s[v].size() > mx){
            mx = s[v].size();
            id = v;
        }
    }
    if(id)
        swap(s[id], s[u]);
    
    s[u].push(c[u]);
    
    for(int v: ch[u]){
        c[u] += c[v];
        while(!s[v].empty()){
            s[u].push(s[v].top());
            s[v].pop();
        }
    }
    
    while(c[u] > m){
        c[u] -= s[u].top();
        s[u].pop();
    }
    
    ans = max(ans, (ll)s[u].size()*l[u]);
}

int main(){
    
    scan(n, m);
    
    for(int i = 1; i <= n; i++){
        scan(b[i], c[i], l[i]);
        ch[b[i]].push_back(i);
    }
    
    for(int i = n; i; i--)
        go(i);
    
    print(ans);
    
    return 0;
}