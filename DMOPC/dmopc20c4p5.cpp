#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 1<<21;

int n, k, a[MM];

int get(int x){
	int ret = 0;
	while(x and x%2 == 0){
		x /= 2;
		ret++;
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin>>n>>k;
	if(n == k or n%2 or (n%4 and k%2 == 0)){
		cout<<"0\n";
		return 0;
	}
	if(k%2){
		for(int i = 0; i < n; i++){
			a[i] = i%2 ? 1 : -1;
		}
	}
	else{
		for(int i = 0; i < n; i++)
			a[i] = 1;
		//"shift over" last block
		int kk = min(k, n-k);
		int l = 0;
		while(l+kk < n/2){
			a[l] = -1;
			l += kk;
		}
		//how many to shift over
		int rem = n/2-l;
		int extra = kk-rem;
		// assert(extra%2 == 0);
		int mv = extra/2;
		a[l-mv] = -1;
	}
	
	for(int i = 0; i < n; i++){
		cout<<a[i]<<" \n"[i==n-1];
	}

	if(0){
		//check answer
		cout<<flush;
		int sum = 0;
		for(int i = 0; i < n; i++){
			int b = 1;
			for(int j = 0; j < k; j++){
				b = b*a[(i+j)%n];
			}
			sum += b;
		}
		assert(!sum);
	}
}