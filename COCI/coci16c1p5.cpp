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
const int MM = 5e5+5;

int n, a[MM], b[MM], c[MM], psa[MM], ans;
vector<int> in[MM];

int main(){
	scan(n);
	for(int i = 0; i < n; i++)
		scan(a[i]);
	for(int i = 0; i < n; i++)
		scan(b[i]);
	for(int i = 0; i < n; i++){
		scan(c[i]);
		in[a[i]-1].emplace_back(c[i]);
	}

	int l = 0;
	for(int i = 0; i < n; i++){
		psa[i] = (int)size(in[i])-1;
		if(i) psa[i] += psa[i-1];
		if(psa[i] < psa[l])
			l = i;
	}

	while(psa[(l+1)%n] == psa[l] and l != n-1)
		l = (l+1)%n;
	l = (l+1)%n;

	set<int> st;
	bool done = 0;
	for(int i = l; !done or i != l; i = (i+1)%n){
		done = 1;
		for(int j: in[i])
			st.insert(j);
		
		auto it = st.upper_bound(b[i]);
		if(it != st.end()){
			st.erase(it);
			ans++;
		}
		else{
			// assert(size(st));
			st.erase(st.begin());
		}
	}
	print(ans);
}