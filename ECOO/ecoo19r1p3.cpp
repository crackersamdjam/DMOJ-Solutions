#include <bits/stdc++.h>
using namespace std;

string arr[30];
int J, W, H;

bool canjump(int i, int k){
    
    if(2+k > H)
        return 0;
    
    //at col i, jump k up
    if(arr[2+k][i+1] != '.')
        return 0;
    
    bool pos = 1;
    
    for(int j = 1; j <= 2+k; j++){
        if(arr[j][i] == '@' or arr[j][i+2] == '@'){
            return 0;
        }
    }
    
    return pos;
}

int main(){
    
    //freopen("DATA32.txt", "r", stdin);
    for(int tc = 1; tc  <= 10; tc++){
        
        cin >> J >> W >> H;
        
        for(int i = H; i >= 1; i--){
            cin >> arr[i];
        }
        
        int ans, st = -1, ed = -1;
        
        for(int i = 0; i < W; i++){
            if(arr[2][i] == 'L'){
                st = i;
                arr[2][i] = '.';
            }
            if(arr[2][i] == 'G'){
                ed = i;
                arr[2][i] = '.';
            }
        }
        
        ans = st;
        
        for(int i = st; i <= ed; i++){
            ans = i;
            if(arr[2][i+1] == '.')
                continue;
            else{
                bool pos = 0;
                for(int k = 1; k <= J; k++){
                    if(canjump(i, k)){
                        pos = 1;
                        break;
                    }
                }
                if(!pos)
                    break;
                
                i++;
            }
        }
        
        if(ans == ed)
            puts("CLEAR");
        else
            printf("%d\n", ans+2);
    }
    
    return 0;
}