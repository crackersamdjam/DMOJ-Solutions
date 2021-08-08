#include <bits/stdc++.h>
#define MM 1000002
#define f first
#define s second
using namespace std;
typedef pair<int,int> pii;
struct qry{
    int l,r,o;
}q[MM];
int arr[MM],tree[MM],out[MM],N,Q,ptr;
stack<pii> st;
inline void update(int ind, int val){
    for(int i = ind; i < MM; i += i&-i){
        tree[i] += val;
    }
}
inline int query(int ind){
    int sum = 0;
    for(int i = ind; i > 0; i -= i&-i){
        sum += tree[i];
    }
    return sum;
}
inline bool cmp(qry a, qry b){
    return a.l < b.l;
}
int main(){
    scanf("%d%d",&N,&Q);
    for(int i = 1; i <= N; i++)
        scanf("%d",arr+i);
    for(int i = 1; i <= Q; i++){
        scanf("%d%d",&q[i].l,&q[i].r);
        q[i].o = i;
    }
    sort(q+1,q+Q+1,cmp); //store order of queries
    ptr = N;
    for(int i = Q; i > 0; i--){
        while(ptr > 0 && ptr >= q[i].l){
            while(!st.empty() && arr[ptr] >= st.top().f){
                pii tp = st.top(); st.pop();
                update(tp.s,-1); //remove one
            }
            st.push({arr[ptr],ptr});
            update(ptr,1); //add one
            ptr--;
        }
        out[ q[i].o ] = query( q[i].r );
    }
    for(int i = 1; i <= Q; i++){
        printf("%d\n",out[i]);
    }
    return 0;
}