#include <bits/stdc++.h>
#define MM 1026
using namespace std;
typedef long long ll;
ll sum;
int tree[MM][MM],t,S,a,b,c,d;
void update(int x, int yy, int val){
    while(x <= S){
        int y = yy;
        while(y <= S){
            tree[x][y] += val;
            y += (y & -y);
        }
        x += (x & -x);
    }
}
ll query(int r, int yy){
    sum = 0;
    while(r > 0){
        int y = yy;
        while(y > 0){
            sum += tree[r][y];
            y -= (y & -y);
        }
        r -= (r & -r);
    }
    return sum;
}
int main(){
    while(t != 3){
        scanf("%d",&t);
        switch(t){
            case 0:
                scanf("%d",&S);
                break;
            case 1:
                scanf("%d%d%d",&a,&b,&c);
                update(a+1,b+1,c);
                break;
            case 2:
                scanf("%d%d%d%d",&a,&b,&c,&d);
                printf("%lld\n", query(c+1,d+1) - query(c+1,b)
                                 - query(a, d+1) + query(a,b));
                break;
            case 3:
                break;
        }
    }
    return 0;
}