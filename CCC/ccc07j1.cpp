#include <bits/stdc++.h>
using namespace std;
int arr[3];
int main() {
    for(int i = 0;i < 3; i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+3);
    printf("%d\n",arr[1]);
    return 0;
}