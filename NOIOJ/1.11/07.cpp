#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[100001];
bool bisearch(int i,int j,int x){
	int m=(i+j+1)/2;
	if(i==j)
		return a[i]==x;
	if(i>j)
		return false;
	if(x>=a[m])
		return bisearch(m,j,x);
	else
		return bisearch(i,m-1,x);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(bisearch(i+1,n,m-a[i])){
			cout<<a[i]<<' '<<m-a[i]<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
	return 0;
}
