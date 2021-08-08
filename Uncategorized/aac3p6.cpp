#ifndef LOCAL
#pragma GCC optimize("O3","unroll-loops","omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("avx2")
#endif

#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T, typename... Args> void pr(T a, Args... args){std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
int const MM = 1e6+5;

int r, c, n, m, a[MM], b[MM];
int aans[MM], bans[MM];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>r>>c;
	cin>>n>>m;

	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i < m; i++){
		cin>>b[i];
	}

	assert(is_sorted(a, a+n));
	assert(is_sorted(b, b+m));

	if(c < r){
		// for(int i = 0; i < m; i++)
			// t.insert(b[i]);
		int lim = r-c;
		int ok = 1;
		for(int i = 0; i < n; i++){
			// int cnt = (int)t.order_of_key(a[i]+lim+1)-(int)t.order_of_key(a[i]);
			// counts # in range [a[i], a[i]+lim]

			// int cnt = (int)t.order_of_key(a[i]+1)-(int)t.order_of_key(a[i]-lim);
			int cnt = lower_bound(b, b+m, a[i]+1) - lower_bound(b, b+m, a[i]-lim);

			if(cnt == lim+1){
				ok = 0;
			}
		}
		if(ok){
			for(int i = 0; i < n; i++){
				int l = 0, r = lim;
				while(l <= r){
					int k = l+r>>1;
					// int cnt = (int)t.order_of_key(a[i]+1)-(int)t.order_of_key(a[i]-k);
					int cnt = lower_bound(b, b+m, a[i]+1) - lower_bound(b, b+m, a[i]-k);

					if(cnt == k+1){
						//doesn't work
						l = k+1;
					}
					else{
						r = k-1;
						//works
					}
				}
				aans[i] = l;
			}
			cout<<r+1<<'\n';
			#ifndef STRESS
			for(int i = 0; i < n; i++){
				cout<<aans[i]<<" \n"[i==n-1];
			}
			for(int i = 0; i < m; i++){
				cout<<0<<" \n"[i==m-1];
			}
			#endif
			pr("first");
			return 0;
		}
	}
	else{
		// for(int i = 0; i < n; i++)
			// t.insert(a[i]);
		int lim = c-r;
		int ok = 1;
		for(int i = 0; i < m; i++){
			// int cnt = (int)t.order_of_key(b[i]+lim+1)-(int)t.order_of_key(b[i]);
			// counts # in range [b[i], b[i]+lim]
			// int cnt = (int)t.order_of_key(b[i]+1)-(int)t.order_of_key(b[i]-lim);
			// counts # in range [b[i]-lim, b[i]]
			int cnt = lower_bound(a, a+n, b[i]+1) - lower_bound(a, a+n, b[i]-lim);

			if(cnt == lim+1){
				ok = 0;
			}
		}
		if(ok){
			for(int i = 0; i < m; i++){
				int l = 0, r = lim;
				while(l <= r){
					int k = l+r>>1;
					// int cnt = (int)t.order_of_key(b[i]+1)-(int)t.order_of_key(b[i]-k);
					int cnt = lower_bound(a, a+n, b[i]+1) - lower_bound(a, a+n, b[i]-k);
					if(cnt == k+1){
						//doesn't work
						l = k+1;
					}
					else{
						r = k-1;
						//works
					}
				}
				bans[i] = l;
			}
			cout<<c+1<<'\n';
			#ifndef STRESS
			for(int i = 0; i < n; i++){
				cout<<0<<" \n"[i==n-1];
			}
			for(int i = 0; i < m; i++){
				cout<<bans[i]<<" \n"[i==m-1];
			}
			#endif
			pr("second");
			return 0;
		}
	}

	int ans = 0;

	for(int i = 0; i < n; i++){
		if(a[i]%2){
			aans[i] = 0;
		}
		else{
			aans[i] = 1;
		}
		ans = max(ans, 1+c+aans[i]);
	}
	for(int i = 0; i < m; i++){
		if(b[i]%2){
			bans[i] = 1;
		}
		else{
			bans[i] = 0;
		}
		ans = max(ans, 1+r+bans[i]);
	}
	assert(ans == max(r, c)+2);
	cout<<ans<<'\n';

	#ifndef STRESS	
	for(int i = 0; i < n; i++){
		cout<<aans[i]<<" \n"[i==n-1];
	}
	for(int i = 0; i < m; i++){
		cout<<bans[i]<<" \n"[i==m-1];
	}
	#endif
	pr("last");
}
/*

either delay all those from lower dimension until it works
or do parity and preserve for higher one

a and b from input are sorted (phew)

6 5
4 4
1 2 5 6 
1 2 4 5 

*/