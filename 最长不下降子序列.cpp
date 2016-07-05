#include<iostream>
using namespace std;
int n,q[1000],d[1000];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>q[i];
		d[i]=1;
	}
	
	for(int i=n-2;i>=0;i--){
		d[i]=1;
		for(int j=n-1;j>i;j--)
			if(q[i]<=q[j]){
				//cout<<"qi&qj"<<q[i]<<' '<<q[j]<<endl;
				//cout<<"before change:"<<d[i]<<endl;
				d[i]=max(d[i],d[j]+1);
				//cout<<"i="<<i<<","<<"j="<<j<<" d[i] changed to "<<d[i]<<endl;
			}
	}
	int m=-1;
	for(int i=0;i<n;i++)
		m=max(m,d[i]);
	cout<<m;
	return 0;
}
