#include <bits/stdc++.h>
using namespace std;
int main() {
    int na, cnt=0, a, b, c;
    scanf("%d%d%d%d",&na,&a,&b,&c);
    for(int n = na; n > 0; n--){
        switch(cnt%3){
            case 0:
                a++;
                if(a%35==0) n+=30;
                break;
            case 1:
                b++;
                if(b%100==0) n+=60;
                break;
            case 2:
                c++;
                if(c%10==0) n+=9;
                break;
        }
        cnt++;
    }
    printf("Martha plays %d times before going broke.\n",cnt);
    return 0;
}