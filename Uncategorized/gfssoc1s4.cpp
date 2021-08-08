#include <bits/stdc++.h>
#define MM 252
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef long long ll;
ll tree[MM][MM][MM],sum,ans;
int arr[MM][MM][MM],N,Q,q,x,y,z,l,dif,x2,y2,z2;
void update(int xx, int yy, int zz, int val){
    for(int i = xx; i <= N; i += i & -i)
        for(int j = yy; j <= N; j += j & -j)
            for(int k = zz; k <= N; k += k & -k)
                tree[i][j][k] += val;
}
ll query(int xx, int yy, int zz){
    sum = 0;
    for(int i = xx; i > 0; i -= i & -i)
        for(int j = yy; j > 0; j -= j & -j)
            for(int k = zz; k > 0; k -= k & -k)
                sum += tree[i][j][k];
    return sum;
}
int main(){
    sc(N); sc(Q);
    while(Q--){
        q = getchar_unlocked();
        if(q == 'C'){
            sc(x); sc(y); sc(z); sc(l);
            dif = l - arr[x][y][z];
            arr[x][y][z] = l;
            update(x,y,z,dif);
        }else{
            sc(x); sc(y); sc(z); sc(x2); sc(y2); sc(z2);
            x--, y--, z--;
            ans += query(x2,y2,z2) - query(x,y2,z2)
            - query(x2,y,z2) - query(x2,y2,z) + query(x2,y,z)
            + query(x,y2,z) + query(x,y,z2) - query(x,y,z);
        }
    }
    printf("%lld\n",ans);
    return 0;
}