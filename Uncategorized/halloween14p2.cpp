#include <bits/stdc++.h>
#define MM 500002
using namespace std;
typedef long long ll;
ll val[MM],cost[MM],dp[MM],N,W,p,c,ptr=0,l,m,r;
char t;
int main(){
    scanf("%lld%lld",&N,&W);
    while(N--){
        scanf(" %c",&t);
        if(t == 'A'){
            ptr++;
            scanf("%lld%lld",&p,&c);
            cost[ptr] = cost[ptr-1] + p;
            val[ptr] = val[ptr-1] + c;
            l = 0, r = ptr;
            while(l <= r){
                m = l + (r-l)/2;
                if(cost[ptr] - cost[m] <= W)
                    r = m-1;
                else
                    l = m+1;
            }
            dp[ptr] = max(dp[ptr-1], val[ptr]-val[l]);
            printf("%lld\n",dp[ptr]);
        }else{
            dp[ptr] = 0;
            ptr--;
        }
    }
    return 0;
}