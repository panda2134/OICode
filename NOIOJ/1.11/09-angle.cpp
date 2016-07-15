#include <cstdio>
#include <cmath>
using namespace std;
const double EPS=1e-10;
double l,l_arc,n,c;
inline bool equals(double a,double b) {
	return abs(a-b)<=EPS;
}
inline bool chk(double x) {
	double sinAngle=sin(x*M_PI/180.0);
	double r=(l/2)/sinAngle;
	double l_arc_tmp=2*x*M_PI*r/180.0;
	return l_arc_tmp>=l_arc;
}
double bisearch(double i,double j) {
	if(equals(i,j))
		return i;
	double m=(i+j)/2;
	if(chk(m))//>=
		return bisearch(i,m);
	else
		return bisearch(m,j);
}
int main() {
	scanf("%lf%lf%lf",&l,&n,&c);
	l_arc=(1+n*c)*l;
	if(l*n*c<=EPS){
		printf("0.000\n");
		//return 0;
	}
	double angle=bisearch(0.0,90.0);
	double sinAngle=sin(angle*M_PI/180.0);
	double r=(l/2)/sinAngle;
	double x=sqrt(r*r-(l/2)*(l/2));
	double h=r-x;
	printf("%.3lf\n",h);
	return 0;
}
