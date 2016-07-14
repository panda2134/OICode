#include <cstdio>
#include <iostream>
using namespace std;
inline double pow(double x,int y){
	double ans=1;
	for(int i=1;i<=y;i++)
		ans*=x;
	//cout<<"pow "<<x<<' '<<y<<' '<<ans<<endl;
	return ans;
}
inline double abs(double x){
	return x>=0?x:-x;
}
inline double f(double x){
	//cout<<"f("<<x<<") is "<<pow(x,5) - 15 * pow(x,4) + 85 * pow(x,3) - 225 * pow(x,2) + 274 * x - 121<<endl;
	return pow(x,5) - 15 * pow(x,4) + 85 * pow(x,3) 
	- 225 * pow(x,2) + 274 * x - 121;
}
inline bool equals(double x,double y){
	return abs(x-y)<=1e-12;
}
double work(double i,double j){
	double m=(i+j)/2;
	double f1=f(i),f2=f(j),fm=f(m);
	//cout<<i<<' '<<j<<' '<<m<<' '<<f1<<' '<<f2<<' '<<fm<<endl;
	if(equals(m,0) || equals(i,j))
		return m;
	if(f1>0 && fm<0)
		return work(i,m);
	if(fm>0 && f2<0)
		return work(m,j);
}
int main(){
	//freopen("0111-02.txt","w",stdout);
	double i=1.5,j=2.4;
	double ans=work(i,j);
	//printf("%.7lf\n",ans);
	//ans=ans+0.0000009;
	printf("%.6lf",ans);
	return 0;
}
