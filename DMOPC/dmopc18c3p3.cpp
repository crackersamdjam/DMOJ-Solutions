#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MM = 1e6+2;
char a[MM];
int N, len[MM];
int main(){
    scanf("%d ", &N);
    for(int i = 1; i <= N; i++){
        scanf("%c",a+i);
        len[i] = 1;
        if(a[i] == a[i-1])
            len[i] += len[i-1];
    }
    for(int i = N; i > 0; i--){
        if(a[i] == a[i+1])
            len[i] = len[i+1];
    }
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        //odd
        ans += min(len[i], min(i, N-i+1));
        
        //even
        if(a[i] == a[i+1])
            ans += min(len[i], min(i, N-i));
        else
            ans += min(max(len[i],len[i+1]), min(i, N-i));
    }
    printf("%lld\n", ans);
    return 0;
}