// stop copying problem statements >:(

#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 2002;

int n;
ll a[MM], b[MM], c[MM], d[MM], g[MM][MM];
ll rx[MM], ry[MM], ans;
map<int, int> mx, my;
int px, py;

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
        freopen("err.txt", "w", stderr);
    #endif
    
    scan(n);
    for(int i = 0; i < n; i++){
        scan(a[i], d[i], c[i], b[i]);
        mx[a[i]] = mx[c[i]] = my[b[i]] = my[d[i]] = 0;
    }
    
    for(auto &x: mx){
        x.second = ++px;
        rx[px] = x.first;
    }
    for(auto &x: my){
        x.second = ++py;
        ry[py] = x.first;
    }
    
    for(int i = 0; i < n; i++){
        a[i] = mx[a[i]], c[i] = mx[c[i]], b[i] = my[b[i]], d[i] = my[d[i]];
        g[a[i]][b[i]]++;
        g[a[i]][d[i]]--;
        g[c[i]][b[i]]--;
        g[c[i]][d[i]]++;
    }
    
    for(int i = 1; i <= px; i++){
        for(int j = 1; j <= py; j++){
            g[i][j] += g[i-1][j] + g[i][j-1] - g[i-1][j-1];
            if(g[i][j] > 0){
                //print(rx[i], ry[j], g[i][j]);
                ans += (rx[i+1]-rx[i])*(ry[j+1]-ry[j]);
            }
        }
    }
    
    print(ans);
    
    return 0;
}