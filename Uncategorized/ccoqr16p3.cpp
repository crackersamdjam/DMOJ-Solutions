#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e5+1;

int N, M;
ll ans;
pair<int, int> a[MM], last;

int main(){
    
    scanf("%d%d", &N, &M);
    
    for(int i = 0; i < M; i++){
        scanf("%d%d", &a[i].second, &a[i].first);
        //from top, so reverse row
        a[i].second = N - a[i].second + 1;
    }
    
    sort(a, a+M);
    
    last = a[0];
    ans += (ll)a[0].second*(a[0].second+1)/2;
    
    for(int i = 1; i < M; i++){
        auto pre = a[i-1];
        if(last.second - (a[i].first - last.first) <= pre.second - (a[i].first - pre.first))
            last = pre;
    
        int dif = last.second - (a[i].first - last.first);
        
        if(a[i].second >= dif){
            //otherwise completely contained
            ans += (ll)a[i].second*(a[i].second+1)/2;
            if(dif > 0)
                ans -= (ll)dif*(dif+1)/2;
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}
/*
 * only need to compare with tallest previous
 *
 * update tallest (last vs highest) after going to new pt
 * max(cur_i - highest_i + highest_v, cur_i - last_i + highest_v)
 */