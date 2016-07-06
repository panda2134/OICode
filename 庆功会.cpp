#include<iostream>
#define B
using namespace std;
#ifdef A
int n,m,v[550],w[550],s[550];
int d[30000];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>v[i]>>w[i]>>s[i];
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--)
			for(int k=0;k<=s[i];k++){
				if(j-k*v[i]<0)
					break;
				d[j]=max(d[j],d[j-k*v[i]]+k*w[i]);
			}
	}
	cout<<d[m];
}
#endif
#ifdef B
int n,m,cur,v[550],w[550];
int d[30000];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int v1,w1,s1;
		cin>>v1>>w1>>s1;
		int q=1;
		while(s1>=q){
			v[++cur]=v1*q;
			w[cur]=w1*q;
			s1-=q;
			q<<=1;
		}
		v[++cur]=v1*s1;
		w[cur]=w1*s1;
	}
	for(int i=1;i<=cur;i++)
		for(int j=m;j>=v[i];j--)
				d[j]=max(d[j],d[j-v[i]]+w[i]);
	cout<<d[m];
}
#endif
