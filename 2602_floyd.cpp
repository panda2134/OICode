#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
struct Point {
	int x,y;
};
const int INF=0x7fffffff;
int n,m,s,t;
double E[101][101];
double d[101][101];
Point p[101];
double floyd(int,int);
inline int pow2(int i) {
	return i*i;
}
int main() {
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>p[i].x>>p[i].y;
	cin>>m;
	int t1=0,t2=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			E[i][j]=INF;
	for(int i=1; i<=m; i++) {
		cin>>t1>>t2;
		E[t1][t2]=E[t2][t1]=sqrt(pow2(p[t1].x-p[t2].x)+pow2(p[t1].y-p[t2].y));
	}
	cin>>s>>t;
	printf("%.2f",floyd(s,t));
	return 0;
}
double floyd(int s,int t) {
	for(int i=1; i<=n; i++)
		for(int j=1;j<=n;j++)
			d[i][j]=E[i][j];
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(d[i][j]>d[i][k]+d[k][j])
					d[i][j]=d[i][k]+d[k][j];
	return d[s][t];
}
