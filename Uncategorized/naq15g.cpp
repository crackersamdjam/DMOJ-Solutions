#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef pair<int, pair<int, int>> pii;

int n, dis[2][1<<15], a[15];
priority_queue<pii, vector<pii>, greater<pii>> q;

int main(){
    
    scan(n);
    
    for(int i = 0; i < n; i++)
        scan(a[i]);
    
    memset(dis, 0x3f, sizeof dis);
    
    dis[0][0] = 0;
    
    q.push({0, {0, 0}});
    
    while(!q.empty()){
        auto p = q.top(); q.pop();
        int d = p.first, l = p.second.first, m = p.second.second;
        if(d > dis[l][m])
            continue;
        
        for(int i = 0; i < n; i++){
            if(((m>>i)&1) == l){
                int nx = m^(1<<i);
                if(dis[l][m] + a[i] < dis[l^1][nx]){
                    dis[l^1][nx] = dis[l][m] + a[i];
                    q.push({dis[l^1][nx], {l^1, nx}});
                }
                
                for(int j = i+1; j < n; j++){
                    if(((m>>j)&1) == l){
                        nx = m^(1<<i)^(1<<j);
                        if(dis[l][m] + max(a[i], a[j]) < dis[l^1][nx]){
                            dis[l^1][nx] = dis[l][m] + max(a[i], a[j]);
                            q.push({dis[l^1][nx], {l^1, nx}});
                        }
                    }
                }
            }
        }
    }
    
    print(dis[1][(1<<n)-1]);
    
    return 0;
}