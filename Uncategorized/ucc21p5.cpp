#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

bool vis[305][3][305][3];
bool dp[305][3][305][3];

bool go(int a, int b, int c, int d){
	bool &ret = dp[a][b][c][d];
	if(vis[a][b][c][d])
		return ret;
	vis[a][b][c][d] = 1;
	if(a == 1 and b == 1 and c == 1 and d == 1) return 0;

	//op1
	for(int i = 1; i < a; i++)
		ret |= !go(i, b, a-i, b);
	for(int i = 1; i < b; i++)
		ret |= !go(a, i, a, b-i);
	for(int i = 1; i < c; i++)
		ret |= !go(i, d, c-i, d);
	for(int i = 1; i < d; i++)
		ret |= !go(c, i, c, d-d);

	//op2
	for(int i = 1; i < min(11, a); i++)
		ret |= !go(a-i, b, c, d);
	for(int i = 1; i < min(11, b); i++)
		ret |= !go(a, b-i, c, d);
	for(int i = 1; i < min(11, c); i++)
		ret |= !go(a, b, c-i, d);
	for(int i = 1; i < min(11, d); i++)
		ret |= !go(a, b, c, d-i);

	return ret;
}

int main(){
	int a, b, c, d;
	cin>>a>>b>>c>>d;
	assert(a < 3 and c < 3);
	assert(a and b and c and d);
	auto res = go(b, a, d, c);
	if(res)
		cout<<'W';
	else
		cout<<'L';
}