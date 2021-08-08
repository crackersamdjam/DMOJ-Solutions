#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}
 
#define ONLINE_JUDGE

using namespace std;
using ll = long long;
using pii = pair<ll, int>;
const int MM = 1505;
 
#ifndef ONLINE_JUDGE
void allocate_tickets(vector<vector<int>> s){
	for(auto &i: s){
		for(auto j: i)
			cout<<j<<' ';
		cout<<'\n';
	}
}
#else
void allocate_tickets(vector<vector<int>> s);
#endif
 
priority_queue<pii, vector<pii>, greater<pii>> st;
int n, m, k;
vector<vector<int>> a;
int l[MM];
 
ll find_maximum(int _k, vector<vector<int>> _a){
	a = move(_a);
	n = size(a), m = size(a[0]), k = _k;
	
	for(int i = 0; i < n; i++)
		st.emplace(a[i][0]+a[i][m-k+l[i]], i);
	
	for(int tt = 0; tt < n*k/2; tt++){
		assert(size(st));
		auto i = st.top().second; st.pop();
		if(++l[i] < k)
			st.emplace(a[i][l[i]]+a[i][m-k+l[i]], i);
	}
	
	auto out = a;
	for(int i = 0; i < n; i++)
		fill(all(out[i]), -1);
	
	ll suml = 0, sumr = 0;
	int nx = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < l[i]; j++){
			suml += a[i][j];
			out[i][j] = nx;
			nx = (nx+1)%k;
		}
		int cont = nx;
		int cnt = k-l[i];
		for(int j = m-1; cnt > 0; cnt--, j--){
			sumr += a[i][j];
			out[i][j] = cont;
			cont = (cont+1)%k;
		}
	}
	allocate_tickets(out);
	return sumr-suml;
}
 
#ifndef ONLINE_JUDGE
int main(){
	int N, M, K;
	scan(N, M, K);
	vector<vector<int>> A(N);
	for(int i = 0; i < N; i++){
		A[i].resize(M);
		for(int j = 0; j < M; j++)
			scan(A[i][j]);
	}
	print(find_maximum(K, A));
	// print(find_maximum(2, {{0, 2, 5},{1, 1, 3}}));
	// print(find_maximum(1, {{5, 9}, {1, 4}, {3, 6}, {2, 7}}));
}
#endif