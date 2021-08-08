#include <bits/stdc++.h>
int sa,sb,a,b,c;
int main(){
    for(int i = 1;;i++){
        a = getchar_unlocked();
        if(a == '\n')
            break;
        if(a < 'a')
            a += 'a'-'A';
        c = i%4;
        if(c == 0)
            c += 4;
        sa = (sa + (int)pow(a-'a'+1, c))%10;
    }
    for(int i = 1;;i++){
        b = getchar_unlocked();
        if(b == '\n')
            break;
        c = i%4;
        if(c == 0)
            c += 4;
        if(b < 'a')
            b += 'a'-'A';
        sb = (sb + (int)pow(b-'a'+1, c))%10;
    }
    if(sa == 0)
        sa += 10;
    if(sb == 0)
        sb += 10;
    printf("%d\n",sa+sb);
    return 0;
}