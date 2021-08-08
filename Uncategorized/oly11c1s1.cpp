#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;

int N, M, id[51][51], t, dis[51][51][4];
int mx[] = {1, -1, 0, 0}, my[] = {0, 0, 1, -1};
string adj[51];
bool vis[51][51];

void dfs(int x, int y){
    
    for(int k = 0; k < 4; k++){
        int nx = x + mx[k], ny = y + my[k];
        
        if(nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;
        
        if(!vis[nx][ny] && adj[nx][ny] != '.'){
            vis[nx][ny] = 1;
            id[nx][ny] = id[x][y];
            dfs(nx, ny);
        }
    }
}

int main(){
    
    memset(dis, 0x3f, sizeof dis);
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        cin >> adj[i];
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!vis[i][j] && adj[i][j] != '.'){
                vis[i][j] = 1;
                id[i][j] = ++t;
                dfs(i, j);
            }
        }
    }
    
    queue<pair<int, int>> q;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(id[i][j] == 1){
                dis[i][j][1] = 0;
                q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        for(int k = 0; k < 4; k++){
            int nx = cur.first + mx[k], ny = cur.second + my[k];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            
            if(dis[nx][ny][1] > dis[cur.first][cur.second][1] + 1){
                dis[nx][ny][1] = dis[cur.first][cur.second][1] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    //2
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(id[i][j] == 2){
                dis[i][j][2] = 0;
                q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        for(int k = 0; k < 4; k++){
            int nx = cur.first + mx[k], ny = cur.second + my[k];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            
            if(dis[nx][ny][2] > dis[cur.first][cur.second][2] + 1){
                dis[nx][ny][2] = dis[cur.first][cur.second][2] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    //3
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(id[i][j] == 3){
                dis[i][j][3] = 0;
                q.push({i, j});
            }
        }
    }
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        for(int k = 0; k < 4; k++){
            int nx = cur.first + mx[k], ny = cur.second + my[k];
            
            if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            
            if(dis[nx][ny][3] > dis[cur.first][cur.second][3] + 1){
                dis[nx][ny][3] = dis[cur.first][cur.second][3] + 1;
                q.push({nx, ny});
            }
        }
    }
    
    int ans = INT_MAX;
    bool done = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            
            int t4 = dis[i][j][1] + dis[i][j][2] + dis[i][j][3];
            ans = min(ans, t4-2);
            
            for(int ii = 0; ii < N; ii++){
                for(int jj = 0; jj < M; jj++){
                    if(i == ii && j == jj)
                        continue;
                    
                    int t1 = dis[i][j][1] + dis[i][j][2] + dis[ii][jj][1] + dis[ii][jj][3];
                    int t2 = dis[i][j][2] + dis[i][j][1] + dis[ii][jj][2] + dis[ii][jj][3];
                    int t3 = dis[i][j][3] + dis[i][j][1] + dis[ii][jj][3] + dis[ii][jj][2];
                    ans = min(ans, min(t1, min(t2, t3)) - 2);
                    /*
                    if(ans == 6 and !done){
                        done = 1;
                        print(i, j, ii, jj);
                        print(t1, t2, t3);
                    }
                     */
                }
            }
            
        }
    }
    
    print(ans);
    
    assert(ans != 0x3f3f3f3f);
    assert(t == 3);
    /*
    puts("1");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(dis[i][j][1] == 0x3f3f3f3f){
                cout << "- ";
                continue;
            }
            cout << dis[i][j][1] << ' ';
        }
        pc(10);
    }
    
    puts("2");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(dis[i][j][2] == 0x3f3f3f3f){
                cout << "- ";
                continue;
            }
            cout << dis[i][j][2] << ' ';
        }
        pc(10);
    }
    
    puts("3");
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(dis[i][j][3] == 0x3f3f3f3f){
                cout << "- ";
                continue;
            }
            cout << dis[i][j][3] << ' ';
        }
        pc(10);
    }
    */
    
    return 0;
}
/*
2 3
X.X
.X.

 */