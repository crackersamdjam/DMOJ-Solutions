#include <bits/stdc++.h>
#define MM 100002
using namespace std;
int arr[MM],N,K,Q,a,b,x,y,l,m,r;
vector<int> occ[2002]; //occ[value] = (sorted) vector of indices
bool kys;
bool bs(int f, int x, int y){
    l = 0, r = (int)occ[f].size()-1;
    if(r < 0)
        return 0;
    while(1){
        m = (l+r)/2;
        if(occ[f][m] < x){
            if(l == r) //watch out, remember to check when l and r, not just m
                return 0;
            l = m+1;
        }else if(occ[f][m] > y){
            if(m == l)
                return 0;
            r = m;
        }else
            return 1;
    }
}
int main(){
    scanf("%d%d%d",&N,&K,&Q);
    for(int i = 1; i <= N; i++){
        scanf("%d",arr+i);
        occ[ ((arr[i] < 0) ? (arr[i]+2000) : (arr[i])) ].push_back(i);
        arr[i] += arr[i-1];
    }
    while(Q--){
        kys = 0;
        scanf("%d%d%d%d",&a,&b,&x,&y);
        if(arr[y] - arr[(x==0)?(x):(x-1)] > K){
            if(a < 0)
                a += 2000;
            if(bs(a,x,y)){
                if(b < 0)
                    b += 2000;
                if(bs(b,x,y))
                    kys = 1;
            }
        }
        printf(kys? "Yes\n": "No\n");
    }
    return 0;
}