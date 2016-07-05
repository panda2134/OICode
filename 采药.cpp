#include<iostream>
using namespace std;
int t,m,tn[1000],vn[1000];
int d[1000];

int main(){
	cin>>t>>m;
	for(int i=1;i<=m;i++){
		cin>>tn[i]>>vn[i];
		for(int j=t;j>=tn[i];j--)
				d[j]=max(d[j],d[j-tn[i]]+vn[i]);
	}
	cout<<d[t];
	return 0;
}

