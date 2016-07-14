#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using std::scanf;
using std::printf;
using std::cerr;
using std::endl;
using std::sqrt;

struct Pos{
	double x,y;
};
struct Edge{
	int v,next;
};

int e=1,lnk[5000];
bool vis[5000];
Pos g[200],h[200];
Edge a[5000];int head[5000];

inline double GetDist(Pos a,Pos b){
	double xDelta=a.x-b.x,yDelta=a.y-b.y;
	return sqrt(xDelta*xDelta+yDelta*yDelta);
}

inline void AddNode(int u,int v){
	a[e].v=v;a[e].next=head[u];head[u]=e;e++;
}

bool dfs(int);
void Clear();

int main(){
    #ifdef DEBUG
    freopen("1538.in","r",stdin);
    #endif
	int n,m,t,v;memset(lnk,-1,sizeof(lnk));
	while(scanf("%d%d%d%d",&n,&m,&t,&v)>0){
		int cnt=0;
		for(int i=1;i<=n;i++)
			scanf("%lf%lf",&(g[i].x),&(g[i].y));

		for(int i=1;i<=m;i++)
			scanf("%lf%lf",&(h[i].x),&(h[i].y));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(GetDist(g[i],h[j])<=t*v)
					AddNode(i,j+n);
		for(int i=1;i<=n;i++){
			memset(vis,false,sizeof(vis));
			if(!dfs(i))
				cnt++;
		}
		printf("%d\n",cnt);
		Clear();//To Be Done
	}
	return 0;
}

void Clear(){ //To Be Done
	e=1;
	memset(lnk,-1,sizeof(lnk));
	memset(g,0,sizeof(g));
	memset(h,0,sizeof(h));
	memset(a,0,sizeof(a));
	memset(head,0,sizeof(head));
}

bool dfs(int u){
    #ifdef DEBUG
    cerr<<"U="<<u<<endl;
    #endif
	for(int i=head[u];i!=0;i=a[i].next){
		int v=a[i].v;
		#ifdef DEBUG
        cerr<<u<<' '<<v<<endl;
        #endif
		if(vis[v])
			continue;
		vis[v]=true;
		if(lnk[v]==-1 || dfs(lnk[v])){
			lnk[v]=u;
			#ifdef DEBUG
			cerr<<"lnk "<<lnk[v]<<endl;
			#endif
			return true;
		}
	}
	return false;
}
