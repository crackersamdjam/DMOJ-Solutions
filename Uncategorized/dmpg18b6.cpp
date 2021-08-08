#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    set<int> cd;
    for(int i = 0, a; i < n; i++){
        scanf("%d", &a);
        cd.insert(a);
    }
    int s = *cd.rbegin();
    int ans = 1;
    cd.erase(s);
    while(!cd.empty()){
        int i = *cd.rbegin();
        cd.erase(i);
        if(i + k <= s){
            ans++;
            s = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}