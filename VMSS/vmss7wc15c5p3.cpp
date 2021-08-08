#include <bits/stdc++.h>
#define MM 2002
#define mod 1000000007
using namespace std;
typedef long long ll;
ll tree[MM*2][MM],sum,ans;
int N,t;
inline void update(int r, int c, int val){
    for(; c < MM; c += c&-c)
        tree[r][c] = (tree[r][c]+val)%mod;
}
inline ll query(int r, int c){
    sum = 0;
    for(; c > 0; c -= c&-c)
        sum = (sum+tree[r][c])%mod;
    return sum;
}
int main(){
    int q,r,c;
    scanf("%d",&N);
    while(N--){
        scanf("%d%d%d%d",&q,&r,&c,&t);
        if(q == 1){
            r += c-1;
            update(r,c,t);
        }else{
            r += c-1;
            ans = (ans + query(r,c+t) - query(r,c-1))%mod;
        }
    }
    printf("%lld\n",ans);
    return 0;
}