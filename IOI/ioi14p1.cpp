#include "rail.h"
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;

void findLocation(int n, int first, int loc[], int stype[]){
	array<int, 2> dis[n];
	dis[0] = {0, 0};
	loc[0] = first;
	stype[0] = 1;

	for(int i = 1; i < n; i++){
		dis[i] = {getDistance(0, i), i};
	}
	sort(dis, dis+n);
	auto [add, fs] = dis[1];
	int l = 0, r = fs;
	loc[fs] = first+add;
	stype[fs] = 2;
	pr("fs", fs, loc[fs]);

	set<int> lc, rd;
	lc.insert(loc[0]);
	rd.insert(loc[fs]);

	for(int j = 2; j < n; j++){
		auto [d0, i] = dis[j];
		int df = getDistance(fs, i);
		pr(j, i, d0-add, df);
		if(d0-add == df){
			//then 0->i turns at fs
			// 0 ( 1
			// ( l 0 1
			// l ) 0 1
			if(df < add){
				// first case
				loc[i] = loc[fs]-df;
				stype[i] = 1;
				continue;
			}

			// now check it's distance from l to know which case (out of last two)
			int dl = getDistance(l, i);
			int dif = (loc[fs]-loc[l] + dl - df)/2;

			if(lc.count(loc[l]+dif)){
				//it's l )
				loc[i] = loc[l]+dl;
				stype[i] = 2;
			}
			else{
				loc[i] = loc[fs]-df;
				stype[i] = 1;
				l = i;
				lc.insert(loc[i]);
			}
		}
		else{
			//it doesn't turn at fs
			// 0 1 ( r
			// 0 1 r )
			int dr = getDistance(r, i);
			int dif = (loc[r]-loc[0] + dr - d0)/2;

			if(rd.count(loc[r]-dif)){
				// 0 1 ( r
				loc[i] = loc[r]-dr;
				stype[i] = 1;
			}
			else{
				loc[i] = loc[0]+d0;
				stype[i] = 2;
				r = i;
				rd.insert(loc[i]);
			}
		}
	}
}