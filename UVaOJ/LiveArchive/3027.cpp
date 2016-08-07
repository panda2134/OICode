#include<iostream>
#include<algorithm>
using namespace std;
int fa[200010],d[200010];
int GetFather(int x){
	if(fa[x]==x) return x;
	else{
		int root=GetFather(fa[x]);
		d[x]+=d[fa[x]];
		return fa[x]=root;
	}
}
int main(){
	int t,n;
	cin>>t;
	while(t--){
		char cmd;int n,u,v;
		cin>>n;
		for(int i=1;i<=n;i++){fa[i]=i;d[i]=0;}
		while(cin>>cmd && cmd!='O'){
			if(cmd=='E'){
				cin>>u;GetFather(u);cout<<d[u]<<endl;
			}else{
				cin>>u>>v;fa[u]=v;d[u]=abs(u-v)%1000;
			}
		}
	}
	return 0;
}
