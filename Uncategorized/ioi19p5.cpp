#ifndef CLION
#ifndef ONLINE_JUDGE
#define ONLINE_JUDGE
#endif
#endif

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
template<typename T>
void print(T a){std::cout<<a<<std::endl;}
template<typename T,typename... Args>
void print(T a, Args... args) {std::cout<<a<<' ',print(args...);}
#else
#include "vision.h"
template<typename... Args>
void print(Args... args){}
#endif

#ifndef ONLINE_JUDGE
int LIM =  10000;
vector<int> all;
int eval(int i){
	return all[i];
}
int add_and(std::vector<int> Ns){
	assert(all.size() < LIM);
	assert(Ns.size());
	int ret = 1;
	for(int i: Ns){
		assert(i >= 0 and i < all.size());
		ret &= all[i];
	}
	if(Ns.empty())
		ret = 0;
	all.emplace_back(ret);
	return all.size()-1;
}
int add_or(std::vector<int> Ns){
	assert(all.size() < LIM);
	assert(Ns.size());
	int ret = 0;
	for(int i: Ns){
		assert(i >= 0 and i < all.size());
		ret |= all[i];
	}
	all.emplace_back(ret);
	return all.size()-1;
}
int add_xor(std::vector<int> Ns){
	assert(all.size() < LIM);
	assert(Ns.size());
	int ret = 0;
	for(int i: Ns){
		assert(i >= 0 and i < all.size());
		ret ^= all[i];
	}
	all.emplace_back(ret);
	return all.size()-1;
}
int add_not(int N){
	assert(all.size() < LIM);
	assert(N >= 0 and N < all.size());
	all.emplace_back(!all[N]);
	return all.size()-1;
}
#else
int eval(int i){
	return 0;
}
#endif

const int MM = 600;

int n, m, mx, zero;
int prea[MM], pre2a[MM], sufa[MM], suf2a[MM];
int *pre = prea+1, *pre2 = pre2a+1, *suf = sufa+1, *suf2 = suf2a+1;

bool ok(int i, int j){ return i >= 0 and i < n and j >= 0 and j < m; }
int at(int i, int j){ return i*m+j; }

int go(int k){
	//if dist >= k
	vector<int> ret = {zero};
	print("**********");
	print("try", k);
	
	for(int i = -1; i <= mx; i++){
		if(!suf[i+k])
			break;
		ret.push_back(add_and({pre[i], suf[i+k]}));
		//both are 1 means that points are >= k apart
		print("or", i, i+k, eval(ret.back()));
	}
	
	for(int i = -1; i <= mx; i++){
		if(!suf2[i+k])
			break;
		ret.push_back(add_and({pre2[i], suf2[i+k]}));
		print("or2", i, i+k, eval(ret.back()));
	}
	
	//returns if outside
	return add_or(ret);
}

void construct_network(int _n, int _m, int k){
	n = _n, m = _m;
	if(n*m == 2){
		//edge case where I can not get "zero"
		if(k == 1){
			add_or({0, 1});
			return; //[2] is 1
		}
		
		add_not(1); //[2] is 0
		return;
	}
	
	zero = add_and({0, 1, 2}); //must be 0
	
	mx = n+m+5;
	
	pre[-1] = zero;
	suf[mx+1] = zero;
	
	for(int i = 0; i <= mx; i++){
		vector<int> v = {pre[i-1]};
		print("in", i);
		for(int j = 0; j <= n+m; j++){
			if(ok(j, i-j)){
				print(j, i-j, "-", eval(at(j, i-j)));
				v.push_back(at(j, i-j));
			}
		}
		pre[i] = add_or(v);
		print("pre ", eval(pre[i]));
	}
	
	for(int i = mx; i >= 0; i--){
		vector<int> v = {suf[i+1]};
		print("in", i);
		for(int j = 0; j <= n+m; j++){
			if(ok(j, i-j)){
				print(j, i-j, "-", eval(at(j, i-j)));
				v.push_back(at(j, i-j));
			}
		}
		suf[i] = add_or(v);
		print("suf ", eval(suf[i]));
	}
	
	pre2[-1] = zero;
	suf2[mx+1] = zero;
	
	for(int i = 0; i <= mx; i++){
		vector<int> v = {pre2[i-1]};
		print("in2", i);
		for(int j = 0; j <= n+m; j++){
			if(ok(j, m-1-i+j)){
				print(j, m-1-i+j, "-", eval(at(j, m-1-i+j)));
				v.push_back(at(j, m-1-i+j));
			}
		}
		pre2[i] = add_or(v);
		print("pre ", eval(pre2[i]));
	}
	for(int i = mx; i >= 0; i--){
		vector<int> v = {suf2[i+1]};
		print("in2", i);
		for(int j = 0; j <= n+m; j++){
			if(ok(j, m-1-i+j)){
				print(j, m-1-i+j, "-", eval(at(j, m-1-i+j)));
				v.push_back(at(j, m-1-i+j));
			}
		}
		suf2[i] = add_or(v);
		print("suf ", eval(suf2[i]));
	}
	
	int hi = go(k+1); // if k+1 (does not) work
	int lo = go(k); // if k works
	
	int ret = add_and({add_not(hi), lo});
	print("ans", eval(hi), eval(lo), eval(ret));
}

#ifndef ONLINE_JUDGE
//int main(){
//	all = {0, 0, 0, 0, 1, 0, 0, 0, 1};
//	construct_network(3, 3, 2);
//	cout<<all.back()<<endl;
//}

mt19937 g;
int randint(int l, int r){ return uniform_int_distribution<int>(l, r)(g); }
int main(int argc, char *args[]){
//	freopen("../in", "w", stdout);
	int sd = argc > 1 ? atoi(args[1]) : 0;

//	sd = 2;

	g = mt19937(sd);
	int N = randint(1, 3), M = randint(1, 3);
	if(N+M == 2)
		M++;
	int K = randint(1, N+M-2);

	all.resize(N*M);

	int AX = randint(0, N-1), AY = randint(0, M-1);
	int BX, BY;
	do{
		BX = randint(0, N-1), BY = randint(0, M-1);
	} while(BX == AX and BY == AY);

	all[AX*M+AY] = all[BX*M+BY] = 1;

	cout<<N<<' '<<M<<' '<<K<<endl;
	cout<<AX<<' '<<AY<<endl;
	cout<<BX<<' '<<BY<<endl;
	cout<<"Reeeeee "<<AX*M+AY<<' '<<BX*M+BY<<endl;

	int DIST = abs(AX-BX) + abs(AY-BY);
	int ANS = DIST==K;
	construct_network(N, M, K);
	cout<<all.back()<<' '<<ANS<<endl;
	assert(all.back() == ANS);
}
#endif