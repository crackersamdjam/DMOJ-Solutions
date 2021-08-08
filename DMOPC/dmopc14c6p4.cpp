#include <bits/stdc++.h>
using namespace std;
#define MM 103
int arr[MM];
int main() {
    int n, m, h, t=0;
    scanf("%d%d%d",&n,&m,&h);
    for(int i = 0; i < n; i++) scanf("%d",&arr[i]);
    for(int i = n-2; i >= 0; i--){
        while(arr[i+1]-arr[i] > h) {
            arr[i] += m;
            t++;
        }
    }
    printf("%d\n",t);
    return 0;
}