#include <bits/stdc++.h>
using namespace std;
#define MM 50002
int saw[MM], logs[MM];
int N;
long long ans = 0;
int main() {
    scanf("%d",&N);
    for(int i = 0; i < N; i++)
        scanf("%d",&saw[i]);
    for(int i = 0; i < N; i++)
        scanf("%d",&logs[i]);
    sort(saw, saw+N);
    sort(logs, logs+N);
    for(int i = 0; i < N; i++){
        int j = N-1 - i;
        ans += ((long long)(saw[i])*(long long)(logs[j]));
    }
    printf("%lld\n",ans);
    return 0;
}