#include<iostream>
using namespace std;

int n,m,nums[100010],t[100010];

void Update(int o,int L,int R,int num,int val){
	int M=(L+R)/2;
	
	if(L==R){
		t[o]=val;
		return;
	}
	if(num>=L && num<=M)
		Update(o*2,L,M,num,val);
	if(num>=M+1 && num<=R)
		Update(o*2+1,M+1,R,num,val);
	t[o]=t[o*2]+t[o*2+1];
}

int query(int o,int L,int R,int ql,int qr){
	int M=(L+R)/2;
	if(ql<=L && R<=qr)
		return t[o];
	if(ql<=M && M+1<=qr)
		return query(o*2,L,M,ql,M)+query(o*2+1,M+1,R,M+1,qr);
	if(qr<=M)
		return query(o*2,L,M,ql,qr);
	if(ql>=M+1)
		return query(o*2+1,M+1,R,ql,qr);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
		Update(1,1,n,i,nums[i]);	
	}
	cin>>m;int type=0,a=0,b=0;
	for(int i=1;i<=m;i++){
		cin>>type>>a>>b;
		if(type==1){
			nums[a]+=b;
			Update(1,1,n,a,nums[a]);
		}else{
			cout<<query(1,1,n,a,b)<<endl;
		}
	}
	return 0;
}
