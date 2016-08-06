#include <iostream>
#define MAXN 100050
using namespace std;
int k=0,ans=0,fa[MAXN];
int GetFather(int x){
	if(fa[x]==x) return x;
	else return fa[x]=GetFather(fa[x]);
}
void Union(int i,int j){
	int t1=GetFather(i),t2=GetFather(j);
	fa[t1]=t2;
}
void init(){
	for(int i=1;i<=MAXN;i++)
		fa[i]=i;
	k=0;ans=0;
}
int main(){
	int x,y;
	init();
	while(cin>>x){
		if(x!=-1){
			cin>>y;
			if(GetFather(x)!=GetFather(y))
				Union(x,y);
			else
				ans++;
		}else{
			cout<<ans<<endl;
			init();
		}
	}
	return 0;
}
