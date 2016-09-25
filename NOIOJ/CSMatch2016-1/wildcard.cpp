#include<cstdio>
#include<cstring>
using namespace std;
int lenstr,lenwc;
char str[100],wc[100];
bool d[100][100];
bool vis[100][100];
bool match(int x,int y);
int main(){
	scanf("%s%s",wc,str);
	lenstr=strlen(str);
	lenwc=strlen(wc);
	if(!match(0,0)) printf("not ");
	printf("matched\n");
	return 0;
} 
bool match(int x,int y){
	if(vis[x][y]) return d[x][y];
	vis[x][y]=true;
	if(x>=lenstr && y>=lenwc)
		return d[x][y]=true;
	if(x>=lenstr && y<lenstr && wc[y]!='*')
		return d[x][y]=false;
	if(wc[y]=='*')
		for(int i=x;i<=lenstr;i++)
			if(match(i,y+1))
				return d[x][y]=true;
	if(str[x] != wc[y] && wc[y]!='?')
		return d[x][y]=false;
	if(str[x]==wc[y] || wc[y]=='?')
		return d[x][y]=match(x+1,y+1);
}
