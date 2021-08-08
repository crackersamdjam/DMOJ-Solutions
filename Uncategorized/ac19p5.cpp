#pragma GCC optimize "O3"
#pragma GCC target "sse4"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define max(x, y) ((x) > (y) ? (x) : (y))

const int MM = 1501;

int n, a[MM][MM], dis[MM][MM], t, ans;
int mx[] = {1, -1, 0, 0}, my[] = {0, 0, 1, -1};

struct st{
    int x, y, v;
    bool operator <(const st &o) const{
        return v < o.v;
    }
} v[MM*MM];

int main(){
    
    scan(n);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scan(a[i][j]);
            v[t++] = {i, j, a[i][j]};
        }
    }
    
    std::sort(v, v+t);
    
    for(int i = 0; i < t; i++){
        st p = v[i];
        dis[p.x][p.y] = max(dis[p.x][p.y], 1);
        for(int k = 0; k < 4; k++){
            int nx = p.x + mx[k], ny = p.y + my[k];
            if(a[nx][ny] > a[p.x][p.y])
                dis[nx][ny] = max(dis[nx][ny], dis[p.x][p.y]+1);
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++)
            ans = max(ans, dis[i][j]);
    }
    
    print(ans-1);
    
    return 0;
}