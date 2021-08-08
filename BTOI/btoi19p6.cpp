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
using state = pair<int, vector<vector<int>>>; //first x-1 fixed, v
using it = pair<int, state>; //val, state
priority_queue<it> q;

int n, m, k;

void fix(it &st){
	auto &v = st.second.second;
	for(int i = 0; i < m; i++){
		int mx = -1, id = 0;
		for(int j = i; j < (int)v.size(); j++){
			if(v[j][i] > mx){
				mx = v[j][i];
				id = j;
			}
			// if(v[j][i] > v[i][i])
				// swap(v[j][i], v[i][i]);
		}
		swap(v[i], v[id]);
	}
	int ret = 0;
	for(int i = 0; i < m; i++){
		int mx = 0;
		for(int j = 0; j < m; j++)
			mx = max(mx, v[j][i]);
		ret += mx;
	}
	st.first = ret;

	// for(int j = 0; j < (int)v.size(); j++){
	// 	for(int i = 0; i < m; i++)
	// 		cout<<v[j][i]<<' ';
	// 	cout<<'\n';
	// }
	// cout<<ret<<endl;
}

int main(){
	scan(n, m, k);
	it st;
	st.second.first = 0;
	st.second.second.resize(n);
	for(auto &i: st.second.second){
		i.resize(m);
		for(int &j: i)
			scan(j);
	}
	fix(st);
	q.push(st);
	while(k--){
		auto cur = q.top(); q.pop();
		if(!k){
			print(cur.first);
			return 0;
		}
		if((int)cur.second.second.size() == m)
			continue; //no more to rm
		//calc next state
		int x = cur.second.first;
		for(int j = x; j < m; j++){
			//rm the jth one
			auto nx = cur;
			nx.second.first = j;
			nx.second.second.erase(nx.second.second.begin()+j);
			fix(nx);
			q.push(nx);
		}
	}
}