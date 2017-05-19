//ToBeDone
#include<cstdio>
#include<algorithm>
#include<cstring>
#define CLEAR(x) memset(x,0,sizeof(x))
using namespace std;
const int MAXN=60,MAXT=210,INF=0x3f3f3f3f;
int cz=1,n,t,m1,m2;
int T[MAXN],opt[MAXN][MAXT];
bool vis[MAXN][MAXT],right[MAXN][MAXT],
	 left[MAXN][MAXT];//station,time
const char czstr[]="Case Number %d: ";
inline int readint(){
	int f=1,r=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9'){r=r*10+c-'0';c=getchar();}
	return f*r;
}
inline bool init(){
	CLEAR(T);CLEAR(right);CLEAR(left);CLEAR(vis);
	memset(opt,0x3f,sizeof(opt));
	n=readint();
	if(n==0) return false;
	t=readint();
	for(int i=1;i<=n-1;i++) T[i]=readint();
	m1=readint();
	for(int i=1;i<=m1;i++){
		int di=readint();
		right[1][di]=true;
		for(int j=1;j<=n-1;j++){
			di+=T[j];
			right[j+1][di]=true;
		}
	}
	m2=readint();
	for(int i=1;i<=m2;i++){
		int ei=readint();
		left[n][ei]=true;
		for(int j=n-1;j>=1;j--){
			ei+=T[j];
			left[j][ei]=true;
		}
	}
	return true;
}
int dp(int xn,int tn){
	if(vis[xn][tn])return opt[xn][tn];
	vis[xn][tn]=true;if(tn>t) return INF;
	if(tn==t && xn==n) return opt[xn][tn]=0;
	//
	opt[xn][tn]=dp(xn,tn+1)+1;
	if(left[xn][tn] && xn>1)
		opt[xn][tn]=min(opt[xn][tn],
			dp(xn-1,tn+T[xn-1]));
	if(right[xn][tn] && xn<n)
		opt[xn][tn]=min(opt[xn][tn],
			dp(xn+1,tn+T[xn]));
	return opt[xn][tn];
}
int main(){
	while(init()){
		int ans=dp(1,0);printf(czstr,cz++);
		if(ans<INF) printf("%d\n",ans);
		else printf("impossible\n");
	}
	return 0;
}

