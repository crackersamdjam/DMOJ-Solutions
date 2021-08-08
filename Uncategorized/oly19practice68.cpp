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
using pi = pair<int, int>;
using pii = pair<ll, int>;
const int MM = 1e5+1;

int n, m, k;
vector<pi> s;
ll dis[11][MM], ans = 1e15;
vector<pi> adj[MM];
queue<int> q;
bool inq[MM];

void run(int id, int sc){
    dis[id][sc] = 0;
    q.push(sc);
    while(!q.empty()){
        int cur = q.front(); q.pop(); inq[cur] = 0;
        for(auto u: adj[cur]){
            if(dis[id][cur] + u.second < dis[id][u.first]){
                dis[id][u.first] = dis[id][cur] + u.second;
                if(!inq[u.first]){
                    inq[u.first] = 1;
                    q.push(u.first);
                }
            }
        }
    }
}

int main(){
    
    memset(dis, 0x3f, sizeof dis);
    
    scan(n, m);
    
    for(int i = 0,a,b,c; i < m; i++){
        scan(a, b, c);
        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }
    
    scan(k);
    for(int i = 1,a; i <= k; i++){
        scan(a);
        s.push_back({a, i});
        run(i, a);
    }
    run(0, 0);
    
    sort(s.begin(), s.end());
    do{
        ll d = dis[0][s[0].first] + dis[s.back().second][0];
        for(int i = 0; i < s.size()-1; i++){
            d += dis[s[i].second][s[i+1].first];
        }
        ans = min(ans, d);
        
        //for(auto i: s)
          //  printf("%d ", i.first);
        //printf("\nd: %lld\n", d);
        
    } while(next_permutation(s.begin(), s.end()));
    
    print(ans);
    
    return 0;
}