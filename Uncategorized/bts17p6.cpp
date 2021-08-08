#include <bits/stdc++.h>
#define MM 100002
using namespace std;
int N, a[MM], b[MM], tree[MM];
unordered_map<int,int> mp;
//a is original, b in final
//mp used to map b[i] = mp[b[i]]
//b is which index of a is b b[i] = j | a[j] = b
inline void update(int i, int v){
    for(; i < MM; i += i&-i)
        tree[i] += v;
}
inline void build(){
    for(int i = 1; i < MM; i++)
        update(i, 1);
}
inline int query(int i){
    int sum = 0;
    for(; i > 0; i -= i&-i)
        sum += tree[i];
    return sum;
}
int main(){
    scanf("%d",&N);
    for(int i = 1; i <= N; i++){
        scanf("%d", a+i);
        mp[a[i]] = i;
    }
    for(int i = 1,n; i <= N; i++){
        scanf("%d", &n);
        b[i] = mp[n];
    }
    int l = 1, r = 2, ans = INT_MIN, ls, rs;
    while(r <= N){
        if(b[r] > b[r-1]){
            r++;
        }else{
            if(r - l > ans)
                ans = r-l, ls = l, rs = r-1;
            l = r;
            r++;
        }
    }
    if(r - l > ans)
        ans = r-l, ls = l, rs = r-1;

    printf("%d\n", N - ans);
    build();
    for(int i = rs+1; i <= N; i++){
        printf("B %d\n", query(b[i]));
        update(b[i], -1);
    }
    for(int i = ls-1; i > 0; i--){
        printf("F %d\n", query(b[i]));
        update(b[i], -1);
        update(1, 1);
    }
    return 0;
}