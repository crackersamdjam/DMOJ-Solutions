#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef long long ll;
const int maxn = 1e5+1, maxm = 17, mod = 1e9+7;

int N, Q, K, curRoot = 1, val[maxn], dep[maxn], lca[maxm][maxn], sum[maxm][maxn];
ll prod[maxm][maxn];
int low[maxm][maxn], high[maxm][maxn], gcd[maxm][maxn];
int band[maxm][maxn], bor[maxm][maxn], bxor[maxm][maxn];
int morekcnt[maxm][maxn], lesskcnt[maxm][maxn];
int morek[maxm][maxn], lessk[maxm][maxn];

vector<int> adj[maxn];

void dfs(int cur, int pre){
    
    for(int &u: adj[cur]){
        
        if(u != pre){
            dep[u] = dep[cur] + 1;
            lca[0][u] = cur;
            prod[0][u] = sum[0][u] = low[0][u] = high[0][u] = gcd[0][u] = band[0][u] =
                bor[0][u] = bxor[0][u] = val[u];
            
            if(val[u] > K){
                morekcnt[0][u] = 1;
                morek[0][u] = val[u];
            }
            else{
                morek[0][u] = 1e5;
            }
            
            if(val[u] < K){
                lesskcnt[0][u] = 1;
                lessk[0][u] = val[u];
            }
            else{
                lessk[0][u] = -1;
            }
            
            dfs(u, cur);
        }
    }
}

//clang is gay
inline int getgcd(int a, int b){
    if(a == 0)
        return b;
    return getgcd(b % a, a);
}

inline void build(){
    
    //init 1
    prod[0][1] = sum[0][1] = low[0][1] = high[0][1] = gcd[0][1] = band[0][1] =
    bor[0][1] = bxor[0][1] = val[1];
    
    if(val[1] > K){
        morekcnt[0][1] = 1;
        morek[0][1] = val[1];
    }
    else{
        morek[0][1] = 1e5;
    }
    
    if(val[1] < K){
        lesskcnt[0][1] = 1;
        lessk[0][1] = val[1];
    }
    else{
        lessk[0][1] = -1;
    }
    
    
    for(int i = 1; i < maxm; i++){
        for(int j = 1; j <= N; j++){
            
            if(lca[i-1][j] != -1){
                lca[i][j] = lca[i-1][lca[i-1][j]];
                
                sum[i][j] = sum[i-1][j] + sum[i-1][lca[i-1][j]];
                
                prod[i][j] = (prod[i-1][j] * prod[i-1][lca[i-1][j]]) % mod;
                
                low[i][j] = min(low[i-1][j], low[i-1][lca[i-1][j]]);
    
                high[i][j] = max(high[i-1][j], high[i-1][lca[i-1][j]]);
    
                gcd[i][j] = getgcd(gcd[i-1][j], gcd[i-1][lca[i-1][j]]);
    
                band[i][j] = band[i-1][j] & band[i-1][lca[i-1][j]];
    
                bor[i][j] = bor[i-1][j] | bor[i-1][lca[i-1][j]];
    
                bxor[i][j] = bxor[i-1][j] ^ bxor[i-1][lca[i-1][j]];
    
                morekcnt[i][j] = morekcnt[i-1][j] + morekcnt[i-1][lca[i-1][j]];
    
                lesskcnt[i][j] = lesskcnt[i-1][j] + lesskcnt[i-1][lca[i-1][j]];
    
                morek[i][j] = min(morek[i-1][j], morek[i-1][lca[i-1][j]]);
                
                lessk[i][j] = max(lessk[i-1][j], lessk[i-1][lca[i-1][j]]);
            }
        }
    }
}

inline int getLca(int a, int b){
    if(dep[a] < dep[b])
        swap(a, b);
    for(int i = maxm-1; i >= 0; i--){
        if((lca[i][a] != -1) && (dep[lca[i][a]] >= dep[b]))
            a = lca[i][a];
    }
    if(a == b)
        return a;
    for(int i = maxm-1; i >= 0; i--){
        if((lca[i][a] != -1) && (lca[i][b] != -1) && (lca[i][a] != lca[i][b])){
            a = lca[i][a];
            b = lca[i][b];
        }
    }
    return lca[0][a];
}

ll ans;
int op;

inline void combine(int i, int n){
    switch(op){
        case 3:
            ans += sum[i][n];
            break;
        case 4:
            ans = (ans * prod[i][n])%mod;
            break;
        case 5:
            ans = min(ans, (ll)low[i][n]);
            break;
        case 6:
            ans = max(ans, (ll)high[i][n]);
            break;
        case 7:
            ans = getgcd(ans, gcd[i][n]);
            break;
        case 8:
            ans &= band[i][n];
            break;
        case 9:
            ans |= bor[i][n];
            break;
        case 10:
            ans ^= bxor[i][n];
            break;
        case 11:
            ans += morekcnt[i][n];
            break;
        case 12:
            ans += lesskcnt[i][n];
            break;
        case 13:
            ans = min(ans, (ll)morek[i][n]);
            break;
        case 14:
            ans = max(ans, (ll)lessk[i][n]);
            break;
    }
}

inline ll query(int a, int b){
    ans = 0;
    if(op == 4)
        ans = 1;
    else if(op == 5)
        ans = 1e5;
    else if(op == 6)
        ans = -1;
    else if(op == 8) //and
        ans = (1<<30)-1;
    else if(op == 13)
        ans = 1e5;
    else if(op == 14)
        ans = -1;
    
    //for 7, gcd(0, b) is b
    
    int rt = getLca(a, b);
    
    //combine root, because this uses nodes, not edges
    combine(0, rt);
    
    for(int i = maxm-1; i >= 0; i--){
        if(dep[a] >= dep[rt] + (1<<i)){
            
            combine(i, a);
            a = lca[i][a];
        }
    }
    
    for(int i = maxm-1; i >= 0; i--){
        if(dep[b] >= dep[rt] + (1<<i)){
            
            combine(i, b);
            b = lca[i][b];
        }
    }
    return ans;
}

int main(){
    
    memset(lca, -1, sizeof lca);
    
    scan(N, Q, K);
    for(int i = 1; i <= N; i++){
        scan(val[i]);
    }
    
    for(int i = 0,a,b; i < N-1; i++){
        scan(a, b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(1, -1);
    build();
    
    for(int i = 0,a,b; i < Q; i++){
        scan(op, a);
        
        //evan is gay
        if(op == 1){
            curRoot = a;
            continue;
        }
        if(op == 2){
            //useless
            scan(b);
            print(curRoot);
            continue;
        }
        
        scan(b);
        ll ans = query(a, b);
        
        if(op == 13 && ans == 1e5)
            ans = K;
        if(op == 14 && ans == -1)
            ans = K;
        
        print(ans);
    }
    
    return 0;
}