#include<iostream>
using namespace std;
int n,m,a[1000];//n->格子数;m->卡片数;a->分数
int cnt[5];
int d[1000];
int dp(int n);
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int b=0;cin>>b;
		cnt[b]++;
	}
	for(int i=2;i<=n;i++)
		d[i]=-0x7ffffff;
	d[0]=a[0];
	//TO BE DONE
	cout<<dp(n);
	return 0;
}

