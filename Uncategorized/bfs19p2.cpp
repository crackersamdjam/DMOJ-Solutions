#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef long long ll;
typedef pair<int, ll> pii;
const int MM = 1001;

#define f first
#define s second

int n;
char a[MM][MM];
int dis[MM][MM];
ll cnt[MM][MM];
//count lefts
queue<pii> q;

ll sq(ll x){
    return x*x;
}

int main(){
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++){
        scanf("%s", a[i]+1);
    }
    
    memset(dis, 0x3f, sizeof dis);
    dis[1][1] = 0;
    cnt[1][1] = 0;
    q.push({1, 1});
    
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        if(cur.f < n && a[cur.f+1][cur.s] == '.' && dis[cur.f][cur.s]+1 < dis[cur.f+1][cur.s]){
            dis[cur.f+1][cur.s] = dis[cur.f][cur.s]+1;
            cnt[cur.f+1][cur.s] = cnt[cur.f][cur.s];
            q.push({cur.f+1, cur.s});
        }
        if(cur.s < n && a[cur.f][cur.s+1] == '.' && dis[cur.f][cur.s]+1 < dis[cur.f][cur.s+1]){
            dis[cur.f][cur.s+1] = dis[cur.f][cur.s]+1;
            cnt[cur.f][cur.s+1] = cnt[cur.f][cur.s];
            q.push({cur.f, cur.s+1});
        }
        if(cur.s > 1 && a[cur.f][cur.s-1] == '.' && dis[cur.f][cur.s]+1 < dis[cur.f][cur.s-1]){
            dis[cur.f][cur.s-1] = dis[cur.f][cur.s]+1;
            cnt[cur.f][cur.s-1] = cnt[cur.f][cur.s]+1;
            q.push({cur.f, cur.s-1});
        }
    }
    
    if(dis[n][n] == 0x3f3f3f3f)
        puts("-1");
    else
        print(sq(n-1) + sq(n-1 + cnt[n][n]) + sq(cnt[n][n]));
    
    /*
    for(int i = 1; i <= n; i++){
        for(int j=  1; j <= n; j++){
            printf("%d ", dis[i][j]);
        }
        pc(10);
    }
     */
    
    return 0;
}