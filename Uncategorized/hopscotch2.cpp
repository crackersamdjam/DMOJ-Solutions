#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MM 8388610
#define f first
#define s second
using namespace std;
typedef long long ll;
ll N,K,r,n,nx,par[MM];
deque<pair<ll,ll>> q;
stack<ll> path;
int main(){
    sc(N); sc(K);
    q.push_back({0,0});
    for(r = 1; r <= N; r++){
        sc(n);
        while(q.front().s < r-K){
            q.pop_front();
        }
        n += q.front().f;
        par[r] = q.front().s;
        while(q.back().f >= n){
            q.pop_back();
        }
        q.push_back({n,r});
    }
    while(q.front().s < N+1-K)
        q.pop_front();
    n += q.front().f;
    par[r] = q.front().s;
    while(q.back().f >= n){
        q.pop_back();
    }
    q.push_back({n,r});
    printf("%lld\n",q.front().f);
    nx = q.front().s;
    while(nx != 0){
        path.push(nx);
        nx = par[nx];
    }
    while(!path.empty()){
        printf("%lld ",path.top());
        path.pop();
    }
    return 0;
}