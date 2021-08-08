#include <iostream>
char cnt[5];
int main(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(getchar_unlocked() == '1')
                cnt[i]++, cnt[j]++, cnt[4]++;
            getchar_unlocked();
        }
    }
    if(cnt[4]>6){
        putchar_unlocked('N'); putchar_unlocked('o');
        return 0;
    }else if(cnt[4] == 6){
        for(int i = 0; i < 4; i++)
            if(!cnt[i]){
                putchar_unlocked('N'); putchar_unlocked('o');
                return 0;
            }
    }
    putchar_unlocked('Y'); putchar_unlocked('e'); putchar_unlocked('s');
    return 0;
}