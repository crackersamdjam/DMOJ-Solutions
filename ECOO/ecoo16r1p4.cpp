#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll X, Y, a[101], b[101];
char t[101];
int tc = 10, D, R, MM = 100;

int main(){
    
    
    
    while(tc--){
        
        D = 0, R = 0;
        cin >> X >> Y;
        
        for(int i = 0; i < MM; i++){
            cin >> a[i] >> b[i] >> t[i];
        }
        
        for(int i = -250; i <= 250; i++){
            for(int j = -250; j <= 250; j++){
                
                bool flag = 0;
                for(int k = 0; k < MM; k++){
                    if(a[k] == i and b[k] == j){
                        flag = 1;
                        break;
                    }
                }
                if(flag)
                    continue;
                
                ll dis = (X-i)*(X-i)+(Y-j)*(Y-j);
                
                
                if(dis > 50*50)
                    continue;
                
                //cout << i << " " << j << '\n';
                //consider this point
                
                ll d1 = 1e9, d2 = 1e9, d3 = 1e9;
                
                for(int k = 0; k < MM; k++){
                    ll dis = (a[k]-i)*(a[k]-i)+(b[k]-j)*(b[k]-j);
                    
                    if(dis < d1){
                        d3 = d2;
                        d2 = d1;
                        d1 = dis;
                    }
                    else if(dis < d2){
                        d3 = d2;
                        d2 = dis;
                    }
                    else if(dis < d3){
                        d3 = dis;
                    }
                }
                
                int cntd = 0, cntr = 0;
                
                for(int k = 0; k < MM; k++){
                    ll dis = (a[k] - i) * (a[k] - i) + (b[k] - j) * (b[k] - j);
                    if(dis <= d3){
                        
                        if(t[k] == 'D')
                            cntd++;
                        else
                            cntr++;
                    }
                }
                
                //printf("%d %d\n", cntd, cntr);
                
                if(cntd >= cntr)
                    D++;
                else
                    R++;
            }
        }
        
        //printf("%d %d\n", D, R);
        printf("%.1lf\n", ((1.0*D)/(1.0*(D+R)))*100 );
    }
    
    return 0;
}