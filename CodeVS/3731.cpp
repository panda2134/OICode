#include<iostream>
#include<cstdlib>
#include<queue>
#include<cstring>
using namespace std;

struct Node{
	int nodeNum;
	int next;
};

const int INF=0x7fffffff;

bool inQueue[1000000],exist[1000000];
int n,m,s,t,cur=1;
int head1[1000000],head2[1000000];
int dis[1000000],dis_rev[1000000];
Node nodes[1000000];

void init_all();
void spfa();
void spfa_rev();

void addNode(int s,int t){
	nodes[cur].nodeNum=t;nodes[cur].next=head1[s];head1[s]=cur;cur++;
	nodes[cur].nodeNum=s;nodes[cur].next=head2[t];head2[t]=cur;cur++;
}

int main(){
	cin>>n>>m;
	int x,y;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		addNode(x,y);
	}
	cin>>s>>t;
	init_all();
	spfa_rev();
	for(int i=1;i<=n;i++)
		for(int j=head1[i];j!=0;j=nodes[j].next)
			if(dis_rev[nodes[j].nodeNum]==INF){
				exist[i]=false;
				break;
			}
	spfa();
	cout<<-1;
	return 0;
}

void spfa(){
	if(!exist[s])
		return;
	queue<int> q;
	q.push(s);inQueue[s]=true;
	while(!q.empty()){
		int u=q.front();q.pop();inQueue[u]=false;
		for(int v=head1[u];v!=0;v=nodes[v].next){
			if(nodes[v].nodeNum==t){
				cout<<dis[u]+1;
				exit(0);
			}
			if(exist[nodes[v].nodeNum] && dis[nodes[v].nodeNum]>dis[u]+1){
				dis[nodes[v].nodeNum]=dis[u]+1;
				if(!inQueue[nodes[v].nodeNum]){
					q.push(nodes[v].nodeNum);
					inQueue[nodes[v].nodeNum]=true;
				}
			}
		}
	}
}

void spfa_rev(){
	queue<int> q;
	q.push(t);inQueue[t]=true;
	while(!q.empty()){
		int u=q.front();q.pop();inQueue[u]=false;
 		for(int v=head2[u];v!=0;v=nodes[v].next){
			if(dis_rev[nodes[v].nodeNum]>dis_rev[u]+1){
				dis_rev[nodes[v].nodeNum]=dis_rev[u]+1;
				if(!inQueue[nodes[v].nodeNum]){
					q.push(nodes[v].nodeNum);
					inQueue[nodes[v].nodeNum]=true;
				}
			}
		}
	}
	memset(inQueue,false,sizeof(inQueue));
}

void init_all(){
	for(int i=1;i<=n;i++)
		dis[i]=dis_rev[i]=INF;
	dis[s]=0;	
	dis_rev[t]=0;
	memset(exist,true,sizeof(exist));
}
