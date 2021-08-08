#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define gc getchar()
#define pc(x) putchar(x)
template<typename T> void scan(T &x){x = 0;bool _=0;T c=gc;_=c==45;c=_?gc:c;while(c<48||c>57)c=gc;for(;c<48||c>57;c=gc);for(;c>47&&c<58;c=gc)x=(x<<3)+(x<<1)+(c&15);x=_?-x:x;}
template<typename T> void printn(T n){bool _=0;_=n<0;n=_?-n:n;char snum[65];int i=0;do{snum[i++]=n%10+48;n/= 10;}while(n);--i;if (_)pc(45);while(i>=0)pc(snum[i--]);}
template<typename First, typename ... Ints> void scan(First &arg, Ints&... rest){scan(arg);scan(rest...);}
template<typename T> void print(T n){printn(n);pc(10);}
template<typename First, typename ... Ints> void print(First arg, Ints... rest){printn(arg);pc(32);print(rest...);}

using namespace std;
const int MM = 2e4+5;

int n, t, s;
int psa[MM], dp[51][MM];
char res[51][MM];
int ls[51][MM], rs[51][MM], fail[51], oncnt;
//[k ppl pass][ends at ith case], starting point in [ls[k][i], rs[k][i])

int main(){
	scan(n, t, s);
	for(int i = 1; i <= t; i++){
		scan(psa[i]);
		psa[i] += psa[i-1];
	}
	for(int j = 0; j < n; j++){
		scanf("%s", res[j]+1);
		res[j][0] = '0';
	}
	//calculate splits...
	for(int k = 1; k <= n; k++){
		//how many ppl pass
		for(int j = 0; j < n; j++)
			fail[j] = 0;
		oncnt = n;

		for(int i = 1, l = 1; i <= t; i++){
			for(int j = 0; j < n; j++){
				if(res[j][i] == '0'){
					if(!fail[j])
						oncnt--;
					fail[j]++;
				}
			}
			while(oncnt < k){
				for(int j = 0; j < n; j++){
					if(res[j][l] == '0'){
						fail[j]--;
						if(!fail[j])
							oncnt++;
					}
				}
				l++;
			}
			rs[k-1][i] = l;
			ls[k][i] = l;
		}
	}
	for(int i = 1; i <= t; i++){
		ls[0][i] = 1;
		rs[n][i] = i+1;
	}

	memset(dp, 0x3f, sizeof dp);
	dp[0][0] = 0;

	for(int k = 1; k <= s; k++){
		//k = # of subtasks

		for(int cnt = 0; cnt <= n; cnt++){
			//# of ppl who pass

			deque<pair<int, int>> q;
			int r = 1;
			
			for(int i = 1; i <= t; i++){
				//ith test case
				while(q.size() and q.front().first < ls[cnt][i])
					q.pop_front();
				while(r < rs[cnt][i]){
					int v = dp[k-1][r-1] - cnt*psa[r-1];
					while(q.size() and v < q.back().second)
						q.pop_back();

					q.emplace_back(r, v);
					r++;
				}
				if(q.size())
					dp[k][i] = min(dp[k][i], cnt*psa[i] + q.front().second);

				// for(int j = ls[cnt][i]; j < rs[cnt][i]; j++){
					// dp[k][i] = min(dp[k][i], cnt*(psa[i] - psa[j-1]) + dp[k-1][j-1]);
				// }
				// above is naive way
			}
		}
		print(dp[k][t]);
	}
}