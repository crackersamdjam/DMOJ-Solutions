#include <bits/stdc++.h>
using namespace std;
int n,a,b,c;
vector<int> d;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a);
        d.push_back(a);
    }
    sort(d.begin(),d.end());
    printf("%d\n",d[n-1]-d[0]);
}