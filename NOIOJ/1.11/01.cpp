#include <iostream>
using std::cin;
using std::cout;
using std::endl;
long long n, m, a[100010], tmp, ans;
inline long long abs(long long x){
	return x>0?x:-x;
}
int find(long long l,long long r){
		long long m=(l+r)/2;
	//cout<<"l,r,m,tmp "<<l<<' '<<r<<' '<<m<<' '<<tmp<<endl;
	if(l==r){
		long long t1=abs(tmp-a[l-1]),t2=abs(tmp-a[l]),t3=abs(tmp-a[l+1]);
		//cout<<t1<<' '<<t2<<' '<<t3<<endl;
		//cin.get();cin.get();
		if(t1<=t2 && t1<=t3){
			return a[l-1];
		}
		if(t2<=t1 && t2<=t3){
			return a[l];
		}
		if(t3<=t2 && t3<=t1){
			return a[l+1];
		}
		if(t2==0)
			return a[l];
		if(t1==t2 && l==n)
			return a[l-1];
		if(t2==t3 && l==1)
			return a[l];
	}
	if(a[m]<=tmp)
		return find(m+1,r);
	else
		return find(l,m);
}
int main() {
	//freopen("1.in","r",stdin);
	cin >> n;
	for (long long i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	a[0]=a[n+1]=0x7fffffffffffffff;
	cin >> m;
	for (long long i = 1; i <= m; i++) {
		cin>>tmp;
		if(a[n]<tmp)
			cout<<a[n]<<endl;
		else if(a[1]>tmp)
			cout<<a[1]<<endl;
		else{
			cout<<find(1,n)<<endl;	
		}
	}
	return 0;
}
