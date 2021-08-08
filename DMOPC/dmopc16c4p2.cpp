#include <bits/stdc++.h>
#define MM 100002
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
int fail[MM],B,F,sum=0;
struct st{
    int f,e,p;
};
st arr[MM];
int main(){
    sc(B);
    for(int i = 0; i < B; i++){
        sc(arr[i].f); sc(arr[i].e); sc(arr[i].p);
    }
    sc(F);
    for(int i = 0; i < F; i++)
        sc(fail[i]);
    sort(fail,fail+F);
    for(int i = 0; i < B; i++)
        if((lower_bound(fail,fail+F,arr[i].f) -
                upper_bound(fail,fail+F,arr[i].e)) >= 0)
            sum += arr[i].p;
    printf("%d\n",sum);
    return 0;
}