#include <bits/stdc++.h>
#define MM 1000002
using namespace std;
int J,A,arr[MM],cnt;
char c;
int main(){
    scanf("%d%d",&J,&A);
    for(int i = 1; i <= J; i++){
        scanf(" %c",&c);
        switch(c){
            case 'S':
                arr[i] = 1;
                break;
            case 'M':
                arr[i] = 2;
                break;
            case 'L':
                arr[i] = 3;
                break;
        }
    }
    for(int i = 1,sz,a; i <= A; i++){
        scanf(" %c%d",&c,&a);
        switch(c){
            case 'S':
                sz = 1;
                break;
            case 'M':
                sz = 2;
                break;
            case 'L':
                sz = 3;
                break;
        }
        if(arr[a] >= sz){
            cnt++;
            arr[a] = 0;
        }
    }
    printf("%d\n",cnt);
    return 0;
}