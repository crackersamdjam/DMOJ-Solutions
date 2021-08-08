#include <bits/stdc++.h>
using namespace std;

int mod = 998244353;

vector<int> f(int n){
    vector<int> ans(n);
    ans[0] = 1;
    for(int i = 2; i <= n; i++){
        ans[i-1] = (1LL*ans[i-2]*i)%mod;
    }
    return ans;
}

#ifndef ONLINE_JUDGE
int main(){
    vector<int> vec = f(10);
    for(int i: vec){
        printf("%d ", i);
    }
}
#endif