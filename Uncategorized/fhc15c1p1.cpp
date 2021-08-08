#include <bits/stdc++.h>
#define MM 10000002
using namespace std;
vector<int> vec[10];
int fac[MM],T,A,B,K;
int main(){
    for(int i = 2; i < MM; i++){
        if(!fac[i])
            for(int j = i; j < MM; j+=i)
                fac[j]++;
        vec[fac[i]].push_back(i);
    }
    for(int i = 0; i <= 9; i++)
        sort(vec[i].begin(), vec[i].end());

    scanf("%d",&T);
    for(int i = 1; i <= T; i++){
        scanf("%d%d%d",&A,&B,&K);
        if(K > 9)
            printf("Case #%d: 0\n",i);
        else
            printf("Case #%d: %d\n",i,(int)(upper_bound(vec[K].begin(), vec[K].end(), B) -
                lower_bound(vec[K].begin(), vec[K].end(), A)));
    }
    return 0;
}