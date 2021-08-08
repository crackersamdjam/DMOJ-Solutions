#include <bits/stdc++.h>
using namespace std;
#define MM 1000001
int nums[MM];
int arr[MM];
bool contains[MM];
bool vis[MM];
int ans[MM];
queue<int> v;
unordered_map<int, int> S;
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        nums[i] = i;
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &arr[i]);
        if(!contains[arr[i]]) {
            contains[arr[i]] = true;
            v.push(arr[i]);
        }
    }
    if(v.size() == 1){
        printf("%d\n", -1); return 0;
    }
    v.push(v.front()); v.pop();
    for(int i = 1; i <= n; i++){
        if(!vis[arr[i]]){
            vis[arr[i]] = true;
            ans[i] = v.front(); v.pop();
            nums[ans[i]] = -1;
        }
    }
    int cnt = 1;
    for(int i = 1; i <= n; i++){
        if(ans[i]) {
            printf("%d ",ans[i]);
            continue;
        }
        while(nums[cnt] == -1) cnt++;
        ans[i] = nums[cnt]; cnt++;
        printf("%d ",ans[i]);
    }
    return 0;
}
/*
5
2 1 4 1 1
 */