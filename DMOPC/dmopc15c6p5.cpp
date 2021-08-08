#include <bits/stdc++.h>
using namespace std;
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MM 3000001
#define f first
#define s second
int a[MM];
int N,K,l=0,r=0;
long long ans = 0;
deque<pair<int,int>> maxq, minq;
int main(){
    sc(N); sc(K);
    for(int i = 0; i < N; i++)
        sc(a[i]);
    a[N] = INT_MAX;
    while(l < N){
        while(!maxq.empty() && maxq.front().s < l)
            maxq.pop_front();
        while(!minq.empty() && minq.front().s < l)
            minq.pop_front();
        while(!maxq.empty() && a[r] >= maxq.back().f)
            maxq.pop_back();
        maxq.push_back({a[r], r});
        while(!minq.empty() && a[r] <= minq.back().f)
            minq.pop_back();
        minq.push_back({a[r], r});
        if(maxq.front().f - minq.front().f <= K)
            r++;
        else{
            l++;
            ans += r-l+1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}