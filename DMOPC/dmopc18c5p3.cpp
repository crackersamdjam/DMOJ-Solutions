#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 2e5+1;

int N, a[MM];
ll M;

int main(){
    
    cin >> N >> M;
    
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    
    int l = 0, r = 0, ans = 0;
    ll sum = a[0];
    
    while(l < N && r < N){
        if(sum < M){
            ans = max(ans, r-l+1);
            sum += a[++r];
        }
        else if(l == r){
            sum += a[++r];
        }
        else{
            sum -= a[l++];
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}