#pragma GCC optimize "Ofast"
#pragma GCC optimize "unroll-loops"
#pragma GCC optimize "omit-frame-pointer"
#pragma GCC optimize "prefetch-loop-arrays"
#pragma GCC target "sse,sse2,sse3,sse4,abm,avx,aes,sse4a,sse4.1,sse4.2,mmx,popcnt,tune=native"
#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
typedef pair<int, int> pii;
const int MM = 1e6+1;

int n, m, t, dis[MM];
vector<vector<int>> grid;
pii last;
vector<pii> adj[MM];
priority_queue<pii, vector<pii>, greater<pii>> q;

int mx[] = {1, -1, 0, 0}, my[] = {0, 0, 1, -1};

void dfs(int x, int y){
    
    grid[x][y] = t+'0';
    
    for(int i = 0; i < 4; i++){
        int nx = x+mx[i], ny = y+my[i];
        if(nx >= 0 && ny >= 0 && nx <= n && ny < m && grid[nx][ny] == '#')
            dfs(nx, ny);
    }
}

int main(){
    
    scan(n, m);
    
    grid.resize(n+1);
    for(int i = 0; i <= n; i++)
        grid[i].resize(m);
    
    for(int i = n; i; i--){
        for(int j = 0; j < m; j++)
            grid[i][j] = gc;
        gc;
    }
    for(int i = 0; i < m; i++)
        grid[0][i] = '#';
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '#'){
                t++;
                dfs(i, j);
            }
        }
    }
    
    for(int i = 0; i < m; i++){
        last = {1, 0};
        for(int j = 1; j <= n; j++){
            if(grid[j][i] != '.'){
                if(grid[j][i]-'0' != last.first){
                    adj[last.first].push_back({grid[j][i]-'0', j-last.second-1});
                    last = {grid[j][i]-'0', j};
                }
                else
                    last.second = j;
            }
        }
    }
    
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    q.push({0, 1});
    while(!q.empty()){
        int c = q.top().second;
        if(q.top().first > dis[c]){
            q.pop();
            continue;
        }
        q.pop();
        
        for(auto e: adj[c]){
            if(dis[c] + e.second < dis[e.first]){
                dis[e.first] = dis[c] + e.second;
                q.push({dis[e.first], e.first});
            }
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < m; j++){
            int c = grid[i][j];
            if(c != '.'){
                grid[i][j] = '.';
                grid[i - dis[c-'0']][j] = '#';
            }
        }
    }
    
    for(int i = n; i; i--){
        for(int j = 0; j < m; j++)
            pc(grid[i][j]);
        pc(10);
    }
    
    return 0;
}