#include<cstdio>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;
struct Point{
	int x,y;
};
const int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
int m,n,sx,sy,tx,ty;
int dist[25][25];
bool vis[25][25],maze[25][25];
bool init(){
	memset(maze,0,sizeof(maze));
	memset(vis,0,sizeof(vis));
	memset(dist,0,sizeof(dist));
	m=n=sx=sy=tx=ty=0;
	for(int i=0;i<25;i++)
		for(int j=0;j<25;j++)
			maze[i][j]=true;
	scanf("%d%d",&m,&n);
	if(m==0 && n==0) return false;
	char ch;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>ch;
			if(ch=='@'){sx=i;sy=j;maze[i][j]=false;}
			else if(ch=='*'){tx=i;ty=j;maze[i][j]=false;}
			else if(ch=='.') maze[i][j]=false;
		}
	}
	dist[sx][sy]=0;
	return true;
}
int bfs(){
	queue<Point> q;
	q.push((Point){sx,sy});
	while(!q.empty()){
		Point u=q.front();q.pop();
		vis[u.x][u.y]=true;
		if(u.x==tx && u.y==ty) break;
		for(int i=0;i<4;i++){
			int nx=u.x+dx[i],ny=u.y+dy[i];
			if(!maze[nx][ny] && !vis[nx][ny]){
				dist[nx][ny]=dist[u.x][u.y]+1;
				q.push((Point){nx,ny});
			}
		}
	}
	if(dist[tx][ty]==0) return -1;
	else return dist[tx][ty];
}
int main(){
	while(init())
		printf("%d\n",bfs());
	return 0;
} 
