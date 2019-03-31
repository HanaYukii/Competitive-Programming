#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define maxn 1000005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
const ll mod=1e9+7;
typedef double Double;
struct Point {
	Double x,y;

	bool operator < (const Point &b)const{
		//return tie(x,y) < tie(b.x,b.y);
		//return atan2(y,x) < atan2(b.y,b.x);
		assert(0 && "choose compare");
	}
	Point operator + (const Point &b)const{
		return {x+b.x,y+b.y};
	}
	Point operator - (const Point &b)const{
		return {x-b.x,y-b.y};
	}
	Point operator * (const Double &d)const{
		return {d*x,d*y};
	}
	Point operator / (const Double &d)const{
		return {x/d,y/d};
	}
	Double operator * (const Point &b)const{
		return x*b.x + y*b.y;
	}
	Double operator % (const Point &b)const{
		return x*b.y - y*b.x;
	}
	friend Double abs2(const Point &p){
		return p.x*p.x + p.y*p.y;
	}
	friend Double abs(const Point &p){
		return sqrt( abs2(p) );
	}
};
typedef Point Vector;

struct Line{
	Point P; Vector v;
	bool operator < (const Line &b)const{
		return atan2(v.y,v.x) < atan2(b.v.y,b.v.x);
	}
};
Point circumcentre(Point &p0, Point &p1, Point &p2){
	Point a = p1-p0;
	Point b = p2-p0;
	Double c1 = abs2(a)*0.5;
	Double c2 = abs2(b)*0.5;
	Double d = a % b;
	Double x = p0.x + ( c1*b.y - c2*a.y ) / d;
	Double y = p0.y + ( c2*a.x - c1*b.x ) / d;
	return {x,y};
}
    
void SmallestCircle(int n, Point _p[]){
	Point *p = new Point[n];
	memcpy(p,_p,sizeof(Point)*n);
	random_shuffle(p,p+n);
	
	Double r2=0;
	Point cen;
	for (int i=0; i<n; i++){
		if ( abs2(cen-p[i]) <= r2)continue;
		cen = p[i], r2=0;
		for (int j=0; j<i; j++){
			if ( abs2(cen-p[j]) <= r2)continue;
			cen = (p[i]+p[j])*0.5;
			r2 = abs2(cen-p[i]);
			for (int k=0; k<j; k++){
				if ( abs2(cen-p[k]) <= r2)continue;
				cen = circumcentre(p[i],p[j],p[k]);
				r2 = abs2(cen-p[k]);
			}
		}
	}

	//delete[] p;
	cout <<fixed <<setprecision(10)<< cen.x <<' '<< cen.y <<' '<< sqrt(r2) <<'\n';
}
int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Point p[3];
	while(cin >> p[0].x >> p[0].y >> p[1].x >> p[1].y >>p[2].x >> p[2].y){
		SmallestCircle(3,p);
	}
}