#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
	int u,v;
	int len;
};

int n,l,ans,cnt,fa[30000];
vector<Edge> edges;

inline void Init();
int GetFather(int);
void Union(int,int);

bool cmp(const Edge & a,const Edge & b){
	return a.len<b.len;
}

int main(){
	scanf("%d",&n);
	Init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			scanf("%d",&l);
			if(l){
				Edge e;e.u=i;e.v=j;e.len=l;
				edges.push_back(e);
			}
		}
	sort(edges.begin(),edges.end(),cmp);
	for(int i=0;i<edges.size();i++){
		Edge edge=edges[i];
		if(GetFather(edge.u)!=GetFather(edge.v)){
			Union(edge.u,edge.v);
			ans+=edge.len;
			cnt++;
			if(cnt==n-1)
				break;
		}
	}
	printf("%d",ans);
	return 0;
}

inline void Init(){
	for(int i=1;i<=n;i++)
		fa[i]=i;
}

int GetFather(int x){
	if(x==fa[x])
		return x;
	return fa[x]=GetFather(fa[x]);
}

void Union(int u,int v){
	fa[GetFather(u)]=GetFather(v);
}
