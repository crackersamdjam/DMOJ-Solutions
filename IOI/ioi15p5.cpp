#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int findSwapPairs(int n, int a[], int m, int x[], int y[], int p[], int q[]){

	auto go = [&](int k, bool final = 0){
		int b[n], at[n];
		memcpy(b, a, n*sizeof(a[0]));
		for(int i = 0; i < k; i++)
			swap(b[x[i]], b[y[i]]);

		int t = 0;

		for(int i = 0; i < n; i++){
			while(b[i] != i){
				//the numbers to swap (not index)
				p[t] = b[i], q[t] = b[b[i]];
				swap(b[i], b[b[i]]);
				t++;
			}
		}

		if(t > k) return 0;

		if(final){
			assert(is_sorted(b, b+n));
		}

		//convert the numbers to indices now
		memcpy(b, a, n*sizeof(a[0]));
		for(int i = 0; i < n; i++){
			at[b[i]] = i;
		}
		for(int i = 0; i < t; i++){
			swap(at[b[x[i]]], at[b[y[i]]]);
			swap(b[x[i]], b[y[i]]);
			
			int f = p[i], s = q[i];
			p[i] = at[f], q[i] = at[s];
			assert(b[at[f]] == f);
			assert(b[at[s]] == s);
			swap(b[at[f]], b[at[s]]);
			swap(at[f], at[s]);
		}

		while(t < k){
			p[t] = q[t] = 0;
			t++;
		}

		return 1;
	};

	int l = 0, r = m-1;
	while(l <= r){
		int mid = l+r>>1;
		if(go(mid))
			r = mid-1;
		else
			l = mid+1;
	}
	assert(l >= 0 and l <= m);
	go(l, 1);
	return l;
}

#ifdef LOCAL
int main(){
	int aa[99], bb[99], ret = -2;
	if(0){
		int a[] = {4, 3, 2, 1, 0}, x[] = {0, 1, 2, 3, 0, 1}, y[] = {1, 2, 3, 4, 1, 2};
		ret = findSwapPairs(5, a, 6, x, y, aa, bb);
	}
	else{
		int a[] = {3, 0, 4, 2, 1}, x[] = {1, 4, 2, 3, 1, 0}, y[] = {1, 0, 3, 4, 4};
		ret = findSwapPairs(5, a, 5, x, y, aa, bb);
	}
	cout<<ret<<'\n';
	for(int i = 0; i < ret; i++)
		cout<<aa[i]<<' '<<bb[i]<<'\n';
}
#endif

/*
prefer shorter "swap cycles"
each of M move:
	if breaks a cycle into 2, ans++
	if joins two cycles, ans--

*/