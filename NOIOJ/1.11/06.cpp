#include <iostream>
using namespace std;
long long n,m,a[100100];
inline bool chk(long long x){
	long long sum=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x)
			return false;
		sum+=a[i];
		if(sum>x){
			sum=a[i];
			cnt++;
		}
	}
	cnt++;
	return cnt<=m;
}
long long bisearch(long long i,long long j){
	if(i==j)
		return i;
	long long m=(i+j)/2;
	if(chk(m))
		bisearch(i,m);
	else
		bisearch(m+1,j);
}
int main(){
	cin>>n>>m;long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	long long ans=bisearch(0,2*sum+1);
	cout<<ans;
	return 0;
}
