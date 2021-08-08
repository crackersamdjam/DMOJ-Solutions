#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
using ld = double;
const int MM = 1e5+5;

vector<int> sort_cyclic_shifts(string const& s, const int alphabet){
	int n = s.size();
	vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
	for(int i = 0; i < n; i++)
		cnt[s[i]]++;
	for(int i = 1; i < alphabet; i++)
		cnt[i] += cnt[i-1];
	for(int i = 0; i < n; i++)
		p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for(int i = 1; i < n; i++){
		if(s[p[i]] != s[p[i-1]])
			classes++;
		c[p[i]] = classes-1;
	}
	vector<int> pn(n), cn(n);
	for(int h = 0; (1<<h) < n; h++){
		for(int i = 0; i < n; i++){
			pn[i] = p[i] - (1<<h);
			if(pn[i] < 0)
				pn[i] += n;
		}
		fill(cnt.begin(), cnt.begin()+classes, 0);
		for(int i = 0; i < n; i++)
			cnt[c[pn[i]]]++;
		for(int i = 1; i < classes; i++)
			cnt[i] += cnt[i-1];
		for(int i = n-1; i >= 0; i--)
			p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		for(int i = 1; i < n; i++){
			pair<int, int> cur = {c[p[i]], c[(p[i] + (1<<h)) % n]};
			pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1<<h)) % n]};
			if(cur != prev)
				classes++;
			cn[p[i]] = classes-1;
		}
		c.swap(cn);
	}
	return p;
}

vector<int> suffix_array_construction(string s, const int alphabet = 256){
	s += "$";
	vector<int> sorted_shifts = sort_cyclic_shifts(s, alphabet);
	sorted_shifts.erase(sorted_shifts.begin());
	return sorted_shifts;
}

vector<int> lcp_construction(string const& s, vector<int> const& p){
    int n = s.size();
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
        rank[p[i]] = i;

    int k = 0;
    vector<int> lcp(n-1, 0);
    for(int i = 0; i < n; i++){
        if(rank[i] == n-1){
            k = 0;
            continue;
        }
        int j = p[rank[i] + 1];
        while(i+k < n and j+k < n and s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
        if(k)
            k--;
    }
    return lcp;
}

int tc, tt, n, m, k, w, x, y, z;
string s;
ll dp[MM];

int main(){
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin>>tc;
	cout<<fixed<<setprecision(3);
	while(tc--){
		tt++;
		cin>>k>>m>>w>>x>>y>>z;
		cin>>s;
		n = size(s);
		for(int i = 0; i < n; i++)
			dp[i] = LLONG_MAX/3;
		dp[0] = -w;

		while(k--){
			int a, b;
			cin>>a>>b;
			for(int i = b; i < n; i++)
				dp[i] = min(dp[i], dp[i-b]+a+w);
		}

		auto v = suffix_array_construction(s, 128);
		auto lcp = lcp_construction(s, v);
		vector<vector<int>> add(n);
		for(int i = 0; i < size(lcp); i++)
			add[lcp[i]].emplace_back(i);

		vector<ld> ans;
		//if i in st, then i and i+1 have lcp <= len
		set<int> st;
		st.insert(-1);
		st.insert((int)size(lcp));

		multiset<ll> ins;
		ins.insert((ll)n*(n-1));
		// options to take

		for(int len = 0; len < n; len++){

			if(len){
				int t = m;
				for(auto it = ins.rbegin(); it != ins.rend(); it++){ 
					if(!t--)
						break;

					ll tot = (ll)(n-len+1)*(n-len);
					ld p = (ld)*it/tot;
					ll sq = n - abs(x-len);
					ll v = y*sq*sq+z;
					ld all = p*v-dp[len];
					ans.emplace_back(all);
				}
			}

			for(auto i: add[len]){
				auto it = st.lower_bound(i);
				auto pre = it;
				pre--;
				ll d = *it-*pre;
				ins.erase(ins.lower_bound(d*(d-1)));

				d = i-*pre;
				ins.insert(d*(d-1));

				d = *it-i;
				ins.insert(d*(d-1));

				st.insert(i);
			}
		}
		sort(all(ans), greater<ld>());
		ll none = -*min_element(dp+1, dp+n);
		while(size(ans) < m)
			ans.emplace_back(none);
		
		// cout<<"Case #"<<tt<<": ";
		for(int i = 0; i < m; i++)
			cout<<max((ld)none, ans[i])<<' ';
		cout<<'\n';

	}
}
/*
Two moves are distinct if they involve purchasing different sequences of letters – the deal(s) used are ignored

https://www.facebook.com/codingcompetitions/hacker-cup/2014/final-round/problems/C

*/