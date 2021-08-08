#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 17;

map<int, map<int, int>> dis[MM][MM];
struct c{
    int x, y, vx, vy;
    int &dist(){
        return dis[x][y][vx][vy];
    }
};
struct{
    int a, b;
} mv[9];

int main(){
    
    for(int i = -1, t = 0; i <= 1; i++)
        for(int j = -1; j <= 1; j++)
            mv[t++] = {i, j};
    
    int T;
    scan(T);
    while(T--){
        
        queue<c> q;
        
        for(int i = 0; i < MM; i++){
            for(int j = 0; j < MM; j++){
                for(int k = -5; k <= 5; k++){
                    for(int l = -5; l <= 5; l++)
                        dis[i][j][k][l] = 0x3f3f3f3f;
                }
            }
        }
        bool no[MM][MM];
        memset(no, 0, sizeof no);
        int n, m, p;
        
        scan(n, m);
        
        c st, ed;
        scan(st.x, st.y, ed.x, ed.y);
        
        scan(p);
        for(int t = 0,qq,w,e,r; t < p; t++){
            scan(qq,w,e,r);
            for(int i = qq; i <= w; i++){
                for(int j = e; j <= r; j++)
                    no[i][j] = 1;
            }
        }
        
        dis[st.x][st.y][0][0] = 0;
        q.push({st.x, st.y, 0, 0});
        
        while(!q.empty()){
            c cur = q.front(), nx; q.pop();
            
            if(cur.x == ed.x and cur.y == ed.y and cur.vx <= (n-ed.x+2) and cur.vy <= (m-ed.y+2)){
                printf("Optimal solution takes %d hops.\n", cur.dist());
                goto out;
            }
            
            for(int k = 0; k < 9; k++){
                nx = {cur.x, cur.y, cur.vx + mv[k].a, cur.vy + mv[k].b};
                nx.x += nx.vx, nx.y += nx.vy;
                if(nx.x >= 0 and nx.x < n and nx.y >= 0 and nx.y < m and !no[nx.x][nx.y]){
                    if(cur.dist() + 1 < nx.dist()){
                        nx.dist() = cur.dist() + 1;
                        q.push(nx);
                    }
                }
            }
        }
        puts("No solution.");
        out:;
    }
    
    return 0;
}