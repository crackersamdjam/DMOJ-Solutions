#include <bits/stdc++.h>
using namespace std;

int par[100002], G, P, ans;

inline int find(int x){
    while(x != par[x]){
        x = par[x];
        par[x] = par[par[x]];
    }
    return x;
}

int main(){

    scanf("%d%d", &G, &P);

    for(int i = 1; i <= G; i++)
        par[i] = i;
    
	for(int i = 0,g; i < P; i++){
        scanf("%d", &g);
        if(find(g)){
            ans++;
            par[find(g)] = find(find(g)-1);
        }
		else break;
    }

    printf("%d\n", ans);
    
	return 0;
}