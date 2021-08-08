#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("sse4")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

const int MM = 7000;

int n, r;
long long a[MM], v[MM*MM/2], ans, cnt;

int main(){
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cin>>n;
	for(int i = 0; i < n; i++)
		std::cin>>a[i];
	
	std::sort(a, a+n); //this line makes code so much faster

	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			v[r++] = a[i]*a[j];
		}
	}
	v[r++] = LLONG_MAX;
	std::sort(v, v+r);
	cnt = 1;
	for(int i = 1; i < r; i++){
		if(v[i] == v[i-1])
			cnt++;
		else{
			ans += cnt*(cnt-1)/2;
			cnt = 1;
		}
	}

	for(int i = 0; i < n; i++){
		r = 0;
		for(int j = 0; j < n; j++){
			if(j != i) v[r++] = a[i]*a[j];
		}
		v[r++] = LLONG_MAX;
		std::sort(v, v+r);
		cnt = 1;
		for(int j = 1; j < r; j++){
			if(v[j] == v[j-1])
				cnt++;
			else{
				ans -= cnt*(cnt-1)/2;
				cnt = 1;
			}
		}
	}

	std::cout<<ans*8<<'\n';
}