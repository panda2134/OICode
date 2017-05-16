//Sec.8 P227
#include<iostream>
#include<cstdlib>
using namespace std;
int k,n,a[110];
void qsort(int l,int r) {
	if(l==r) {
		cout<<a[l];
		exit(0);
	}
	if(l>r) return;
	int key=a[l],i=l,j=r;
	while(i<j) {
		for(; i<j && a[j]>=key; j--);
		a[i]=a[j];
		for(; i<j && a[i]<=key; i++);
		a[j]=a[i];
	}
	a[i]=key;
	if(l<=k && k<=i-1)
		qsort(l,i-1);
	if(k>=i+1 && k<=r)
		qsort(i+1,r);
	if(k==i) {
		cout<<a[i];
		exit(0);
	}
}
int main() {
	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];
	cin>>k;
	qsort(0,n-1);
	return 0;
}
