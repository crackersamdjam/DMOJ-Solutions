#include <bits/stdc++.h>
using namespace std;
typedef pair<pair<int,int>,int> pt;
vector<pt> pts;
#define f  first
#define s second
int main() {
    for(int z = 0, n; z < 5; z++){

        scanf("%d",&n);
        int sz = 0;
        int maxx = 0, maxy = 0, maxz = 0;
        for(int j = 0,a,b,c,d,e,F,g,h,i,u,v; j < n; j++){
            scanf("%d%d%d%d%d%d%d%d%d%d%d", &a, &b,&c,&d,&e,&F,&g,&h,&i,&u,&v);
            for(int t = u; t <= v; t++){
                /*if(abs((a*pow(t, 2) + b*t + c, d*pow(t, 2)) > maxx)){
                    pts.push_back({{a*pow(t, 2) + b*t + c, d*pow(t, 2) + e*t + F}, g*pow(t, 2) + h*t + i});
                    maxx = abs((a*pow(t, 2) + b*t + c, d*pow(t, 2)));
                    sz++;
                }
                else if(abs((d*pow(t, 2) + e*t + F > maxy))){
                    pts.push_back({{a*pow(t, 2) + b*t + c, d*pow(t, 2) + e*t + F}, g*pow(t, 2) + h*t + i});
                    maxy = abs((d*pow(t, 2) + e*t + F));
                    sz++;
                }
                else if(abs((g*pow(t, 2) + h*t + i > maxz))){
                    pts.push_back({{a*pow(t, 2) + b*t + c, d*pow(t, 2) + e*t + F}, g*pow(t, 2) + h*t + i});
                    maxz = abs((g*pow(t, 2) + h*t + i));
                    sz++;
                }*/
                //pts.push_back({{a*pow(t, 2) + b*t + c, d*pow(t, 2) + e*t + F}, g*pow(t, 2) + h*t + i});
            }
            pts.push_back({{a*pow(u, 2) + b*u + c, d*pow(u, 2) + e*u + F}, g*pow(u, 2) + h*u + i});
            pts.push_back({{a*pow(v, 2) + b*v + c, d*pow(v, 2) + e*v + F}, g*pow(v, 2) + h*v + i});
            sz+=2;
            //only add relevant points
        }
        int dis = 0;
        for(int j = 0; j < sz; j++){
            for(int k = j+1, dx, dy, dz; k<sz; k++){
                dx = pts[k].f.f - pts[j].f.f;
                dy = pts[k].f.s - pts[j].f.s;
                dz = pts[k].s - pts[j].s;
                //printf("%d\n", abs(dx) + abs(dy) + abs(dz));
                //printf("%f\n", sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2)));
                //dis = max(dis, sqrt(pow(dx, 2) + pow(dy, 2) + pow(dz, 2)));
                dis = max(dis, abs(dx) + abs(dy) + abs(dz));
                //dis = max(dis, abs(dx + dy + dz));
            }
        }
        printf("%d\n", dis);
        pts.clear();
    }
    return 0;
}