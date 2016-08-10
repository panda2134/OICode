#include <iostream>
#define mid(x,y) ((x+y)>>1)
using namespace std;
int n,m,a[100100],tree[500000];
int build_tree(int o,int l,int r){
	if(l==r) return tree[o]=a[l];
	else
		return tree[o]=build_tree(o*2,l,mid(l,r))
					+build_tree(o*2+1,mid(l,r)+1,r);
}
int query(int o,int l,int r,int i,int j){
	if(l>=i && r<=j) return tree[o];
	if(i<=mid(l,r) && j<=mid(l,r)) return query(o*2,l,mid(l,r),i,j);
	if(i>mid(l,r) && j>mid(l,r)) return query(o*2+1,mid(l,r)+1,r,i,j);
	if(i<=mid(l,r) && j>mid(l,r)) return query(o*2,l,mid(l,r),i,mid(l,r))+query(o*2+1,mid(l,r)+1,r,mid(l,r)+1,j);
}
void modify(int o,int l,int r,int d,int val){
	if(l==r){tree[o]+=val;return;}
	if(d<=mid(l,r)) modify(o*2,l,mid(l,r),d,val);
	else modify(o*2+1,mid(l,r)+1,r,d,val);
	tree[o]=tree[o*2]+tree[o*2+1];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	build_tree(1,1,n);
	cin>>m;
	for(int i=1;i<=m;i++){
		int cmd,a,b;cin>>cmd>>a>>b;
		if(cmd==1)
			modify(1,1,n,a,b);
		else
			cout<<query(1,1,n,a,b)<<endl;
	}
	return 0;
}
