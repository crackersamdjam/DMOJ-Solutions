#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

#define x first
#define y second

using namespace std;
typedef pair<int, int> pii;

char gd[12][12];
int dis[12][12], mx[] = {1, -1, 0, 0, 1, 1, -1, -1}, my[] = {0, 0, 1, -1, 1, -1, 1, -1};

int main(){
    for(int i = 0; i < 12; i++)
        gd[i][0] = gd[0][i] = gd[11][i] = gd[i][11] = '#';
    int tc = 5;
    while(tc--){
        
        vector<pii> a;
        
        for(int i = 1; i <= 10; i++){
            for(int j = 1; j <= 10; j++){
                if((gd[i][j] = gc) == 'X')
                    a.push_back({i, j});
            }
            gc;
        }
        
        pii st = a[0], ed = a[1];
        queue<pii> q;
        memset(dis, 0, sizeof dis);
        dis[st.x][st.y] = 1;
        q.push(st);
        while(!q.empty()){
            pii u = q.front(); q.pop();
            if(gd[u.x][u.y] == '#')
                continue;
            if(u == ed){
                print(dis[u.x][u.y]-1);
                break;
            }
            for(int i = 0; i < 8; i++){
                pii nx = {u.x + mx[i], u.y + my[i]};
                if(!dis[nx.x][nx.y]){
                    dis[nx.x][nx.y] = dis[u.x][u.y] + 1;
                    q.push(nx);
                }
            }
        }
        for(int i = 0; i < 11; i++)
            gc;
    }
    
    return 0;
}