#include <bits/stdc++.h>
#define MM 100002
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
vector<pii> adj[MM];
pair<pii,int> channel[MM*2];
priority_queue<pii, vector<pii>, greater<pii>> q;
int dis1[MM],dis2[MM],N,M,X,Y,A,B,C,Q,F,L,cur,a,b,c;
bool inq[MM];
int main(){
    scanf("%d%d%d%d",&N,&M,&X,&Y);
    for(int i = 1; i <= M; i++){
        scanf("%d%d%d",&A,&B,&C);
        adj[A].push_back({B,C});
        adj[B].push_back({A,C});
        channel[i] = {{A,B},C};
    }
    memset(dis1, 0x3f, sizeof(dis1));
    q.push({0,X}); dis1[X] = 0; inq[X] = 1;
    while(!q.empty()){
        cur = q.top().s; q.pop(); inq[cur] = 0;
        for(const pii &e : adj[cur]){
            if(dis1[cur] + e.s < dis1[e.f]){
                dis1[e.f] = dis1[cur] + e.s;
                if(!inq[e.f]){
                    q.push({dis1[e.f], e.f});
                    inq[e.f] = 1;
                }
            }
        }
    }
    memset(inq, 0, sizeof(inq));
    memset(dis2, 0x3f, sizeof(dis2));
    q.push({0,Y}); dis2[Y] = 0; inq[Y] = 1;
    while(!q.empty()){
        cur = q.top().s; q.pop(); inq[cur] = 0;
        for(const pii &e : adj[cur]){
            if(dis2[cur] + e.s < dis2[e.f]){
                dis2[e.f] = dis2[cur] + e.s;
                if(!inq[e.f]){
                    q.push({dis2[e.f], e.f});
                    inq[e.f] = 1;
                }
            }
        }
    }
    scanf("%d",&Q);
    while(Q--){
        scanf("%d%d",&F,&L);
        if(F == 1){
            if(dis1[L] == dis2[L])
                printf("%d\n", dis1[L]);
            else
                printf("-1\n");
        }else{
            a = channel[L].f.f, b = channel[L].f.s, c = channel[L].s;
            if((dis1[a] < dis2[a] && dis1[b] < dis2[b]) ||
                    (dis1[a] > dis2[a] && dis1[b] > dis2[b])){
                //no storm forms
                printf("-1\n");
            }else if(dis1[a] == dis2[a] && dis1[b] == dis2[b]){
                //both nodes get storm, choose earlier one
                printf("%d\n", min(dis1[a], dis1[b]));
            }else if(dis1[a] == dis2[a]){
                //both arrive at a
                if(min(dis1[b],dis2[b]) + c <= dis1[a])
                    printf("-1\n");
                //one front closes off the other
                else
                    printf("%d\n", dis1[a]);
            }else if(dis1[b] == dis2[b]){
                //both arrive at b
                if(min(dis1[a],dis2[a]) + c <= dis1[b])
                    printf("-1\n");
                //one front closes off the other
                else
                    printf("%d\n", dis1[b]);
            }else{
                if(dis1[a] < dis2[a] && dis1[b] > dis2[b]){
                    //printf("%d %d %d %d %d ", a, b, c, dis1[a], dis2[b]);
                    if(abs(dis1[a] - dis2[b]) >= c)
                        printf("%d\n", min(dis1[a],dis2[b]) + c);
                        //reaches one node early enough to travel to other node.
                    else
                        printf("%.1f\n", ((double)(dis1[a] + dis2[b] + c))/2.0);
                }else if(dis1[a] > dis2[a] && dis1[b] < dis2[b]){
                    if(abs(dis2[a] - dis1[b]) >= c)
                        printf("%d\n", min(dis2[a], dis1[b]) + c);
                    else
                        printf("%.1f\n", ((double)(dis2[a] + dis1[b] + c))/2.0);
                }
            }
        }
    }
    return 0;
}
// not handling edges properly
//
// so storms at nodes don't count as storms on edges
// check when both storms arrive at same node
// if the distance is less than c,
// then no node forms
//
// fixed