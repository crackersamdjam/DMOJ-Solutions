#include <bits/stdc++.h>
#define MM 100002
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
priority_queue<pii, vector<pii>, greater<pii>> q[102];
//location, id [which candy apple]
int N, S, Q, dis[MM];
bool can[MM][102];
char op;
int main(){
    scanf("%d%d",&N,&S);
    for(int i = 1; i <= N; i++)
        scanf("%d", dis+i);

    for(int i = 0,s,a; i < S; i++){
        scanf("%d%d",&s,&a);
        q[a].push({dis[s], s});
        can[s][a] = 1;
    }
    scanf("%d",&Q);
    for(int i = 0,x,k; i < Q; i++){
        scanf(" %c %d", &op, &x);
        if(op == 'Q'){
            k = x;
            while(!q[k].empty() && ((q[k].top().f != dis[q[k].top().s]) || !can[q[k].top().s][k]))
                q[k].pop();

            if(q[k].empty())
                printf("-1\n");
            else
                printf("%d\n", q[k].top().s);

            continue;
        }
        scanf("%d",&k);
        switch(op){
            case 'A':
                q[k].push({dis[x], x});
                can[x][k] = 1;
                break;
            case 'S':
                can[x][k] = 0;
                break;
            case 'E':
                for(int i = 1; i <= 100; i++)
                    can[x][i] = 0;
                dis[x] = k;
                break;
        }
    }
    return 0;
}