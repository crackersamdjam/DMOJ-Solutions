#include <bits/stdc++.h>
#define MM 100002
#define f first
#define s second
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
vector<pii> vec[MM];
int N,n;
ll ans=0,h;
inline bool cmp(pii a, pii b){
    if(a.f == b.f)
        return a.s < b.s;
    return a.f > b.f;
}
int main(){
    sc(N);
    for(int i = 0,k,m; i < N; i++){
        sc(k); sc(m);
        vec[k+m].push_back({k,m});
    }
    for(int i = 1; i < MM; i++){
        if(vec[i].empty())
            continue;
        sort(vec[i].begin(),vec[i].end(),cmp);
        n = vec[i].size(), h = 0;
        for(int j = 1; j < n; j++)
            vec[i][j].f += vec[i][j-1].f;
        for(int j = n-2; j >= 0; j--)
            vec[i][j].s += vec[i][j+1].s;
        for(int j = 0; j < n-1; j++){
            if(min(vec[i][j].f, vec[i][j+1].s) > h)
                h = min(vec[i][j].f, vec[i][j+1].s);
            else break;
        }
        ans = max(ans, h);
    }
    printf("%lld\n",ans);
    return 0;
}