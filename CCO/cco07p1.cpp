//#include "../content/geometry/polygon.h"
//#include "../content/geometry/convex_hull.h"
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

#ifndef ONLINE_JUDGE
template<typename T>
void pr(T a){std::cerr<<a<<std::endl;}
template<typename T,typename... Args>
void pr(T a, Args... args) {std::cerr<<a<<' ',pr(args...);}
#else
template<typename... Args>
void pr(Args... args){}
#endif

using namespace std;

//using T = long double; constexpr T eps = 1e-9;
using T = long long; constexpr T eps = 0;
// all numbers that can be represented by long long can also be
// accurately represented by long double, it's just slower

using pt = complex<T>;
#define x real()
#define y imag()

namespace std{
	bool operator<(const pt &a, const pt &b){
		return a.x < b.x or (a.x-eps <= b.x and a.y < b.y-eps);}
	bool operator==(const pt &a, const pt &b){
		return !(a < b) and !(b < a); }
	bool operator<=(const pt &a, const pt &b){
		return !(b < a);}
}
T dot(pt a, pt b){ return a.x*b.x + a.y*b.y;}
T norm(pt a){ return dot(a, a); } // norm is distance squared. Don't use std::norm because of inaccuracy
T cross(pt a, pt b){ return a.x*b.y - a.y*b.x;} // right hand rule: a-index, b-middle, cross-thumb. Result is > 0 if ccw, < 0 if cw, 0 if collinear.
T ccw(pt origin, pt a, pt b){ return cross(a-origin, b-origin);}

pt intersect(pt a1, pt a2, pt b1, pt b2){
	// lines a1-a2 and b1-b2
	pt d1 = a2-a1, d2 = b2-b1;
	return a1 + cross(b1-a1, d2)/cross(d1, d2) * d1;
}

// make this look nicer (and easier to code up)
bool has_intersect(pt a1, pt a2, pt b1, pt b2){
	if(max(a1.x, a2.x) >= min(b1.x, b2.x) && max(b1.x, b2.x) >= min(a1.x, a2.x) &&
	   max(a1.y, a2.y) >= min(b1.y, b2.y) && max(b1.y, b2.y) >= min(a1.y, a2.y)
	   && ccw(a1, a2, b1) * ccw(a1, a2, b2) <= 0
	   && ccw(b1, b2, a1) * ccw(b1, b2, a2) <= 0)
		return 1;
	return 0;
}

istream &operator >> (istream &stream, pt &p){
	T X, Y; stream>>X>>Y; p = pt(X, Y); return stream;}
ostream &operator << (ostream &stream, const pt &p){
	return stream<<p.x<<' '<<p.y;}

T getarea(vector<pt> v){
	T a = 0;
	for(int i = 2; i < size(v); i++)
		a += ccw(v[0], v[i-1], v[i]);
	return a;
}

vector<pt> convex_hull(vector<pt> pts){
	sort(all(pts));
	vector<pt> hull;
	for(int h = 0; h < 2; h++){
		int last = size(hull);
		for(int i = 0; i < size(pts); i++){
			while(size(hull) >= last+2 and ccw(*(hull.end()-2), pts[i], hull.back()) >= 0)
				hull.pop_back();
			hull.push_back(pts[i]);
		}
		hull.pop_back();
		reverse(all(pts));
	}
	if(size(hull) == 2 and hull[0] == hull[1])
		hull.pop_back();
	if(!size(hull) and size(pts))
		hull.push_back(pts[0]);
	return hull;
}

int main(){
	#ifdef CLION
	freopen("../testing/in", "r", stdin);
	#endif
	int n; cin>>n;
	vector<pt> v(n);
	for(auto &i: v){
		cin>>i;
	}
	v = convex_hull(v);
	auto a = getarea(v);
	cout<<a/100<<'\n';
}