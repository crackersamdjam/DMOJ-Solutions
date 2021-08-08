#include <bits/stdc++.h>
#define MM 1000002
#define f first
#define s second
#define ps push_back
using namespace std;
int N;
struct ethan{
    int val, cn, ind;
};
map<int,int> mp; // ind, channel
vector<ethan> c;
bool cmp(ethan ez, ethan ey){
    return ez.val < ey.val;
}
int main(){
    scanf("%d",&N);
    for(int i = 1,z; i <= N; i++){
        scanf("%d",&z); c.ps({z, 1, i});
    }
    for(int i = 1,z; i <= N; i++){
        scanf("%d",&z); c.ps({z, 2, i});
    }
    sort(c.begin(), c.end(), cmp);
    mp[0] = 2, mp[N+1] = 2;

    for(int i = 0, j = 0; i <= N; i++){ //number of switches
        for(; j < c.size();){ //order

            int v = c[j].val, t = c[j].ind, ch = c[j].cn; j++;

            if(mp.count(t)){
                for(; i <= N; i++)
                    printf("%d\n",v);
                return 0;
                //if been to index already, nothing else can be done to increase min
            }
            auto it = mp.upper_bound(t);
            auto nx = *it, left = *(--it);

            if(ch != left.s && ch != nx.s){
                printf("%d\n", v);
                if(nx.f == N+1)
                    mp[N+1] = ch;
                else{
                    printf("%d\n", v);
                    i++;
                }
                mp[t] = ch;
                break;
            }else
                mp[t] = ch;
        }
    }
    return 0;
}