#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using ll = long long;
const int MM = 2e5+5;

int n, m, k, x[MM], y[MM];
vector<int> in[MM];
vector<vector<int>> a;
vector<pair<int, vector<int>>> b;

int minn(int i){
	return x[b[i].first];
}
int maxx(int i){
	return y[b[i].first];
}
int nor(int i){
	return (int)a[i].size();
}

inline bool cmp(const pair<int, vector<int>> &va, const pair<int, vector<int>> &vb){
	return va.second[x[va.first]] < vb.second[x[vb.first]];
}

struct state{
	ll v;
	int i, j, cnt, maxr; //can not go past next at maxr
	bool operator<(const state &o) const{
		return v > o.v;
	}
};

priority_queue<state> q;
ll base;

int main(){
	scan(n, m, k);
	for(int i = 0,d,c; i < n; i++){
		scan(d, c);
		in[d-1].emplace_back(c);
	}
	for(int i = 0; i < m; i++){
		scan(x[i], y[i]);
		sort(all(in[i]));
		if((int)in[i].size() < x[i]){
			while(k--)
				print(-1);
			return 0;
		}
		for(int j = 0; j < x[i]; j++){
			base += in[i][j];
		}
		for(int j = (int)in[i].size()-1; j > 0; j--){
			in[i][j] -= in[i][j-1];
		}
		
		if((int)in[i].size() > x[i] and y[i]){
			a.emplace_back(in[i]);
			b.emplace_back(i, in[i]);
		}
	}
	sort(all(b), cmp);
	for(int i = 0; i < (int)a.size(); i++)
		a[i] = b[i].second;
	
	if(b.empty()){
		print(base);
		k--;
		while(k--)
			print(-1);
		return 0;
	}
	m = a.size();
	q.push({base, 0, minn(0)-1, 0, nor(0)}); //cnt is how many on right moved...
	while(q.size()){
		auto cur = q.top(); q.pop();
		ll curd = cur.v;
		int i = cur.i, j = cur.j, cnt = cur.cnt, maxr = cur.maxr;
		k--;
		print(curd);
		// print(curd, i, j, cnt, maxr);
		if(!k)
			return 0;
		if(j+1 < maxr){
			q.push({curd+a[i][j+1], i, j+1, cnt+!cnt, maxr}); //edge case !cnt
		}
		if(cnt < minn(i)){
			//add and keep moving
			int l = minn(i)-cnt; //new j pos
			if(l < j) //have space for next
				q.push({curd+a[i][l], i, l, cnt+1, j});
		}
		else if(cnt < maxx(i) and j > 0){
			q.push({curd+a[i][0], i, 0, cnt+1, j});
		}
		if(i+1 < m and cnt){ //not first one edge case
			int l = minn(i+1);
			//ignore this list and go to next
			if(j == minn(i) and cnt == 1){
				q.push({curd+a[i+1][l]-a[i][j], i+1, l, 1, nor(i+1)});
			}
			
			//still has stuff from this, but now in next
			q.push({curd+a[i+1][l], i+1, l, 1, nor(i+1)});
		}
	}
	while(k--)
		print(-1);
}