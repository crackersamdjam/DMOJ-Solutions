#include <iostream>
unsigned long long C,D,E,i,temp,cnt=1;
int main(){
    scanf("%llu%llu%llu",&C,&D,&E);
    temp = C^D;
    for(i = 0; i < 32; i++, C >>= 1, D >>= 1)
        if(!(C&1) && (D&1)){
            printf("0");
            return 0;
        }
    for(i  = 0; i < 32; i++, temp >>= 1, E >>= 1)
        if(temp&1 && E&1)
            cnt<<=1;
    printf("%llu",cnt);
    return 0;
}