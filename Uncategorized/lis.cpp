#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> lis;
int main(){
    scanf("%d",&N);
    lis.push_back(-1);
    for(int i = 0,a; i < N; i++){
        scanf("%d",&a);
        if(a > lis.back())
            lis.push_back(a);
        else
            *(lower_bound(lis.begin(), lis.end(), a)) = a;
    }
    printf("%d\n",lis.size()-1);
    return 0;
}