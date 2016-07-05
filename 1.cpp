#include<stdio.h>
#include<iostream>
using namespace std;
int main() {

	int f[100000],w[100000][3],p[100000][3];
	int n, m, i, j, x, y,v,t,z,ww,pp;
	cin>>v>>n;
	for(i=1; i<=n; i++) {
		cin>>x>>y>>z;
		if(z==0) {
			w[i][0]=x;
			p[i][0]=x*y;
		} else {
			if(w[z][1]==0) {
				w[z][1]=x;
				p[z][1]=x*y;
			} else {
				w[z][2]=x;
				p[z][2]=x*y;
			}
		}
	}

	for(i=1; i<=n; i++)

	{
		for(j=v; j>=1; j--) {
			ww=w[i][0];
			pp=p[i][0];
			if(j>=ww && ww>0)f[j]=max(f[j],f[j-ww]+pp);
			
			ww=w[i][0]+w[i][1];
			pp=p[i][0]+p[i][1];
			if(j>=ww && ww>0)f[j]=max(f[j],f[j-ww]+pp);
			
			ww=w[i][0]+w[i][2];
			pp=p[i][0]+p[i][2];
			if(j>=ww && ww>0)f[j]=max(f[j],f[j-ww]+pp);
			
			ww=w[i][0]+w[i][1]+w[i][2];
			pp=p[i][0]+p[i][1]+p[i][2];
			if(j>=ww && ww>0)f[j]=max(f[j],f[j-ww]+pp);
		}
	}
	cout<<f[v];
	return 0;
}
