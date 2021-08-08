#include <bits/stdc++.h>
#define MM 1000002
using namespace std;
int b[MM],pos[MM],N,M;
vector<int> lis;
int main(){
    scanf("%d",&N);
    for(int i = 1,a; i <= N; i++){
        scanf("%d",&a);
        pos[a] = i;
    }
    scanf("%d",&M);
    for(int i = 1; i <= M; i++)
        scanf("%d",b+i);

    for(int i = 1; i <= M; i++){
        if(!(b[i] = pos[b[i]]))
            continue;
        if(lis.empty() || b[i] > lis.back())
            lis.push_back(b[i]);
        else
            *lower_bound(lis.begin(), lis.end(), b[i]) = b[i];
    }
    printf("%d\n",(int)lis.size());
    return 0;
}