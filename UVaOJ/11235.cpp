#include<iostream>
#include<cstring>
#define MAXN 100100
#define clear(x) memset(x,0,sizeof(x))
using namespace std;
int n,q,d[MAXN][18];
int num[MAXN],s[MAXN],e[MAXN],count[MAXN];
inline void init();
inline void work();
inline int query(int l,int r);
int main(){
	while(cin>>n>>q && n){
		init();
		for(int i=1;i<=q;i++)
			work();
	}
	return 0;
}
inline void init(){
	clear(num);clear(count);clear(s);clear(e);clear(d);
	int cnt=0,now=0,last=-100010;
	for(int i=1;i<=n+1;i++){
		if(i<=n) cin>>now;
		else now=-100010;
		if(now!=last){
			e[cnt]=i-1;
			count[cnt]=e[cnt]-s[cnt]+1;
			s[++cnt]=i;
		}
		num[i]=cnt;
		last=now;
	}
	cnt--;
	for(int i=1;i<=cnt;i++) d[i][0]=count[i];
	for(int j=1;(1<<j)<=cnt;j++)
		for(int i=1;(i+(1<<j)-1)<=cnt;i++)
			d[i][j]=max(d[i][j-1],d[i+(1<<(j-1))][j-1]);
}
inline void work(){
	int a,b;cin>>a>>b;
	int l=num[a],r=num[b];
	if(l==r)
		cout<<b-a+1<<endl;
	else{
		int t1=e[l]-a+1,t2=query(l+1,r-1),t3=b-s[r]+1;
		cout<<max(max(t1,t2),t3)<<endl;
	}
}
inline int query(int l,int r){
	if(l>r) return -1;
	int j;for(j=0;(1<<(j+1))<=r-l+1;j++);
	return max(d[l][j],d[r-(1<<j)+1][j]);
}
