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

int n, m, low[MM], pre[MM], dis[MM], a[MM];
int ans[MM], t;

int main(){
    
    scan(n, m);
    
    scan(a[1]);
    low[a[1]] = 1;
    m++;
    
    for(int i = 2; i <= m; i++){
        scan(a[i]);
        if(i < m)
            scan(a[i]);
        dis[i] = dis[i-1]+1;
        pre[i] = i-1;
        
        if(low[a[i]]){
            int v = dis[low[a[i]]];
            if(v < dis[i]){
                dis[i] = v;
                pre[i] = pre[low[a[i]]];
            }
        }
        
        if(!low[a[i]] || dis[i] < dis[low[a[i]]])
            low[a[i]] = i;
    }
    
    print(dis[m]);
    
    while(m){
        ans[t++] = a[m];
        m = pre[m];
    }
    
    while(t-- > 1)
        print(ans[t], ans[t-1]);
    
    return 0;
}