#include <bits/stdc++.h>
using namespace std;
int main() {
    bool a[2] = {false, false};
    int c;
    scanf("%d", &c);
    for(int i = 0; i < c; i++){
        int n; char E[6]; int last = -1;
        scanf("%d", &n);
        switch(n){
            case 1:
                scanf("%s", E);
                if(E[0] == 't'){
                    if(a[0]) printf("false\n");
                    else{
                        a[0] = true;
                        printf("true\n");
                        last = 0;
                    }
                }else{
                    if(a[1]) printf("false\n");
                    else{
                        a[1] = true;
                        printf("true\n");
                        last = 1;
                    }
                }
                break;
            case 2:
                scanf("%s", E);
                if(E[0] == 't'){
                    if(!a[0]) printf("false\n");
                    else{
                        a[0] = false;
                        printf("true\n");
                    }
                }else{
                    if(!a[1]) printf("false\n");
                    else{
                        a[1] = false;
                        printf("true\n");
                    }
                }
                break;
            case 3:
                scanf("%s", E);
                if(E[0] == 't'){
                    if(a[0]) {
                        if(a[1] && last == 0) printf("1\n");
                        else printf("0\n");
                    } else printf("-1\n");
                }else{
                    if(a[1]) {
                        if(a[0] && last == 1) printf("1\n");
                        else printf("0\n");
                    } else printf("-1\n");
                }
                break;
            case 4:
                if(a[1] && a[0]) printf("false true\n");
                else if(a[0]) printf("true\n");
                else if(a[1]) printf("false\n");
                break;
        }
    }
    return 0;
}