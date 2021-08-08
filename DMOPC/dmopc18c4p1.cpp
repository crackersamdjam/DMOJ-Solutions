#include<bits/stdc++.h>
using namespace std;
double st,pre,my,ans,d,K;
int main(){
    cin >> K >> st;
    my = pre = st;
    for(int i=1,n; i <= K; i++){
        cin >> n;
        for (int j = 1; j <= n; j++){
            cin >> d;
            my += d;
        }
        ans += my;
        my=pre;
    }
    printf("%lf\n",ans/K);
}