#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
#include "grader.c"
#endif

using namespace std;

void exploreCave(int n){
	int flip[n], ans[n];
	int t[n], tt[n];
	fill_n(ans, n, -1);
	fill_n(t, n, 0);

	for(int i = 0; i < n; i++){

		for(int j = 0; j < n; j++){
			if(ans[j] == -1)
				t[j] = 0;
		}

		int f = 0;
		int ret = tryCombination(t);
		if(ret == -1 or ret > i){
			f = 1;
			for(int j = 0; j < n; j++){
				if(ans[j] == -1)
					t[j] ^= 1;
			}
		}

		int id = 0;
		for(int j = 1; j < n; j *= 2){
			memcpy(tt, t, sizeof t);

			for(int k = 0; k < n; k++){
				if((k&j) and ans[k] == -1){
					tt[k] ^= 1;
				}
			}
			ret = tryCombination(tt);
			if(ret == -1 or ret > i){
				id |= j;
			}
		}
		ans[id] = i;
		flip[id] = !f;
		t[id] = !f;
	}
	answer(flip, ans);
}