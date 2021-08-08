#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
const int MM = 5e5+5;

int n;
int dis[MM];
queue<int> q;
int f[MM];

int main(){
	cin>>n;
	f[1] = 1;
	for(int i = 2; i <= n; i++)
		f[i] = (f[i-1]+f[i-2])%2021;

	dis[1] = 1;
	q.emplace(1);
	while(size(q)){
		int i = q.front(); q.pop();
		int a = f[i]%2021+i%50;
		if(i+a <= n and !dis[i+a]){
			dis[i+a] = dis[i]+1;
			q.emplace(i+a);
		}
		if(i-a > 0 and !dis[i-a]){
			dis[i-a] = dis[i]+1;
			q.emplace(i-a);
		}
		a = 1;
		if(i+a <= n and !dis[i+a]){
			dis[i+a] = dis[i]+1;
			q.emplace(i+a);
		}
		if(i-a > 0 and !dis[i-a]){
			dis[i-a] = dis[i]+1;
			q.emplace(i-a);
		}
	}
	cout<<dis[n]-1<<'\n';
}