#include <iostream>
#include <cstring>
#define clear(x) memset(x,0,sizeof(x))
using namespace std;
int n,a[500100],max_sub[2000010],max_prefix[2000010],max_suffix[2000010];
void build_tree(int o,int l,int r){
	if(l==r){max_sub[l]=max_prefix[l]=max_suffix[l]=a[l];return;}
	int mid=(l+r)>>1,v,ptot,stot;
	build_tree(o*2,l,mid);build_tree(o*2+1,mid+1,r);
	max_sub[o]=max(max_sub[o*2],max_sub[o*2+1]);
	max_sub[o]=max(max_sub[o],max_suffix[o*2]+max_prefix[o*2+1]);
	v=0;ptot=a[l];
	for(int i=l;i<=r;i++) ptot=max(ptot,v+=a[i]);
	v=0;stot=a[r];
	for(int i=r;i>=l;i--) stot=max(stot,v+=a[i]);
	max_prefix[o]=ptot;max_suffix[o]=stot;
}
int query(int o,int l,int r,int i,int j){
	//to be done...
}
int main(){
	
	return 0;
}
