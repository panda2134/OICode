#include<iostream>
using namespace std;
struct Item{
	int w,v,t,h;
};
int n,x,y,d[150][150];
Item items[350];
int main(){
	cin>>n>>x>>y;
	for(int i=1;i<=n;i++){
		Item& itm=items[i];
		cin>>itm.w>>itm.v>>itm.t>>itm.h;
	}
	for(int i=1;i<=n;i++) //item
		for(int j=y;j>=0;j--)  //yuan
			for(int k=x;k>=0;k--){ //kg
				Item& itm=items[i];
				if(j>=itm.v && k>=itm.w)
					d[j][k]=max(d[j][k],d[j-itm.v][k-itm.w]+itm.t);
				
				if(j>=itm.h*itm.v && k>=itm.h*itm.w)
					d[j][k]=max(d[j][k],d[j-itm.v*itm.h][k-itm.w*itm.h]+itm.t*itm.h);
			}
	cout<<d[y][x];
	return 0;
}
