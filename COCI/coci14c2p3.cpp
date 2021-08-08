#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int MM = 5001;

int N, K, a[MM], at[MM];
pii b[MM];
vector<int> lis;

int main(){
    
    scanf("%d %d", &N, &K);
    
    for(int i = 0; i < N; i++){
        scanf("%d", a+i);
        b[i] = {a[i], i};
    }
    
    sort(b, b+N);
    
    for(int i = 0; i < N; i++){
        at[b[i].second] = i/K; //which group student i should be in
    }
    
    //all any not in order will be moved exactly once
    //keep the lis, mv the rest
    
    lis.push_back(-1);
    
    for(int i = 0; i < N; i++){
        if(at[i] >= lis.back())
            lis.push_back(at[i]);
        else
            *(upper_bound(lis.begin(), lis.end(), at[i])) = at[i];
    }
    
    printf("%d\n", N - lis.size() + 1);
    
    return 0;
}