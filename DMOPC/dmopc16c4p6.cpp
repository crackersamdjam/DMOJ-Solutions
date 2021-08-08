#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MM 1000002
#define f first
#define s second
int a[MM],N,Q,xk,yk;
ll cnt[MM]; //number of contiguous subseqs with index as smallest element
stack<pair<int,int>> q; //monotonically increasing
int main(){
    sc(N); sc(Q);
    for(int i = 1; i <= N; i++)
        sc(a[i]);
    q.push({-1,0});
    for(int i = 1; i <= N; i++){
        while(q.top().f >= a[i]){ //pop larger earlier elements, they won't go beyond i
            auto temp = q.top(); q.pop();
            cnt[temp.f] += (ll)(i - temp.s)*(ll)(temp.s - q.top().s); // (r - cur) * (cur - l)
        }
        q.push({a[i],i});
    }
    while(q.size() > 1){
        auto temp = q.top(); q.pop();
        cnt[temp.f] += (ll)(N+1 - temp.s)*(ll)(temp.s - q.top().s);
    }
    for(int i = 2; i < MM; i++)
        cnt[i] += cnt[i-1];
    while(Q--){
        sc(xk); sc(yk);
        printf("%lld\n", cnt[yk] - cnt[xk-1]);
    }
    return 0;
}