#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
const int MM = 100002;

int N, M, K, A, B, dis[MM], disr[MM];
queue<int> q;
vector<int> vec, adj[MM];
int main(){

    scan(N, M, K, A, B);
    for(int i = 0,k; i < K; i++){
        scan(k);
        vec.push_back(k);
    }
    for(int i = 0,a,b; i < M; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dis, 0x3f, sizeof(dis));
    memset(disr, 0x3f, sizeof(disr));
    dis[A] = disr[B] = 0;
    q.push(A);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int &u: adj[cur]){
            if(dis[cur] + 1 < dis[u]){
                dis[u] = dis[cur] + 1;
                q.push(u);
            }
        }
    }
    q.push(B);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for(int &u: adj[cur]){
            if(disr[cur] + 1 < disr[u]){
                disr[u] = disr[cur] + 1;
                q.push(u);
            }
        }
    }
    int ans = 1e9;
    for(int &k: vec){
        ans = min(ans, dis[k] + disr[k]);
    }
    print(ans);
    return 0;
}