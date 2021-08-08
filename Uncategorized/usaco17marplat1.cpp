#include <bits/stdc++.h>
using namespace std;
const int MM = 1002;

int n, a[MM][MM], lx[MM*MM], ly[MM*MM], rx[MM*MM], ry[MM*MM];
bool no[MM*MM];
set<int> s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(lx, 0x3f, sizeof lx);
    memset(ly, 0x3f, sizeof ly);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j];
            int v = a[i][j];
            lx[v] = min(lx[v], i);
            ly[v] = min(ly[v], j);
            rx[v] = max(rx[v], i);
            ry[v] = max(ry[v], j);
            s.insert(v);
        }
    }
    
    if(s.size() == 2)
        return printf("%d\n", n*n-1), 0;
    
    for(int k = 1; k <= n*n; k++){
        for(int i = lx[k]; i <= rx[k]; i++){
            for(int j = ly[k]; j <= ry[k]; j++){
                int v = a[i][j];
                if(v != k)
                    no[v] = 1;
            }
        }
    }
    int ans = 0;
    for(int k = 1; k <= n*n; k++)
        ans += !no[k];
    
    cout << ans << '\n';
    
    return 0;
}