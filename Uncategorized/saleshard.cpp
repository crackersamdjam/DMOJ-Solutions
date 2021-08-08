// allen's sol to the original problem. should tle
// loops through all in range [l, r]
// make query ranges larger to kill this

#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
template<typename T>
int sz(const T &a){return int(a.size());}
const int MN=3e5+5;
pii arr[MN];
int dp[51];
vector<pii> cards[51];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int b,n,d;
    cin>>b>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>arr[i].first>>arr[i].second;
        cards[arr[i].first].push_back({arr[i].second,i});
    }
    for(int i=1;i<=b;i++)sort(cards[i].begin(),cards[i].end(),greater<>());
    int cardnum,x,y,newprice;
    while(d--){
        cin>>cardnum>>newprice>>x>>y;
        cards[arr[cardnum].first].erase(find(cards[arr[cardnum].first].begin(),cards[arr[cardnum].first].end(),pii{arr[cardnum].second,cardnum}));
        arr[cardnum].first=newprice;
        int it=0;
        while(it<sz(cards[newprice])&&cards[newprice][it]>pii{arr[cardnum].second,cardnum})it++;
        cards[newprice].insert(cards[newprice].begin()+it,{arr[cardnum].second,cardnum});
        for(int i=0;i<=b;i++)dp[i]=0;
        for(int i=1;i<=b;i++){
            vector<int> touse;
            for(auto cur:cards[i])if(cur.second>=x&&cur.second<=y)touse.push_back(cur.first);
            for(int j=b;j>=0;j--){
                int sum=0,am=0;
                for(auto cur:touse) {
                    sum+=cur;
                    am+=i;
                    if(am>j)break;
                    dp[j] = max(dp[j],dp[j-am]+sum);
                }
            }
        }
        printf("%d\n",*max_element(dp,dp+b+1));
    }
    return 0;
}