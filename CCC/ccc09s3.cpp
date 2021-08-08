#include <bits/stdc++.h>
#define MM 52
using namespace std;
char c;
int a, b, cnt, dis[MM];
unordered_set<int> vec, out;
queue<int> q;
bool adj[MM][MM], con;
inline void init(int s, int r){
    adj[s][r] = adj[r][s] = 1;
}
int main(){
    init(2,6);
    init(1,6);
    init(3,6);
    init(4,6);
    init(5,6);
    init(7,6);
    init(3,4);
    init(4,5);
    init(3,5);
    init(3,15);
    init(15,13);
    init(13,14);
    init(13,12);
    init(12,11);
    init(11,10);
    init(10,9);
    init(12,9);
    init(8,9);
    init(7,8);
    init(16,18);
    init(16,17);
    init(18,17);
    while(1){
        scanf(" %c",&c);
        if(c == 'q')
            break;
        switch(c){
            case 'i':
                scanf("%d%d",&a,&b);
                adj[a][b] = adj[b][a] = 1;
                break;
            case 'd':
                scanf("%d%d",&a,&b);
                adj[a][b] = adj[b][a] = 0;
                break;
            case 'n':
                scanf("%d",&a);
                cnt = 0;
                for(int i = 0; i < MM; i++)
                    if(adj[a][i])
                        cnt++;
                printf("%d\n",cnt);
                break;
            case 'f':
                scanf("%d",&a);
                while(!q.empty()) q.pop();
                q.push(a);
                memset(dis,0x3f,sizeof(dis));
                dis[a] = 0;
                while(!q.empty()){
                    int cur = q.front(); q.pop();
                    for(int i = 0; i < MM; i++){
                        if(adj[cur][i] && dis[cur] + 1 < dis[i] && dis[cur]+1 <= 2){
                            dis[i] = dis[cur] + 1;
                            q.push(i);
                        }
                    }
                }
                cnt = 0;
                for(int i = 0; i < MM; i++)
                    if(dis[i] == 2)
                        cnt++;
                printf("%d\n",cnt);
                break;
            case 's':
                scanf("%d%d",&a,&b);
                con = 0;
                while(!q.empty()) q.pop();
                q.push(a);
                memset(dis,0x3f,sizeof(dis));
                dis[a] = 0;
                while(!q.empty()){
                    int cur = q.front(); q.pop();
                    if(cur == b){
                        con = 1;
                        printf("%d\n",dis[cur]);
                        break;
                    }
                    for(int i = 0; i < MM; i++){
                        if(adj[cur][i] && dis[cur] + 1 < dis[i]){
                            dis[i] = dis[cur] + 1;
                            q.push(i);
                        }
                    }
                }
                if(!con)
                    printf("Not connected\n");
                break;
        }
    }
    return 0;
}