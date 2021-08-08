#include <bits/stdc++.h>
#define f first
#define s second
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
typedef pair<int,int> pii;
int p[4];
pii t[3];
int main(){
    for(int i = 1; i < 4; i++)
        sc(p[i]);
    for(int i = 0; i < 3; i++){
        sc(t[i].f); sc(t[i].s);
    }
    int cost = 0, num = 0;
    for(int i = 1; i <= 100; i++){
        for(int j = 0; j < 3; j++){
            if(t[j].f == i)
                num++;
            if(t[j].s == i)
                num--;
        }
        cost += p[num]*num;
    }
    printf("%d\n", cost);
    return 0;
}