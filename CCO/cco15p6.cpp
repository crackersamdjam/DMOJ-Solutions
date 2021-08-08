#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2505, MN = 1e5+5;

int n, k, m, q, a[MM][MM], bit[MN];
set<int> in[MM];

void up(int i, int v){
    for(i = MN-i-1; i < MN; i += i&-i)
        bit[i] += v;
}

int qu(int i){
    int r = 0;
    for(i = MN-i-1; i > 0; i -= i&-i)
        r += bit[i];
    return r;
}

int main(){
    
    scan(n, k, m);
    
    for(int z = 0,s; z < m; z++){
        scan(s);
        vector<pair<int, int>> v(s);
        for(int i = 0; i < s; i++)
            scan(v[i].first, v[i].second);
        for(int i = 1; i < (1<<s); i++){
            int lx = 1, rx = n, ly = 1, ry = n;
            for(int j = 0; j < s; j++)
                if(i&(1<<j)){
                    lx = max(lx, v[j].first-k+1), rx = min(rx, v[j].first);
                    ly = max(ly, v[j].second-k+1), ry = min(ry, v[j].second);
                }
            if(lx > rx || ly > ry) continue;
            int d = (__builtin_popcount(i)&1) ? 1 : -1;
            rx++, ry++;
            a[lx][ly] += d;
            a[lx][ry] -= d;
            a[rx][ly] -= d;
            a[rx][ry] += d;
        }
    }
    
    n -= k-1;
    long double d = n*n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            up(a[i][j], 1);
            in[i].insert(j);
        }
    }
    
    scan(q);
    for(int z = 0,op,x,y,v; z < q; z++){
        scan(op);
        if(op == 1){
            scan(x, y);
            for(int i = x; i > max(x-k, 0); i--){
                for(auto it = in[i].upper_bound(y-k); it != in[i].end() && *it <= y; it = in[i].erase(it))
                    up(a[i][*it], -1);
            }
        }
        else{
            scan(v);
            if(v > m)
                puts("0.000000");
            else
                printf("%.6Lf\n", qu(v)/d);
        }
    }
    
    return 0;
}