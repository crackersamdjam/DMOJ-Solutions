#include <bits/stdc++.h>
using namespace std;
int a[20], b[20], n;
bool dp[20][200][2][2];
unordered_set<int> st;
char as[20], bs[20];
void go(int pos, int sum, int l, int r){
    if(pos == n){
        st.insert(sum);
        return;
    }
    if(dp[pos][sum][l][r])
        return;
    for(int i = (l? a[pos]: 0); i <= (r? b[pos]: 9); i++)
        go(pos+1, sum+i, l&&(i == a[pos]), r&&(i == b[pos]));
    
    dp[pos][sum][l][r] = 1;
}
int main(){
    scanf("%s%s",as,bs);
    n = strlen(bs);
    for(int i = 0; i < n; i++)
        b[i] = bs[i] - '0';
    int dif = n - strlen(as);
    for(int i = 0; i < n; i++)
        a[i+dif] = as[i] - '0';
    go(0,0,1,1);
    printf("%d\n", st.size());
    return 0;
}