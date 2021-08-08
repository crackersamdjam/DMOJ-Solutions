#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
using pii = pair<int, int>;
using ll = long long;
const int MM = 1005;

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

ll ans;
int n, a[MM][MM], b[MM*2];
queue<int> q;

void check(int i, int j){
	b[i] = b[j+n] = 0;
	for(int k = 0; k < n; k++){
		b[i] = max(b[i], a[i][k]);
		b[j+n] = max(b[j+n], a[k][j]);
	}
	if(b[i] != b[i+n])
		q.push(i);
	if(b[j] != b[j+n])
		q.push(j);
}

int main(){
	cin>>n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin>>a[i][j];
			b[i] = max(b[i], a[i][j]);
			b[n+j] = max(b[n+j], a[i][j]);
		}
	}
	for(int i = 0; i < n; i++){
		if(b[i] != b[i+n])
			q.push(i);
	}
	while(size(q)){
		int i = q.front(); q.pop();
		if(b[i] == b[i+n])
			continue;
		int v = min(b[i], b[i+n]);
		for(int j = 0; j < n; j++){
			if(a[i][j] > v){
				ans += a[i][j]-v;
				a[i][j] = v;
				check(i, j);
			}
			if(a[j][i] > v){
				ans += a[j][i]-v;
				a[j][i] = v;
				check(j, i);
			}
		}
	}

	cout<<ans<<'\n';
}