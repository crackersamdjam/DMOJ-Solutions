#include <bits/stdc++.h>
#define MM 100002
#define f first
#define s second
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
typedef pair<ll,int> pii;
struct st{
    ll c;
    int b,m;
    st(int bb, ll cc, int mm){
        b = bb;
        c = cc;
        m = mm;
    }
};
vector<st> adj[MM];
int N,M,A,B;
bool inq[MM];
ll dis[MM], C;
inline bool pos(int m){
    memset(dis,0x7f,sizeof(dis));
    dis[A] = 0;
    //priority_queue<pii,vector<pii>,greater<pii>> q;
    queue<pii> q;
    q.push({0,A});
    inq[A] = 1;
    while(!q.empty()){
        int cur = q.front().s; q.pop();
        inq[cur] = 0;
        for(st &e: adj[cur]){
            if(e.m <= m){
                if(dis[cur] + e.c < dis[e.b] && dis[cur] + e.c <= C){
                    dis[e.b] = e.c + dis[cur];
                    if(!inq[e.b]){
                        inq[e.b] = 1;
                        q.push({dis[e.b], e.b});
                    }
                }
            }
        }
    }
    return (dis[B] <= C);
}
int main(){
    sc(N); sc(M);
    ll c;
    for(int i = 1,a,b; i <= M; i++){
        sc(a); sc(b); sc(c);
        adj[a].push_back(st(b,c,i));
        adj[b].push_back(st(a,c,i));
    }
    sc(A); sc(B); sc(C);
    int l = 1,m, r = M, ans = INT_MAX;
    while(l <= r){
        m = (l+r)/2;
        if(pos(m)){
            r = m-1;
            ans = min(ans, m);
        }else
            l = m+1;
    }
    printf("%d\n", (ans == INT_MAX ? -1: ans));
    return 0;
}