#include <bits/stdc++.h>
#define MM 102
char _;
using namespace std;
bool a[MM][MM];
int r, c, ans, s, sum, x[] = {-1,-1,-1,0,0,1,1,1}, y[] = {-1,0,1,-1,1,-1,0,1};
int main(){
    scanf("%d%d",&r,&c);
    for(int i = 1; i <= r; i++){
        getchar_unlocked();
        for(int j = 1; j <= c; j++){
            a[i][j] = (getchar_unlocked() == 'S');
        }
    }
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if(a[i][j])
                continue;
            if((i == 1 && j == 1) || (i == r && j == 1) || (i == 1 && j == c) || (i == r && j == c))
                s = 2;
            else if((i == 1) || (i == r) || (j == 1) || (j == c))
                s = 3;
            else
                s = 4;
            
            if(r == 1 || c == 1)
                s = 1;
            
            sum = 0;
            for(int k = 0; k < 8; k++)
                if(a[i + x[k]][j + y[k]])
                    sum++;
            if(sum < s)
                ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}