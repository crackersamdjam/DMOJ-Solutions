#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define f first
#define s second
#define _CRT_SECURE_NO_WARNINGS
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MM = 20002, MN = 202, inf = 0x3f3f3f3f;

int N, M, K, Q, dis[MN][MM], disr[MN][MM];
vector<pii> adj[MM], adjr[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;


inline void sp(int n, int rt){
    
    dis[n][rt] = 0;
    q.push({0, rt});
    
    while(!q.empty()){
        int cur = q.top().s; q.pop();
        for(pii &e: adj[cur]){
            if(dis[n][cur] + e.s < dis[n][e.f]){
                dis[n][e.f] = dis[n][cur] + e.s;
                q.push({dis[n][e.f], e.f});
            }
        }
    }
    
    disr[n][rt] = 0;
    q.push({0, rt});
    
    while(!q.empty()){
        int cur = q.top().s; q.pop();
        for(pii &e: adjr[cur]){
            if(disr[n][cur] + e.s < disr[n][e.f]){
                disr[n][e.f] = disr[n][cur] + e.s;
                q.push({disr[n][e.f], e.f});
            }
        }
    }
}
int main(){
    
    memset(dis, 0x3f, sizeof(dis));
    memset(disr, 0x3f, sizeof(disr));
    
    scan(N, M, K, Q);
    
    for(int i = 0,a,b,c; i < M; i++){
        scan(a, b, c);
        adj[a].push_back({b, c});
        adjr[b].push_back({a, c});
    }
    for(int i = 0,k; i < K; i++){
        scan(k);
        sp(i, k);
    }
    int cnt = 0;
    ll sum = 0;
    for(int i = 0,a,b; i < Q; i++){
        scan(a, b);
        int ans = inf;
        for(int k = 0; k < K; k++){
            ans = min(ans, disr[k][a] + dis[k][b]);
        }
        if(ans != inf){
            sum += ans;
            cnt++;
        }
    }
    print(cnt);
    print(sum);
    return 0;
}