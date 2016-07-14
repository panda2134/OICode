#include<iostream>
using namespace std;
struct ItemFood{
	double price;
	int tastePoint;
	bool isMust;
};
int n,k,d[10000],dMustChoose,tmp=-1;
double x,prices[150],tastePoints[150];
ItemFood items[150];
int main(){
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)
		cin>>prices[i];
	for(int i=1;i<=n;i++)
		cin>>tastePoints[i];
	for(int i=1;i<=n;i++){
		int idx=0;cin>>idx;
		tmp=max(tmp,idx);
		items[idx].price=prices[i];
		items[idx].tastePoint=tastePoints[i];
	}
	for(int i=1;i<=k;i++){
		int idx=0;cin>>idx;
		x-=items[idx].price;
		dMustChoose+=items[idx].tastePoint;
		items[idx].isMust=true;
	}
	for(int i=1;i<=tmp;i++)
		for(double j=x;j>=items[i].price && !items[i].isMust;j-=0.1)
			d[int(j*10)]=max(d[int(j*10)],d[int((j-items[i].price)*10)]+items[i].tastePoint);
	cout<<d[int(x*10)]+dMustChoose;
}
