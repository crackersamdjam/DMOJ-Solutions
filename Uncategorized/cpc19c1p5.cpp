#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}

using namespace std;
typedef long long ll;
const int MM = 1e4+1;

int N, M, K, Q;
unordered_map<ll, pair<int, int>> dis;
queue<pair<ll, int>> q;

inline int value(ll mask, int i){
    return ((mask>>(i*4))&15);
}
/*
inline void peek(ll mask){
    for(int i = N*M-1; i >= 0; i--)
        printf("%d ", value(mask, i));
    pc(10);
}
*/
int main(){
    
    scan(N, M, K, Q);
    
    for(int k = 1; k <= K; k++){
        
        ll in = 0;
        
        for(int i = 0; i < N; i++){
            for(int j = 0,n; j < M; j++){
                scan(n);
                in = (in<<4) | n;
            }
        }
        
        if(dis[in].first != 1){
            dis[in] = {1, k};
            q.push({in, k});
        }
    }
    
    if(M == 4){
        ll pos = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0,n; j < M; j++){
                scan(n);
                pos = (pos<<4) | n;
            }
        }
        
        dis[pos] = {1, -1};
        q.push({pos, -1});
    }
    
    int delay = 1e9, pt, ans = 3;
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        if(delay < dis[cur.first].first){
            print(ans);
            pc(32);
            print(pt);
            pc(10);
            return 0;
        }
        
        int bl = -1;
        
        for(int i = 0; i < N*M; i++){
            if(value(cur.first, i) == 0){
                bl = i;
                break;
            }
        }
        
        for(int i = 0; i < M*N; i++){
            
            if((bl^i) and ((bl/M == i/M and abs(bl-i) == 1) or abs(bl-i) == M)){
                
                ll v = value(cur.first, i);
                
                ll nx = cur.first | (v<<(4*bl));
                nx ^= v<<(4*i);
                
                if(M == 4){
                    if(((dis[nx].second == -1) xor (cur.second == -1)) and dis[nx].second and cur.second){
                        if(ans == 3 or pt == dis[nx].first + dis[cur.first].first - 1){
                            ans = min(ans, max(dis[nx].second, cur.second));
                            pt = dis[nx].first + dis[cur.first].first - 1;
                            delay = dis[nx].first;
                        }
                    }
                }
                
                if(dis[cur.first].first + 1 < dis[nx].first or !dis[nx].first){
                    dis[nx] = {dis[cur.first].first + 1, cur.second};
                    q.push({nx, cur.second});
                }
                else if(dis[cur.first].first + 1 == dis[nx].first and dis[nx].second - cur.second == 1){
                    dis[nx].second = 1;
                    abort();
                }
            }
        }
    }
    
    for(int t = 0; t < Q; t++){
        
        ll pos = 0;
        
        for(int i = 0; i < N; i++){
            for(int j = 0,n; j < M; j++){
                scan(n);
                pos = (pos<<4) | n;
            }
        }
        
        print(dis[pos].second);
        pc(32);
        print(dis[pos].first-1);
        pc(10);
    }
    
    return 0;
}