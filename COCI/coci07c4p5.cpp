#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 1e6+2;

int N, dp[MM], bit[MM];
pii a[MM];
stack<pii> out;

inline void update(int i, int v){
    i++;
    for(; i; i -= i&-i){
        if(v > bit[i])
            bit[i] = v;
    }
}

inline int query(int i){
    i++;
    int ret = 0;
    for(; i < MM; i += i&-i)
        ret = max(ret, bit[i]);
    return ret;
}

int main(){
    
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++)
        scanf("%d %d", &a[i].first, &a[i].second);
    
    sort(a, a+N, [](pii x, pii y){
        if(x.first == y.first)
            return x.second > y.second;
        return x.first < y.first;
    });
    
    for(int i = 0; i < N; i++){
        int ans = query(a[i].second)+1;
        dp[i] = ans;
        update(a[i].second, ans);
    }
    
    int num = query(0);
    
    printf("%d\n", num);
    
    int v = num;
    pii last = {1e9, -1};
    
    for(int i = N-1; i >= 0 && v; i--){
        if(dp[i] == v && a[i].first <= last.first && a[i].second >= last.second){
            v--;
            out.push(a[i]);
            last = a[i];
        }
    }
    
    while(!out.empty()){
        pii p = out.top(); out.pop();
        printf("%d %d\n", p.first, p.second);
    }
    
    return 0;
}