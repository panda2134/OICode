#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100001];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int now=a[1];
	cout<<now<<' ';
	for(int i=2;i<=n;i++)
		if(a[i]!=now){
			now=a[i];
			cout<<now<<' ';
		}
	return 0;
}
