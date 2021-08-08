#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;

int n, q, cnt[MM], odd, par[MM];
set<int> st;
int find(int x){
    while(x != par[x])
        x = par[x], par[x] = par[par[x]];
    return x;
}

int main(){
    scanf("%d %d", &n, &q);
    while(q--){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if(!par[a]){
            par[a] = a;
            st.insert(a);
        }
        if(!par[b]){
            par[b] = b;
            st.insert(b);
        }
        if(find(a) != find(b)){
            st.erase(find(b));
            par[find(b)] = find(a);
        }
        
        c &= 1;
        odd -= cnt[a] + cnt[b];
        cnt[a] ^= c;
        cnt[b] ^= c;
        odd += cnt[a] + cnt[b];
        if((odd == 0 or odd == 2) and st.size() == 1)
            puts("YES");
        else
            puts("NO");
    }
    
    
    return 0;
}