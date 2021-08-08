#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MM = 1002;

ll mod = 1e9+7, cnt[MM*MM], ans=1;
int n, m, par[MM*MM];
char s[MM][MM];

int find(int i, int j){
    int x = i*MM+j;
    while(par[x] != x)
        x = par[x], par[x] = par[par[x]];
    return x;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < MM*MM; i++)
        par[i] = i, cnt[i] = 1;
    for(int i = 0; i < n; i++){
        scanf("%s", s[i]);
    }
    for(int i = n-2; i > 0; i--){
        for(int j = 1; j < m; j++){
            if(s[i][j] == '#')
                continue;
            if(s[i][j-1] == '.')
                par[find(i, j)] = find(i, j-1);
            if(s[i+1][j] == '.' and find(i+1, j) != find(i, j)){
                int a = find(i, j), b = find(i+1, j);
                par[b] = a;
                cnt[a] = cnt[a]*cnt[b] % mod;
            }
        }
        for(int j = 1; j < m; j++){
            int a = find(i, j);
            if(a == i*MM+j)
                cnt[a]++;
        }
    }
    for(int i = 1; i < n-1; i++){
        for(int j = 1; j < m-1; j++){
            if(s[i][j] == '#')
                continue;
            int a = find(i, j);
            //cout<<i<<' '<<j<<' '<<a/MM<<' '<<a%MM<<' '<<par[a]/MM<<' '<<par[a]%MM<<' '<<cnt[a]<<'\n';
            if(a == i*MM+j){
                ans = ans*cnt[a]%mod;
            }
        }
    }
    printf("%lld\n", ans);
    
    return 0;
}