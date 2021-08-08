#include <bits/stdc++.h>
using namespace std;
#define MM 20
int arr[MM], dif[MM];
deque<int> deq;
int main() {
    int n;
    while(1){
        memset(arr,0,sizeof(arr));
        memset(dif,0,sizeof(dif));
        scanf("%d",&n);
        if(n == 0)break;
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        for(int i = 0; i < n-1; i++)
            dif[i] = arr[i+1]-arr[i];
        int ans = n-1;
        for(int i = 1; i < n-1; i++){
            deq.clear();
            bool b = true;
            for(int j = 0; j < i; j++)
                deq.push_back(dif[j]);
            for(int j = 0; j < n-1; j++){
                if(dif[j]!=deq.front()){
                    b = false;
                    break;
                }
                deq.push_back(deq.front()); deq.pop_front();
            }
            if(b){
                ans = i;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}