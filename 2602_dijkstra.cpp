#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
struct Point {
	int x,y;
};
const int INF=0x7fffffff;
vector<int> Edges[101];
int n,m,s,t;
double E[101][101];
double d[101];
Point p[101];
double dijkstra(int,int);
inline int pow2(int i) {
	return i*i;
}
inline bool relax(int t1,int t2) {
	if(d[t2]>d[t1]+E[t1][t2]) {
		d[t2]=d[t1]+E[t1][t2];
		return true;
	}
	return false;
}
class cmp {
	public:
		bool operator()(const int & a, const int & b) {
			return d[a]>d[b];
		}
};
int main() {
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>p[i].x>>p[i].y;
	cin>>m;
	int t1=0,t2=0;
	for(int i=1; i<=m; i++) {
		cin>>t1>>t2;
		E[t1][t2]=E[t2][t1]=sqrt(pow2(p[t1].x-p[t2].x)+pow2(p[t1].y-p[t2].y));
		Edges[t1].push_back(t2);
		Edges[t2].push_back(t1);
	}
	cin>>s>>t;
	printf("%.2f",dijkstra(s,t));
	return 0;
}
double dijkstra(int s,int t) {
	for(int i=1; i<=n; i++)
		d[i]=INF;
	d[s]=0.0;//OvO
	priority_queue<int,vector<int>,cmp> pq;
	for(int i=1; i<=n; i++)
		pq.push(i);
	while(!pq.empty()){
		int t1=pq.top(),t2=0;pq.pop();
		for(int i=0;i<Edges[t1].size();i++){
			t2=Edges[t1][i];
			if(relax(t1,t2)){
				pq.push(t2);
			}
		}
	}
	return d[t];
}
