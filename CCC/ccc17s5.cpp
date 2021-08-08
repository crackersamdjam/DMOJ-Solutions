//fast judge :poggers:

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
using ll = long long;
const int MM = 150001, SZ = 300;

int n, m, q, gp[MM], id[MM], loc[MM], shift[MM];
bool ch[MM];
ll sum[MM], a[MM], ans;
std::vector<std::pair<int, int>> line[MM];
std::vector<int> mv[MM];

ll at(int ind){
    int ln = id[ind];
    ind = loc[ind]-shift[ln];
    if(ind < 0) ind += line[ln].size();
    return a[line[ln][ind].first];
}

int main(){
    scanf("%d%d%d",&n,&m,&q);
    for(int i = SZ; i <= n; i += SZ)
        ch[i] = 1;
    for(int i = 1; i <= n; i++){
        gp[i] = gp[i-1]+ch[i];
        scanf("%d", id+i);
        loc[i] = line[id[i]].size();
        line[id[i]].emplace_back(i, gp[i]);
    }
    for(int i = 1; i <= n; i++){
        scanf("%lld", a+i);
        sum[gp[i]] += a[i];
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < line[i].size(); j++){
            //two of each (front and end)
            if((!j or line[i][j].second != line[i][j-1].second) or (j == line[i].size()-1 or line[i][j].second != line[i][j+1].second))
                mv[i].emplace_back(line[i][j].first);
        }
        mv[i].emplace_back(line[i][0].first);
    }
    
    for(int z = 0,op,l,r; z < q; z++){
        scanf("%d%d",&op,&l);
        if(op == 1){
            scanf("%d",&r);
            int lg = gp[l], rg = gp[r], lo = lg*SZ, hi = rg*SZ;
            if(lo < l){
                lg++;
                lo += SZ;
            }
            ans = 0;
            if(lg >= rg){
                for(int i = l; i <= r; i++)
                    ans += at(i);
            }
            else{
                for(int i = lg; i < rg; i++)
                    ans += sum[i];
                for(int i = l; i < lo; i++)
                    ans += at(i);
                for(int i = hi; i <= r; i++)
                    ans += at(i);
            }
            printf("%lld\n", ans);
        }
        else{
            for(int i = 1; i < mv[l].size(); i++){
                int ri = mv[l][i], p = mv[l][i-1];
                sum[gp[ri]] += at(p) - at(ri);
            }
            int s = line[l].size();
            if(++shift[l] == s)
                shift[l] -= s;
        }
    }
    
    return 0;
}