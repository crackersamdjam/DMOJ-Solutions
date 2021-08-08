#include <bits/stdc++.h>
#define MM 100002
#define mp make_pair
using namespace std;
deque<pair<int,int>> q;
map<int,int> m;
int Q;
char op;
int main(){
    scanf("%d",&Q);
    for(int i = 1,a; i <= Q; i++){
        scanf(" %c %d",&op,&a);
        switch(op){
            case 'F':
                q.push_front(mp(a,i));
                m[a] = i;
                break;
            case 'E':
                q.push_back(mp(a,i));
                m[a] = i;
                break;
            case 'R':
                m[a] = 0;
                break;
        }
    }
    while(!q.empty()){
        auto i = q.front(); q.pop_front();
        if(m[i.first] == i.second)
            printf("%d\n", i.first);
    }
    return 0;
}