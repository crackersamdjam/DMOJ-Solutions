#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2005;

int mx[] = {1, -1, 0, 0, 1, -1, 1, -1}, my[] = {0, 0, 1, -1, 1, -1, -1, 1};
int n, ans, cnt;
string s[MM];
bool vis[MM][MM], no;
int minx, maxx, miny, maxy;

void dfs(int i, int j){
    if(min(i, j) == 0 || i == n || j == n+n){
        no = 1;
        return;
    }
    cnt++;
    vis[i][j] = 1;
    minx = min(minx, i);
    miny = min(miny, j);
    maxx = max(maxx, i);
    maxy = max(maxy, j);
    for(int k = 0; k < 8; k++){
        int nx = i+mx[k], ny = j+my[k];
        if(s[nx][ny] == '#' && !vis[nx][ny]){
            dfs(nx, ny);
        }
    }
}

void go(int x, int y){
    minx = miny = 1e9;
    maxx = maxy = cnt = 0;
    no = 0;
    dfs(x, y);
    if(no) return;
    
    int h = maxx-minx+1+2, w = maxy-miny+1+2;
    int m = (w-5)/2;
    
    if(m < 1 || (m*2+5 != w) || ((4 + m/5 + (2*m+2)/3) != h))
        return;
    
    h-=2, w-=2;
    int num = m/5 + 1 + (h-1-m/5)*w;
    if(cnt != num)
        return;
    
    for(int i = minx+1+m/5; i <= maxx; i++){
        for(int j = miny; j <= maxy; j++){
            if(s[i][j] != '#')
                return;
        }
    }
    
    int mid = (miny+maxy)/2;
    for(int i = minx; i <= maxx; i++){
        if(s[i][mid] != '#')
            return;
    }
    
    ans++;
}

int main(){
    
    cin >> n;
    
    for(int i = 0; i < n; i++)
        cin >> s[i];
    
    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < n+n-1; j++){
            if(s[i][j] == '#' && ! vis[i][j])
                go(i, j);
        }
    }
    
    print(ans);
    
    return 0;
}