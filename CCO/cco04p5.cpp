#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;

int n;

int on[500][3];

int main(){
	for(int i = 1; i <= 18; i++)
		on[i][0] = on[i][1] = on[i][2] = 1;

	scanf("%d", &n);
	while(n--){
		int a, c; char b, d;
		scanf("%d%c %d%c", &a, &b, &c, &d);
		b -= 'A', d -= 'A';
		on[a][b] = 0;
		on[c][d] = 1;
		if(!on[a][1] and accumulate(on[a], on[a]+3, 0) < 2){
			printf("The tower collapses after removing %d%c", a, b+'A');
			return 0;
		}
	}
	printf("The tower never collapses\n");
}