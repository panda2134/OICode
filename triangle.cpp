#include<iostream>
#include<cmath>

using namespace std;

int n,ma[1000][1000];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			cin>>ma[i][j];
	for(int i=n-1;i>=1;i--){
		for(int j=1;j<=i;j++)
			ma[i][j]+=max(ma[i+1][j],ma[i+1][j+1]);
	}
	cout<<ma[1][1];
	return 0;	
}
