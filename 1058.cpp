#include<iostream>
using namespace std;
int n,q[1000],d1[1000],d2[1000];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>q[i];
		d1[i]=d2[i]=1;
	}
	
	for(int i=1;i<n;i++){
		for(int j=i-1;j>=0;j--)
			if(q[i]>q[j]){
				//cout<<"i,j="<<i<<' '<<j<<",q[i],q[j]="<<q[i]<<' '<<q[j]<<endl;
				d1[i]=max(d1[i],d1[j]+1);
				//cout<<"d1[i]="<<d1[i]<<endl;
			}
	}
	for(int i=n-2;i>=0;i--){
		d2[i]=1;
		for(int j=n-1;j>i;j--)
			if(q[i]>q[j]){
				d2[i]=max(d2[i],d2[j]+1);
			}
	}
	//for(int i=0;i<n;i++)
	//	cout<<d1[i]<<' '<<d2[i]<<endl;
	
	int tmp=-1;
	for(int i=0;i<n;i++){
		int a=-1,b=-1;
		for(int j=0;j<i;j++)
			a=max(a,d1[j]);
		for(int j=i;j<n;j++)
			b=max(b,d2[j]);
		if(a!=-1 && b!=-1)
			tmp=max(tmp,a+b);
	}
	cout<<n-tmp;
	return 0;
}
