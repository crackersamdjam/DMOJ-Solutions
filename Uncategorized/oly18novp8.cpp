#include <bits/stdc++.h>
#define MM 15002
#define f first
#define s second
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef pair<int,int> pii;
pii vecy[MM];
int N, ans[MM];
int main(){
    sc(N);
    for(int i = 0,a,b; i < N; i++){
        sc(a); sc(b);
        vecy[i] = {a,b};
        //vecx[N-1-i] = {-a,-b};
    }
    //sort(vecx, vecx+N, [](pii &a, pii &b){return a.f < b.f;});
    vector<int> cur;
    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(int j = 0; j < i; j++){
            if(vecy[j].f <= vecy[i].f)
                cnt++;
        }
        ans[cnt]++;
    }
    for(int i = 0; i < N; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
}