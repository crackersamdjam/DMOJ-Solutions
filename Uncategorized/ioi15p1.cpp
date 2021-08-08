#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 1e7+2;

ll pre[MM], suf[MM], ans;

long long delivery(int n, int k, int m, int a[]){
    sort(a, a+n);
    for(int i = 0; i < n; i++){
        pre[i] = 2*min(a[i], m);
        if(i >= k)
            pre[i] += pre[i-k];
    }
    for(int i = n-1; i >= 0; i--){
        suf[i] = 2*min(m-a[i], m);
        if(i+k < n)
            suf[i] += suf[i+k];
    }
    ans = min((ll)(n+k-1)/k*m, suf[0]);
        
    for(int i = 0; i < n; i++){
        ans = min(ans, pre[i]+suf[i+1]);
        int j = i+k+1;
        if(j <= n)
            ans = min(ans, pre[i] + m + suf[j]);
    }
    return ans;
}

#ifndef ONLINE_JUDGE
int z[MM];
int main(){
    
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
    int n, k, m;
    cin >> n >> k >> m;
    for(int i = 0; i < n; i++)
        cin >> z[i];
    cout << delivery(n, k, m, z);

    return 0;
}
#endif