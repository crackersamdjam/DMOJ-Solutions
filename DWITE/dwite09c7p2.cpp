#include <bits/stdc++.h>
#define MM 100002
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
bool np[MM];
int tc = 5, n;
int main(){
    for(int i = 2; i < MM; i++)
        if(!np[i])
            for(int j = i<<1; j < MM; j += i)
                np[j] = 1;

    while(tc--){
        sc(n);
        int ans = 0;
        for(int i = 2; i <= n; i++)
            if(!np[i])
                ans += i;
        printf("%d\n", ans);
    }
    return 0;
}