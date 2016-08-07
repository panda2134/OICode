#include<cstdio>
#include<algorithm>
#include<cstring>
#define CLEAR(x) memset(x,0,sizeof(x))
using namespace std;
int T,n,maxn,a[30000];
long long ans;
int LS[30000],RS[30000];
int C[200000];
inline int lowbit(int x) {
	return x&-x;
}
inline int sum(int x) {
	int ret=0;
	while(x>0) {
		ret+=C[x];
		x-=lowbit(x);
	}
	return ret;
}
inline void add(int x,int val) {
	while(x<=maxn) {
		C[x]+=val;
		x+=lowbit(x);
	}
}
int main() {
	scanf("%d",&T);
	while(T--) {
		n=0;
		ans=0;
		maxn=0;
		CLEAR(a);
		CLEAR(LS);
		CLEAR(RS);
		scanf("%d",&n);
		for(int i=1; i<=n; i++) {
			scanf("%d",a+i);
			maxn=max(maxn,a[i]);
		}
		for(int i=1; i<=n; i++) {
			LS[i]=sum(a[i]-1);
			add(a[i],1);
		}
		CLEAR(C);
		for(int i=n; i>=1; i--) {
			RS[i]=sum(a[i]-1);
			add(a[i],1);
		}
		CLEAR(C);
		for(int i=1; i<=n; i++)
			ans+=((long long)LS[i]*(n-i-RS[i]))+((long long)(i-1-LS[i])*RS[i]);
		printf("%lld\n",ans);
	}
}
