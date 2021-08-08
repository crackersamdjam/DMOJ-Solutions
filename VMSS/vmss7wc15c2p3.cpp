#include <bits/stdc++.h>
typedef long long ll;
#define f first
#define s second
std::stack<std::pair<ll,ll>> q;
ll N,h,add,cnt=0;
int main(){
    scanf("%lld",&N);
    while(N--){
        scanf("%lld",&h);
        add = 1;
        while(!q.empty() && q.top().f < h){
            cnt += q.top().s;
            q.pop();
        }
        if(!q.empty() && q.top().f == h){
            add += q.top().s;
            cnt += q.top().s;
            q.pop();
        }
        if(!q.empty())
            cnt++;
        q.push({h, add});
    }
    printf("%lld",cnt);
    return 0;
}