#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
const int maxr = 10000000;

int N;
map<int, int> mp;
int main(){
    sc(N);
    int r;
    sc(r);
    r = maxr - r;
    //reverse order, high rank = low number
    mp[r] = 2;
    for(int i = 2; i <= N; i++){
        sc(r);
        r = maxr - r;
        auto itr = mp.lower_bound(r);
        if(itr == mp.end()){
            printf("NO\n");
            //printf("%d\n", i);
            return 0;
        }
        if(--itr->second == 0){
            mp.erase(itr);
        }
        mp[r] += 2;
    }
    printf("YES\n");
    return 0;
}
/*
 * find prev value larger than a[i]
 * remove
 * add current value
 */