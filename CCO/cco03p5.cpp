#include <stdio.h>

#ifndef ONLINE_JUDGE
#include <iostream>
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using us = unsigned short;
const int MM = 65536;

bool vis[MM];
unsigned short a[MM], ans[MM];
int l = 1, r, anslen, len, bestl, bestr, bestlen;

signed main(){
	while(1){
		int b; scanf("%d", &b);
		if(!b) break;

		while(vis[b]){
			vis[a[l]] = 0;
			l = (l+1)%MM;
		}

		r = (r+1)%MM;
		if(r == bestl and bestlen > anslen){
			anslen = 0;
			for(int i = bestl; i != bestr; i = (i+1)%MM)
				ans[anslen++] = a[i];
			ans[anslen++] = a[bestr];
		}

		a[r] = b;
		vis[b] = 1;
		len = (r-l+1+MM)%MM;

		if(len > bestlen){
			bestlen = len;
			bestl = l;
			bestr = r;
		}
	}

	if(bestlen > anslen){
		anslen = 0;
		for(int i = bestl; i != bestr; i = (i+1)%MM)
			ans[anslen++] = a[i];
		ans[anslen++] = a[bestr];
	}
	for(int i = 0; i < anslen; printf("%d\n", ans[i++]));
}