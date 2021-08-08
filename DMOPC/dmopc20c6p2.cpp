#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifdef LOCAL
template<typename T> void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args> void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args> void pr(Args... args){}
#endif

using namespace std;
const int MM = 5e5+5;

int n, a[MM], b[MM], dif[MM];
vector<pair<int, int>> v, ans;

void no(){
	cout<<"-1\n";
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin.exceptions(cin.failbit);
	cin>>n;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	for(int i = 1; i <= n; i++){
		cin>>b[i];
		dif[i] = a[i] != b[i];
		dif[i] += dif[i-1];
	}

	if(accumulate(a, a+n+1, 0) != accumulate(b, b+n+1, 0))
		no();

	int l = 1, m = 1, r = 0, offa = 0, want = !b[1];

	int done = 0;

	while(l <= n){
		while(r < m){
			r++;
			offa += !a[r];
		}

		// pr("at", l, m, r);

		if(l == m){
			// pr("try", l);
			if(l <= done){
				// b[l] will always be 1
				if(b[l]){
					// pr("skip done");
					//move on
					offa -= 0; //no dif
					l++;
					m++;
					continue;
				}
			}
			else{
				// pr("check eq");
				if(a[l] == b[l]){
					// pr("skip");
					offa -= !a[l];
					l++;
					m++;
					want = !b[l]; 
					continue;
				}
			}
		}

		if(m == n or b[m] and !b[m+1]){
			//must take
			// pr("must", l, r, offa, want);

			if(offa > want){
				no();
			}

			while(offa != want){
				r++;
				if(r > n)
					no();
				offa += !a[r];
			}
			
			if(want){
				if(want != r-l+1){
					v.emplace_back(l, r);
				}
			}

			done = r;
			//all these are 1

			offa -= want;
			want = 0;
			m++;
			l = m;
			want = !b[m];
			// pr("norm", l, m, r, offa, want);
		}
		else{
			m++;
			want += !b[m];
		}
	}

	if(0){
		for(auto [l, r]: v){
			if(!is_sorted(a+l, a+r+1)){
				sort(a+l, a+r+1);
				ans.emplace_back(l, r);
			}
		}
		// for(int i = 1; i <= n; i++) cerr<<a[i]<<' '; cerr<<endl;
		// for(int i = 1; i <= n; i++) cerr<<b[i]<<' '; cerr<<endl;
		for(int i = 1; i <= n; i++){
			if(a[i] != b[i]){
				no();
			}
		}
	}
	else{
		for(auto [l, r]: v){
			ans.emplace_back(l, r);
		}
	}
	cout<<size(ans)<<'\n';
	#ifndef STRESS
	for(auto [l, r]: ans)
		cout<<l<<' '<<r<<'\n';
	#endif
}