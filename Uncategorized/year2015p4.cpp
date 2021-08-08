#include <bits/stdc++.h>
#define MM 1002
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
bool vis[MM][MM];
struct st{
    int a,b;
    string str;
};
queue<st> q;
int A,B,M;
int main(){
    sc(A); sc(B); sc(M);
    vis[0][0] = 1;
    q.push({0,0,""});
    while(!q.empty()){
        st cur = q.front(); q.pop();
        if(cur.a == M || cur.b == M){
            cout << cur.str;
            return 0;
        }
        if(!vis[0][cur.b]){
            vis[0][cur.b] = 1;
            q.push({0,cur.b,cur.str + "chug A\n"});
        }
        if(!vis[cur.a][0]){
            vis[cur.a][0] = 1;
            q.push({cur.a,0,cur.str + "chug B\n"});
        }
        if(!vis[A][cur.b]){
            vis[A][cur.b] = 1;
            q.push({A,cur.b,cur.str + "fill A\n"});
        }
        if(!vis[cur.a][B]){
            vis[cur.a][B] = 1;
            q.push({cur.a,B,cur.str + "fill B\n"});
        }
        int dif = min(B-cur.b, cur.a);
        if(!vis[cur.a-dif][cur.b+dif]){
            vis[cur.a-dif][cur.b+dif] = 1;
            q.push({cur.a-dif, cur.b+dif, cur.str + "pour A B\n"});
        }
        dif = min(A-cur.a, cur.b);
        if(!vis[cur.a+dif][cur.b-dif]){
            vis[cur.a+dif][cur.b-dif] = 1;
            q.push({cur.a+dif, cur.b-dif, cur.str + "pour B A\n"});
        }
    }
    cout << "Not possible" << endl;
    return 0;
}