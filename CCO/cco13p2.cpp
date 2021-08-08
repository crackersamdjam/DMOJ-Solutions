#include <bits/stdc++.h>
#define MM 1<<21
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
pii tree[MM];
int N,M,K,i,val;
char c;
int main(){
    scanf("%d%d",&N,&M);
    K = (1<<N)-1;
    for(int i = 1; i <= K+1; i++){
        scanf("%d",&tree[i+K].f);
        tree[i+K].s = i;
    }
    for(int i = K; i > 0; i--)
        tree[i] = max(tree[i<<1], tree[(i<<1)+1]);
    while(M--){
        scanf(" %c",&c);
        if(c == 'R'){
            scanf("%d%d",&i,&val);
            i += K;
            tree[i].f = val;
            for(i>>=1; i > 0; i>>=1)
                tree[i] = max(tree[i<<1], tree[(i<<1)+1]);
        }else if(c == 'W'){
            printf("%d\n",tree[1].s);
        }else{
            scanf("%d",&i);
            int cnt = 0;
            i += K;
            for(int j = i>>1; j > 0; j>>=1){
                if(tree[j] != tree[i])
                    break;
                cnt++;
            }
            printf("%d\n",cnt);
        }
    }
    return 0;
}