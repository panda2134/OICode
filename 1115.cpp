#include<iostream>
using namespace std;
int n,m,v[50],p[50];
int d[30000];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>v[i]>>p[i];
		for(int j=n;j>=v[i];j--)
			d[j]=max(d[j],d[j-v[i]]+v[i]*p[i]);
	}
	cout<<d[n];
}
