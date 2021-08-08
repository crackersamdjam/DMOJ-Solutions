#include <bits/stdc++.h>
using namespace std;
#define MM 26
int main() {
    int n; scanf("%d",&n);
    for(int i = 0; i < n ; i++){
        char arr[3][MM];
        scanf("%s%s%s",arr[0],arr[1],arr[2]);
        bool ans = true;
        int last[3];
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < MM; k++){
                if(arr[j][k] == '\0'){
                    last[j] = k-1; break;
                }
            }
        }
        for(int j = 0; j < 3; j++){
            for(int k = j+1; k < 3; k++){
                bool free = true;
                for(int l = 0; l <= min(last[j],last[k]); l++){
                    if(arr[j][l] != arr[k][l]){
                        free = false;
                        break;
                    }
                }
                if(!free) {
                    free = true;
                    for (int l = last[j], l2 = last[k]; l >= 0 && l2 >= 0; l--, l2--) {
                        if (arr[j][l] != arr[k][l2]) {
                            free = false;
                            break;
                        }
                    }
                }
                if(free){
                    ans = false;
                    break;
                }
            }
            if(!ans) break;
        }
        printf(ans? "Yes\n": "No\n");
    }
    return 0;
}