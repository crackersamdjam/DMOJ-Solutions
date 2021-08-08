// S4 solution in O(N)
#include <bits/stdc++.h>
using namespace std;
constexpr int MM = 1e6+2;

int n, cnt[3][3], ans = 1e9, num[3], na, nb, nc;
char s[MM], ins[MM];
int aa[] = {0, 1, 2};

void go(){
	int tot = n-cnt[0][0]-cnt[1][1]-cnt[2][2], res = 0;
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < i; j++){
			int sub = min(cnt[i][j], cnt[j][i]);
			res += sub;
			tot -= sub*2;
		}
	}
	assert(tot % 3 == 0);
	res += tot/3*2;
	ans = min(ans, res);
}

void run(){
	memset(num, 0, sizeof num);
	memset(cnt, 0, sizeof cnt);
	for(int i = 0; i < n; i++){
		s[i] = aa[ins[i]];
		num[s[i]]++;
	}
	na = num[0], nb = num[1], nc = num[2];

	auto gp = [](int i){
		if(i < na)
			return 0;
		if(i < na+nb)
			return 1;
		return 2;
	};

	for(int i = 0; i < n; i++)
		cnt[gp(i)][s[i]]++;

	go();

	auto at = [](int i){
		i %= n;
		if(i < 0) i += n;
		return i;
	};

	for(int sh = 0; sh <= n; sh++){
		cnt[0][s[at(na-1-sh)]]--;
		cnt[1][s[at(na-1-sh)]]++;
		
		cnt[1][s[at(na+nb-1-sh)]]--;
		cnt[2][s[at(na+nb-1-sh)]]++;
		
		cnt[2][s[at(n-1-sh)]]--;
		cnt[0][s[at(n-1-sh)]]++;
		go();
	}
}

int main(){
	scanf("%s", s);
	n = strlen(s);
	for(int i = 0; i < n; i++){
		s[i] -= 'A';
		ins[i] = s[i];
	}

	do{
		run();
	} while(next_permutation(aa, aa+3));
	
	printf("%d\n", ans);
}