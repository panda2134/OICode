#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
struct Point{
	int x,y;
};
bool inQueue[101];
vector<int> Edges[101];
int n,m,s,t;
double E[101][101];
double d[101];
Point p[101];
inline int pow2(int i){return i*i;}
inline bool relax(int t1,int t2){
	if(d[t2]>d[t1]+E[t1][t2]){
		d[t2]=d[t1]+E[t1][t2];
		return true;
	}
	return false;
}
void spfa(int);
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	cin>>m;
	int t1=0,t2=0;
	for(int i=1;i<=m;i++){
		cin>>t1>>t2;
		E[t1][t2]=E[t2][t1]=sqrt(pow2(p[t1].x-p[t2].x)+pow2(p[t1].y-p[t2].y));
		Edges[t1].push_back(t2);Edges[t2].push_back(t1);
	}
	cin>>s>>t;
	spfa(s);
	printf("%.2f",d[t]);
	return 0;
}

void spfa(int s){
	//init
	for(int i=1;i<=n;i++)
		d[i]=999999999.0;
	d[s]=0;
	queue<int> q;
	q.push(s);
	inQueue[s]=true;
	while(!q.empty()){
		int t1=q.front(),t2=0;q.pop();
		inQueue[t1]=false;
		for(int i=0;i<Edges[t1].size();i++){
			t2=Edges[t1][i];
			if(relax(t1,t2) && !inQueue[t2]){
				q.push(t2);
				inQueue[t2]=true;
			}
		}
	}
}
