//TODO:fixit
#include <iostream>
#include <cstdio>
using namespace std;
long long n, k;
long long ans;
long long cable[10001];//cm
bool chk(long long x){
	long long cnt=0;
	for(int i=1;i<=n;i++)
		cnt+=(long long)(cable[i]/x);
	//cout<<"x,cnt="<<x<<','<<cnt<<endl;
	return cnt>=k;
}
void bisearch(long long i,long long j){
	//cout<<i<<' '<<j<<endl;
	if(j==i){
		ans=i;
		return;
	}
	double m=(i+j+1)/2;
	//cout<<"m="<<m<<endl;
	if(chk(m))//>=
		bisearch(m,j);
	else//<
		bisearch(i,m-1);
}
int main() {
	cin >> n >> k;
	double tmp;
	for (int i = 1; i <= n; i++){
		cin>>tmp;
		cable[i]=tmp*100;
	}
	bisearch(0,200000000);
	if(ans>=1)
		printf("%.2f",ans/100.0);
	else
		printf("0.00");
return 0;
}
