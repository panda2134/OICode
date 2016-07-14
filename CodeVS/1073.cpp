#include<cstdio>
using namespace std;

int n,m,p;
int father[10000];

void Init();
int GetFather(int x);
void Union(int,int);

int main(){
	Init();
	scanf("%d%d%d",&n,&m,&p);
	int mi,mj,pi,pj;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&mi,&mj);
		Union(mi,mj);
	}
	for(int i=1;i<=p;i++){
		scanf("%d%d",&pi,&pj);
		if(GetFather(pi)==GetFather(pj))
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

void Init(){
	for(int i=0;i<10000;i++)
		father[i]=i;
}

int GetFather(int x){
	if(father[x]==x)
		return x;
	int anc=GetFather(father[x]);
	return father[x]=anc;
}

void Union(int u,int v){
	int anc1,anc2;
	anc1=GetFather(u);anc2=GetFather(v);
	father[anc2]=anc1;
}
