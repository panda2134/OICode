#include<cstdio>
#include<iostream>
using namespace std;
int n,k,cnt,fa[200000];

void Init(int n){
	for(int i=1;i<=n*3;i++)
		fa[i]=i;
}
int GetFather(int x){
	if(fa[x]==x) return x;
	return fa[x]=GetFather(fa[x]);
}
void Union(int u,int v){
	int t1=GetFather(u),t2=GetFather(v);
	fa[t1]=t2;
}
int main(){
	scanf("%d%d",&n,&k);
	Init(n);
	int d,x,y;
	for(int i=1;i<=k;i++){
		scanf("%d%d%d",&d,&x,&y);
		if(x>n || y>n){
			cnt++;
			continue;
		}
		if(d==1){
			if(GetFather(x+n)==GetFather(y) || GetFather(x+n*2)==GetFather(y)){
                //cout<<i<<" same->false"<<endl;
				cnt++;continue;
			}
			Union(x,y);Union(x+n,y+n);Union(x+2*n,y+2*n);
		}else{
			if((GetFather(x)==GetFather(y)) || (GetFather(x+2*n)==GetFather(y))){
                //cout<<i<<" eat->false"<<endl;
                //cout<<GetFather(x)<<' '<<GetFather(y)<<' '<<GetFather(x+2*n)<<endl;
				cnt++;continue;
			}
			Union(x+n,y);Union(x+n*2,y+n);Union(x,y+n*2);
		}
	}
	printf("%d",cnt);
	return 0;
}
