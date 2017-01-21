/* RE:需要当前弧优化？*/ 
#include<iostream>
#include<cstring>
#include<queue>
#include<deque>
using namespace std;
const int maxn=11100;
int N,M;
int layers[maxn],n,s,t;
int G[maxn][maxn],Gbk[maxn][maxn];
bool vis[maxn];
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
void build_edges(){
	cin>>N>>M;
	s=N+M+1;t=N+M+2;
	n=N+M+2;
	for(int i=1;i<=M;i++){
		int x,y;cin>>x>>y;x+=M;y+=M;
		Gbk[i][x]=Gbk[i][y]=1;
		Gbk[s][i]=1;
	}
} 
void bisearch(int l,int r){
	if(l==r){
		cout<<l<<endl;
		return;
	}
	memcpy(G,Gbk,sizeof(Gbk)); 
	int mid=(l+r)>>1;
	for(int i=M+1;i<=M+N;i++) G[i][t]=mid;
	if(Dinic()<M) bisearch(mid+1,r);
	else bisearch(l,mid);
}
int main(){
	int T;
	cin>>T;
	while(T--){
		build_edges();
		bisearch(1,10010);
	} 
	return 0;
}
