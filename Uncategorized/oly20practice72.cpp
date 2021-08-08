#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar_unlocked()
#define pc(x) putchar_unlocked(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
using help = vector<vector<int>>;
using state = pair<int, help>; //int fixes taken
// all = {{each vector} {} {}}

int n, m, c;

void best(help &v){
	for(int j = 0; j < m; j++){
		int mx = -1, id = 0;
		for(int i = j; i < v.size(); i++){ //do not reuse taken ones
			if(v[i][j] > mx){
				mx = v[i][j];
				id = i;
			}
		}
		swap(v[j], v[id]);
		//bring to front (j is at front after prev ones)
	}
}

int val(const help &v){
	int ret = 0;
	for(int j = 0; j < m; j++){
		int mx = 0;
		for(int i = 0; i < m; i++){
			mx = max(mx, v[i][j]);
		}
		ret += mx;
	}
	return ret;
}

struct cmp{
	bool operator()(const state &lhs, const state &rhs){
		return val(lhs.second) < val(rhs.second);
	}
};
priority_queue<state, vector<state>, cmp> q;

int main(){
	scan(n, m, c);
	help in(n);
	for(int i = 0; i < n; i++){
		in[i].resize(m);
		for(int j = 0; j < m; j++)
			scan(in[i][j]);
	}
	best(in);
	
	q.emplace(0, in);
	c--;
	while(c--){
		auto cur = q.top().second; int fx = q.top().first; q.pop();
		
		if(cur.size() == m)
			continue; //can not keep removing
		
		// up to nf-1 fixed and nf is removed
		for(int nf = fx; nf < m; nf++){
			auto nx = cur;
			nx.erase(nx.begin()+nf);
			best(nx);
			q.emplace(nf, nx);
		}
	}
	
	print(val(q.top().second));
	
	return 0;
}