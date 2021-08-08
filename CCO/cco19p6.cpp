#include <bits/stdc++.h>
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;register bool _=0;register T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){register bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 52;

struct st{
    int i, j, d;
    st(int a1, int a2, int a3 = 0): i(a1), j(a2), d(a3){}
    st(int a1, unsigned long a2, unsigned long a3 = 0): i(a1), j(a2), d(a3){}
};

int n, m, ans = 0x3f3f3f3f;
vector<st> adj[MM][MM];
string s[MM];
queue<st> q;
bool inq[MM][MM];
int dis[MM][MM];

int main(){
    
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        cin >> s[i];
    
    for(int a = 0; a < n; a++){
        for(int b = 0; b < n; b++){
            for(int i = (a==b); i < s[a].size(); i++){
                string tp = s[a].substr(i);
                if(tp.find(s[b]) == 0)
                    adj[a][i].push_back({a, i+s[b].size(), s[b].size()});
                if(s[b].find(tp) == 0)
                    adj[a][i].push_back({b, tp.size(), tp.size()});
            }
        }
    }
    
    memset(dis, 0x3f, sizeof dis);
    
    for(int i = 0; i < n; i++){
        q.push({i, 0});
        dis[i][0] = 0;
        inq[i][0] = 1;
    }
    
    while(!q.empty()){
        auto u = q.front(); q.pop();
        inq[u.i][u.j] = 0;
        if(u.j == s[u.i].size())
            ans = min(ans, dis[u.i][u.j]);
        
        for(auto v: adj[u.i][u.j]){
            int d = dis[u.i][u.j] + v.d;
            if(d < dis[v.i][v.j]){
                dis[v.i][v.j] = d;
                if(!inq[v.i][v.j]){
                    inq[v.i][v.j] = 1;
                    q.push({v.i, v.j});
                }
            }
        }
    }
    
    if(ans == 0x3f3f3f3f)
        puts("-1");
    else
        print(ans);
    
    return 0;
}