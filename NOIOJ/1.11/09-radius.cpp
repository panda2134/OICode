//THIS VERSION DOES NOT WORK:YOU MUST BISEARCH THE ANGLE INSTEAD OF THE RADIUS,BECAUSE OF THE F**KING EPS.
//TODO:WRITE ANOTHER VERSION THAT WORKS...
#include <cstdio>
#include <cmath>
const double EPS=1e-12;
using namespace std;
double l,l_arc,n,c;
inline bool equal(double a,double b){
	return abs(a-b)<=EPS;
}
inline bool chk(double r){
	double l_arc_d=2.0*asin((l/2)/r)*r;
	return l_arc_d<l_arc || equal(l_arc_d,l_arc);
}
double bisearch(double i,double j){
	double m=(i+j)/2;
	if(equal(i,j))
		return i;
	if(chk(m))//<=
		return bisearch(i,m);
	else//>
		return bisearch(m+EPS,j);
	/*while(!equal(i,j)){
		
		double m=(i+j)/2;
		if(chk(m))
			j=m;
		else
			i=m+EPS;
	}
	return i;*/
}
int main(){
	scanf("%lf%lf%lf",&l,&n,&c);
	l_arc=(1+n*c)*l;
	double r=bisearch(0,1e14);
	printf("r=%lf\n",r);
	double h=sqrt(r*r-(l/2)*(l/2));
	double ans=r-h;
	printf("%.3lf",ans);
	return 0;
}
