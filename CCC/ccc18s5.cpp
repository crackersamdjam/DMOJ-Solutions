#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x) {x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void print(T n) {register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);pc(10);}
template<typename First, typename ... Ints>
void scan(First &arg, Ints&... rest) { scan(arg);scan(rest...); }

using namespace std;
typedef long long ll;
const int MM = 1e5+1;

int N, M, P, Q, par[2][MM];
ll sum, ans, rem[2], cnt;

struct edge{
    int a, b, c, d;
};

inline int find(int x, int (&par)[MM]){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
    }
    return x;
}

vector<edge> edges;

int main(){
    
    for(int i = 1; i < MM; i++)
        par[0][i] = par[1][i] = i;
    
    scan(N, M, P, Q);
    rem[0] = M, rem[1] = N;
    cnt = (ll)N*M-1;
    
    for(int i = 0,a,b,c; i < P; i++){
        scan(a, b, c);
        edges.push_back({a, b, c, 0});
        sum += (ll)c*N;
    }
    
    for(int i = 0,a,b,c; i < Q; i++){
        scan(a, b, c);
        edges.push_back({a, b, c, 1});
        sum += (ll)c*M;
    }
    
    sort(edges.begin(), edges.end(), [](const edge &x, const edge &y){
        return x.c < y.c;
    });
    
    for(const edge &e: edges){
        int fa = find(e.a, par[e.d]), fb = find(e.b, par[e.d]);
        if(rem[e.d^1] && fa != fb){
            par[e.d][fa] = fb;
            ans += e.c*rem[e.d^1];
            cnt -= rem[e.d^1];
            rem[e.d]--;
            if(!cnt)
                break;
        }
    }
    
    print(sum - ans);
    
    return 0;
}