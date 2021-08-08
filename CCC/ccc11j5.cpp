#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int n;
int ways(int x){
    int ans = 1;
    for(int i = 0; i < n-1; i++){
        if(arr[i] == x){
            ans *= 1 + ways(i+1);
        }
    }
    return ans;
}

int main() {
    scanf("%d", &n);
    //vector<int> arr[n+1];
    for(int i = 1, a; i < n; i++){
        scanf("%d", &a);
        arr.push_back(a);
    }
    printf("%d\n", ways(n));
    return 0;
}