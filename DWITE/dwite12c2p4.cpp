#include <bits/stdc++.h>
#define MM 102
using namespace std;
int arr[MM], N, ind, t = 5;
bool pos;
vector<int> vec;
int main(){
    while(t--){
        pos = 1;
        scanf("%d",&N);
        vec.push_back(0);
        for(int i = 1; i <= N; i++){
            scanf("%d",arr+i);
            vec.push_back(i);
        }
        for(int i = 1; i <= N; i++){
            ind = (int)vec.size()-arr[i]-1;
            if(ind < 1){
                pos = 0;
                break;
            }
            arr[i] = vec[ind];
            vec.erase((vec.begin()+ind));
        }
        if(!pos){
            printf("IMPOSSIBLE\n");
        }else{
            for(int i = 1; i <= N; i++)
                printf("%d ", arr[i]);
            putchar_unlocked('\n');
        }
    }
    return 0;
}