//No Special Judge! 
#include<iostream>
#include<cstring>
#include<queue>
#include<deque>
using namespace std;
const int MAXN=110;
int G[MAXN][MAXN],layers[MAXN];
bool vis[MAXN];
int p1[MAXN],p2[MAXN];
int s,t,m,n,now=0;
bool countLayer(){
	memset(layers,-1,sizeof(layers));
	layers[s]=0;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int v=1;v<=n;v++)
			if(G[u][v] && layers[v]==-1){
				layers[v]=layers[u]+1;
				if(v==t) return true;
				else q.push(v);
			}
	}
	return false;
}
int Dinic(){
	deque<int> st;
	int maxflow=0;
	while(countLayer()){
		memset(vis,0,sizeof(vis));
		st.push_back(s);
		while(!st.empty()){
			int u=st.back();vis[u]=true;
			if(u==t){
				int minv=0x3f3f3f3f,minp=0;
				for(int i=0;i<st.size()-1;i++){
					int t1=st[i],t2=st[i+1];
					if(G[t1][t2]<minv){
						minv=G[t1][t2];
						minp=t1;
					}
				}
				for(int i=0;i<st.size()-1;i++){
					int t1=st[i],t2=st[i+1];
					G[t1][t2]-=minv;
					G[t2][t1]+=minv;
				}
				maxflow+=minv;
				while(st.back()!=minp){
					vis[st.back()]=true;
					st.pop_back();
				}
			}else{
				bool flag=false;
				for(int v=1;v<=n;v++)
					if(G[u][v] && !vis[v] && layers[v]==layers[u]+1){
						flag=true;
						st.push_back(v);
						break;
					}
				if(!flag) st.pop_back();
			}
		}
	}
	return maxflow;
}
int main(){
	cin>>m>>n;
	s=n+1;t=n+2;
	n+=2;
	int i,j;
	while(cin>>i>>j && i!=-1 && j!=-1){
		G[i][j]=1;
		p1[now]=i;p2[now]=j;now++;
	}
	for(int i=1;i<=m;i++) G[s][i]=1;
	for(int i=m+1;i<=n;i++)
		if(i!=s) G[i][t]=1;
	int maxf=Dinic();
	if(maxf==0){
		cout<<"No Solution!"<<endl;
		return 0;
	}
	cout<<maxf<<endl;
	for(int i=0;i<now;i++)
		if(!G[p1[i]][p2[i]]) cout<<p1[i]<<' '<<p2[i]<<endl;
	return 0;
} 
