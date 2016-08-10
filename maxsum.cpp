#include <iostream>
using namespace std;
int n,a[100010];
int maxsum(int x,int y){
	int maxn,mid,l,r,v;mid=(x+y)>>1;
	if(x+1==y) return a[x];
	maxn=max(maxsum(x,mid),maxsum(mid,y));
	v=0;l=a[mid-1];
	for(int i=mid-1;i>=x;i--) l=max(l,v+=a[i]);
	v=0;r=a[mid];
	for(int i=mid;i<y;i++) r=max(r,v+=a[i]);
	return max(maxn,l+r);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	int a,b;
	while(cin>>a>>b)
		cout<<maxsum(a,b+1)<<endl;
	return 0;
}
