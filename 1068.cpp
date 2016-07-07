#include<iostream>
using namespace std;
int n,m,a[1000];//n->格子数;m->卡片数;a->分数
int cnt[5];
int d[45][45][45][45];

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int b=0;cin>>b;
		cnt[b]++;
	}
	
	return 0;
}

