#include <iostream>
#include <vector>
#include <cstring>
#define CLR(x) memset(x,0,sizeof(x))
using namespace std;
int cz=1,V,E,T;
vector<int> a[1010];
int vis[1010],vis2[1010];
bool visible[1010];
int mark(int u,int cnt){
	//return:not visited->1 visited->0
	if(vis[u]) return 0;vis[u]=cnt;
	for(int i=0;i<a[u].size();i++)
		mark(a[u][i],cnt);
	return 1;
}
int cntOdd(int u){
	int odd=(a[u].size()&1);
	vis2[u]=1;
	for(int i=0;i<a[u].size();i++){
		int v=a[u][i];
		if(!vis2[v]) odd+=cntOdd(v);
	}
	return odd;
}
int main(){
	freopen("test.txt","r",stdin);
	while(cin>>V>>E>>T &&(V||E||T)){
		for(int i=1;i<=V;i++) a[i].clear();
		CLR(vis);CLR(vis2);CLR(visible);
		for(int i=1;i<=E;i++){
			int x,y;cin>>x>>y;a[x].push_back(y);a[y].push_back(x);
			visible[x]=visible[y]=true;//Only walk on points who have edges in/out
		}
		
		//Step one:check the number of connected components,and color the CCs
		int cocnt=0,ans=0,l=0;
		for(int i=1;i<=V;i++) if(visible[i]) cocnt+=mark(i,cocnt+1);
		if(cocnt)
			ans=cocnt-1;
		//Step two:for each CC,check the number of edges that is going to be added
		for(int i=1;i<=V;i++)
			if(vis[i]>l){
				l=vis[i];int odcnt=cntOdd(i);
				if(odcnt>2) ans+=(odcnt-2)/2; 
			}
		cout<<"Case "<<cz++<<": "<<(ans+E)*T<<endl;
	} 
	return 0;
}
