#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int n,f;//n->pie f->people
double pies[10001];
int ans;
inline double getV(int r){
	return M_PI*r*r;
}
bool chk(double x){
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=int(pies[i]/x);
	//cout<<x<<" "<<cnt<<endl;
	return cnt>=f;
}
double bisearch(double i,double j){
	//cout<<i<<' '<<j<<endl;
	if(i==j || j-i<=1e-4)
		return i;
	double m=(i+j)/2+0.5e-4;
	if(chk(m))
		return bisearch(m,j);
	else
		return bisearch(i,m-0.5e-4);
}
int main(){
	scanf("%d %d",&n,&f);f++;
	int r;
	for(int i=1;i<=n;i++){
		scanf("%d",&r);
		pies[i]=getV(r);
		//cout<<"V of #"<<i<<" is "<<getV(r)<<endl;
	}
	printf("%.3lf",bisearch(1,1e9));
	return 0;
}
