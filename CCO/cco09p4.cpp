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

mt19937_64 g(chrono::steady_clock::now().time_since_epoch().count());
int randint(int l, int r){return uniform_int_distribution<int>(l, r)(g);}

vector<int> ansa = {2, 1, 3}, ansb = {3, 2, 1};
int n = ansa.size();

#ifndef ONLINE_JUDGE
#define AUTO
#endif

int ask(int a, int b){
	cout<<"0 "<<a<<' '<<b<<endl;
	int x;
#ifdef AUTO
	a--, b--;
	if(ansa[a] == ansb[b])
		x = 0;
	else if(ansa[a] > ansb[b])
		x = 1;
	else
		x = -1;
	cout<<x<<endl;
	return x;
#endif
	cin>>x;
	return x;
}

void go(vector<int> &a, vector<int> &b){
	if(a.empty())
		return;
	vector<int> la, lb, ra, rb;
	int mid = a[randint(0, a.size()-1)], ok = 0;

	for(int i: b){
		int ret = ask(mid, i);
		if(ret < 0)
			lb.emplace_back(i);
		else if(ret > 0)
			rb.emplace_back(i);
		else
			ok = i;
	}

	// assert(ok);
	cout<<"1 "<<mid<<' '<<ok<<endl;

	for(int i: a){
		if(i == mid) continue;
		int ret = ask(i, ok);
		if(ret > 0)
			la.emplace_back(i);
		else if(ret < 0)
			ra.emplace_back(i);
		else
			abort();
	}
	go(la, lb);
	go(ra, rb);
}

int main(){
#ifndef AUTO
	cin>>n;
#endif
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i++){
		a[i] = b[i] = i+1;
	}
	go(a, b);
}