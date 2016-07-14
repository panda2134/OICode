//TODO:fixit
#include <iostream>
#include <cstdio>
using namespace std;
long long n, k;
double ans;
double cable[10001];//cm
bool chk(double x){
	int cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=int(cable[i]/x);
	//cout<<"x,cnt="<<x<<','<<cnt<<endl;
	return cnt>=k;
}
void bisearch(double i,double j){
	cout<<i<<' '<<j<<endl;
	if(j-i<=0.01){
		ans=i;
		return;
	}
	double m=(i+j+1)/2;
	if(chk(m))//>=
		bisearch(m,j);
	else//<
		bisearch(i,m-0.01);
}
int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) 
		cin >> cable[i];
	
	bisearch(0.01,200000);
	printf("%.2f",ans);
	return 0;
}
