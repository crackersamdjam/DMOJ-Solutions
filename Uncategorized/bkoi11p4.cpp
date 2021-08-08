#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=char(n%10+48);n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

// #define ONLINE_JUDGE
// #define DEBUG

#ifdef DEBUG
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;
const int MM = 4096;


#ifndef ONLINE_JUDGE
int A[10240];
void bit_set(int x){
	A[x] = 1;
}
int bit_get(int x){
	return  A[x];
}
#endif

void remember(int a){
	vector<int> v;
	for(int i = 0; i < 6; i++){
		v.push_back(a%4+1);
		a /= 4;
	}
	reverse(all(v));
	int rt = 0;
	for(int i = 0; i < 6; i++){
		// cout<<v[i]<<' ';
		rt = rt*4+v[i];
		bit_set(rt);
	}
	// cout<<endl;
}
int compare(int b){
	vector<int> v;
	for(int i = 0; i < 6; i++){
		v.push_back(b%4+1);
		b /= 4;
		// cout<<v.back()<<' ';
	}
	// cout<<endl;
	reverse(all(v));
	vector<int> id(6);
	int rt = 0;
	for(int i = 0; i < 6; i++){
		rt = rt*4+v[i];
		id[i] = rt;
		// cout<<v[i]<<' ';
	}
	// cout<<endl;
	int l = 0, m, r = 5;
	while(l <= r){
		m = (l+r)/2;
		int res = bit_get(id[m]);
		if(res)
			l = m+1;
		else
			r = m-1;
	}
	//l is first bit where different
	if(l == 6)
		return 0;
	pr("l", l, v[l]);
	//4 cases
	if(v[l] == 1)
		return -1;
	if(v[l] == 4)
		return 1;
	if(v[l] == 2){
		int t = bit_get(id[l]-1);
		return t ? 1 : -1;
	}
	else{
		int t = bit_get(id[l]+1);
		pr("t", t);
		return t ? -1 : 1;
	}
}

#ifndef ONLINE_JUDGE
int main(){
	remember(5);
	for(int i = 1; i < 10; i++){
		print(i, compare(i));
	}
}
#endif