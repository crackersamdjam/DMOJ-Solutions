#include <bits/stdc++.h>
using namespace std;


int sx, sy, sz, x, y, z, nx, ny, nz, ans = 1e9, d;
char c;

inline void calc(){
    ans = min(ans, x*x + y*y + z*z);
}

int main(){
    
    cin >> sx >> sy >> sz >> x >> y >> z;
    x -= sx, y -= sy, z -= sz;
    x = -x, y = -y, z = -z;
    //reverse because now the planet is moving
    
    calc();
    
    while(1){
        cin >> d >> c;
        
        for(int i = 0; i < d; i++){
            x++;
            calc();
        }
        
        if(c == 'E')
            break;
        
        //x in front, y left, z above
        
        if(c == 'U')
            nx = z, ny = y, nz = -x;
        else if(c == 'D')
            nx = -z, ny = y, nz = x;
        else if(c == 'L')
            nx = y, ny = -x, nz = z;
        else if(c == 'R')
            nx = -y, ny = x, nz = z;
        
        x = nx, y = ny, z = nz;
    }
    
    printf("%.2lf\n", sqrt((double)ans));
    
    return 0;
}