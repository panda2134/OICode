#include<iostream>
using namespace std;
int n,m,a[1000];//n->格子数;m->卡片数;a->分数
int cnt[10],used[10];
int d[1000][5000];
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
	d[1]=a[1];
	int maxn=-1;
    int cur=-1;
	//TODO:rewrite this. the state should include which cards are used
	for(int i=2;i<=n;i++){
            maxn=-1;
        for(int j=1;j<=4;j++){
                for(int k=)

            if(i-j>=1 && used[j]<cnt[j]){

                if(maxn<d[i-j]+a[i]){
                    maxn=d[i-j]+a[i];
                    cur=j;

                }

            }
        }

        if(maxn==-1)
            continue;
        d[i]=maxn;
        used[cur]++;

	}

	return 0;
}

