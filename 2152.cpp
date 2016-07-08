#include<iostream>
using namespace std;
const int INF=0x7fffffff;
const int x[]={-1,0,1,0},y[]={0,-1,0,1};
int a[102][102],d[102][102];
int r,c;
int dp(int i,int j);
int main(){
	cin>>r>>c;
	for(int i=0;i<=r+1;i++)
		for(int j=0;j<=c+1;j++)
			a[i][j]=INF;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			cin>>a[i][j];
	int maxn=-1;
	for(int i=1;i<=r;i++)
		for(int j=1;j<=c;j++)
			maxn=max(maxn,dp(i,j));
	cout<<maxn;
	return 0;
}

int dp(int i,int j){
	if(d[i][j])
		return d[i][j];
	int maxn=1;
	for(int w=0;w<4;w++){
		int xd=i+x[w],yd=j+y[w];
		//cout<<i<<' '<<j<<' '<<xd<<' '<<yd<<' '<<a[i][j]<<' '<<a[xd][yd]<<endl;
		if(a[i][j]>a[xd][yd]){
			maxn=max(maxn,dp(xd,yd)+1);
		}
	}
	return d[i][j]=maxn;
}
