#include<bits/stdc++.h>
#define REP(i,n) for(int i=1;i<=n;i++)
using namespace std;
const int MAXN=100;
typedef double Mat[MAXN+10][MAXN+10];
inline void Clear(Mat x){memset(x,0,sizeof(Mat));}
inline void Assign(Mat x,Mat y){memcpy(x,y,sizeof(Mat));}

void gauss_jordan(Mat A,int n){
	int r;
	REP(i,MAXN){
		r=i;
		for(int j=i+1;j<=MAXN;j++)
			if(fabs(A[j][i])>fabs(A[i][i])) r=j;
		
	}
}
int main(){
	
	return 0;
}
