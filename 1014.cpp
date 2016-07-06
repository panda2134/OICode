#include<iostream>
#define B
using namespace std;

#ifdef A
//Solution1:OK.
int vn,maxn=0,n,V;
bool d[100000];
int main(){
	cin>>V>>n;
	d[0]=true;
	for(int i=1;i<=n;i++){
		cin>>vn;
		bool found=false;
		for(int j=maxn;j>=0;j--)
			if(d[j]){
				//cout<<j+vn<<"(before)"<<maxn<<endl;
				d[j+vn]=true;
				if(!found){
					maxn=j+vn;
					found=true;
				}
				//cout<<j+vn<<"(after)"<<maxn<<endl;
			}
	}
	/*
	for(int i=V;i>=0;i--)
		if(d[i])
			cout<<"i="<<i<<" true"<<endl;
	*/
	for(int i=V;i>=0;i--)
		if(d[i])
			{cout<<V-i;return 0;}
	return 0;
}
#else
//Solution2:BUGGY!  TODO:FIX IT
int vn,n,v,d[100000];
int main(){
	cin>>v>>n;
	for(int i=1;i<=n;i++){
		cin>>vn;
		for(int j=v;j>=vn;j--)
			if(d[j-vn]>vn)
				d[j]=min(d[j],d[j-vn]-vn);
	}
	cout<<d[v];
}
#endif
