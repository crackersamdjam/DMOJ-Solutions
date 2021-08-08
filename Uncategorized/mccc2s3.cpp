#include <bits/stdc++.h>
using namespace std;
const int MM = 5e4+2, MN = 130;

int n, m, q, par[MN][MM];
int find(int k, int x){
    while(x != par[k][x]){
        x = par[k][x], par[k][x] = par[k][par[k][x]];
    }
    return x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    for(int i = 0; i < MN; i++)
        for(int j = 1; j <= n; j++)
            par[i][j] = j;
    for(int i = 0,a,b,c; i < m; i++){
        cin>>a>>b>>c;
        for(int j = 0; j < MN; j++)
            if((c&j) == c){
                int fa = find(j, a), fb = find(j, b);
                par[j][fa] = fb;
            }
    }
    for(int t = 0,a,b; t < q; t++){
        cin>>a>>b;
        for(int j = 0; j < MN; j++){
            if(find(j, a) == find(j, b)){
                cout<<j<<'\n';
                break;
            }
            assert(j != 129);
        }
    }
        
    return 0;
}