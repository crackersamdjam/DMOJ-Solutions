#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
using pii = pair<short, short>;
constexpr int MM = 3e4+1;

int b, n, d;

struct SegmentTree{
	pii tree[MM*2];

	pii query(int l, int r){
		pii ret = {0, 0};
	    for(l += n, r += n+1; l < r; l >>= 1, r >>= 1){
	        if(l&1)
	            ret = max(ret, tree[l++]);
	        if(r&1)
	            ret = max(ret, tree[--r]);
	    }
	    return ret;
	}

	void update(int i, int v){
	    tree[i += n] = {v, i};
	    for(i >>= 1; i > 0; i >>= 1){
	    	tree[i] = max(tree[i<<1], tree[i<<1|1]);
	    }
	}
} best[51];

short c[30001], v[30001];
int dp[51];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>b>>n>>d;
	for(int i = 1; i <= n; i++){
		cin>>c[i]>>v[i];
		best[c[i]].update(i, v[i]);
	}
	for(int z = 1; z <= d; z++){
		int i, cc, x, y;
		cin>>i>>cc>>x>>y;
		best[c[i]].update(i, 0);
		c[i] = cc;
		best[c[i]].update(i, v[i]);

		// pr("day", z);

		memset(dp, 0, sizeof dp);

		for(int k = 1; k <= b; k++){
			int rem = b/k;
			// pr("k", k, rem);

			using stt = tuple<pair<int, int>, int, int>;
			priority_queue<stt> q;
			q.push({best[k].query(x, y), x, y});
			while(size(q) and rem--){
				auto [p, l, r] = q.top(); q.pop();
				int m = p.second;
				if(!m) break;
				// pr(k, p.first, p.second, ",", l, r);
				for(int j = b; j >= k; j--)
					dp[j] = max(dp[j], dp[j-k]+p.first);
				
				q.push({best[k].query(l, m-1), l, m-1});
				q.push({best[k].query(m+1, r), m+1, r});
			}
		}
		cout<<dp[b]<<'\n';
	}
}