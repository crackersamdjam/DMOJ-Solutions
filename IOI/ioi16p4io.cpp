#include <bits/stdc++.h>
#define all(x) (x).begin() (x).end()
using namespace std;
const int MM = 2e5+5;

int n, k, a[105];
bool on[MM][105], off[MM][105];
bool ron[MM][105], roff[MM][105];
string s;
int psa[MM], canoff[MM];
int bad[MM];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin>>s>>k;
	n = size(s);
	s = " "+s+" ";
	for(int i = 1; i <= n+1; i++){
		bad[i] = bad[i-1] + (s[i] == '_');
	}

	for(int i = 1; i <= k; i++)
		cin>>a[i];

	off[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			if(s[i] != '_'){
				if(j and i >= a[j] and (bad[i] == bad[i-a[j]])) on[i][j] = off[i-a[j]][j-1];
			}
			if(s[i] != 'X'){
				off[i][j] = off[i-1][j] | on[i-1][j];
			}
		}
	}

	roff[n+1][k+1] = 1;
	for(int i = n; i > 0; i--){
		for(int j = k+1; j > 0; j--){
			if(s[i] != '_'){
				if(j <= k and i+a[j] <= n+1 and (bad[i-1] == bad[i+a[j]-1])) ron[i][j] = roff[i+a[j]][j+1];
			}
			if(s[i] != 'X'){
				roff[i][j] = roff[i+1][j] | ron[i+1][j];
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= k; j++){
			if(off[i][j] and (roff[i+1][j+1] or ron[i+1][j+1])){
				canoff[i] = 1;
			}
			if(on[i][j] and roff[i+1][j+1]){
				psa[i-a[j]+1]++;
				psa[i+1]--;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		psa[i] += psa[i-1];
		if(psa[i]){
			if(canoff[i])
				cout<<'?';
			else
				cout<<'X';
		}
		else{
			assert(canoff[i]);
			cout<<'_';
		}
	}
	cout<<'\n';
}