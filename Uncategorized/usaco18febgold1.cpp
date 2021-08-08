#include <bits/stdc++.h>
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

void init(){
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    #endif
}

const int MM = 1e5+2;
int n, b, a[MM], par[MM], sz[MM];
vector<pair<int, int>> v;
map<int, int> req;

int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}
void merge(int i, int j){
    //i into j
    par[i = find(i)] = par[j = find(j)];
    sz[j] += sz[i];
}

int main(){
    init();
    scan(n, b);
    for(int i = 1; i <= n; i++){
        scan(a[i]);
        v.emplace_back(-a[i], i);
    }
    sort(v.begin(), v.end());
    int ans = 1;
    req[1e9+1] = 0;
    for(auto p: v){
        int i = p.second;
        par[i] = i, sz[i] = 1;
        if(sz[i-1]){
            merge(i-1, i);
            ans = max(ans, sz[i]);
        }
        if(sz[i+1]){
            merge(i+1, i);
            ans = max(ans, sz[i]);
        }
        req[-p.first] = ans;
        //print(-p.first, ans);
    }

    //if not able to visit numbers greater than first, second is ans
    for(int i = 0,dep,len; i < b; i++){
        scan(dep, len);
        int v = req.upper_bound(dep)->second;
        print(v < len);
    }

    return 0;
}