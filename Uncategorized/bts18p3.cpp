#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N,X,t;
ll sum;
priority_queue<int> q;
int main(){
    scanf("%d%d",&N,&X);
    for(int i = 0,m; i < N; i++){
        scanf("%d",&m);
        q.push(m);
    }
    while(X){
        t = q.top(); q.pop();
        if(t < 1)
            break;
        sum += t;
        X--;
        q.push(t-1);
    }
    printf("%lld\n",sum);
    return 0;
}