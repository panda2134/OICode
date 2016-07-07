#include<iostream>
using namespace std;
int n,m,a[1000];//n->格子数;m->卡片数;a->分数
int cnt[5];
int d[45][45][45][45];

inline int len(int a,int b,int c,int d);

int main()
{

    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=m; i++)
    {
        int b=0;
        cin>>b;
        cnt[b]++;
    }
    d[0][0][0][0]=a[1];
    for(int i=0; i<=cnt[1]; i++)
        for(int j=0; j<=cnt[2]; j++)
            for(int k=0; k<=cnt[3]; k++)
                for(int l=0; l<=cnt[4]; l++)
                {
                    if(i-1>=0)
                        d[i][j][k][l]=max(d[i][j][k][l],d[i-1][j][k][l]+a[len(i,j,k,l)]);
                    if(j-1>=0)
                        d[i][j][k][l]=max(d[i][j][k][l],d[i][j-1][k][l]+a[len(i,j,k,l)]);
                    if(k-1>=0)
                        d[i][j][k][l]=max(d[i][j][k][l],d[i][j][k-1][l]+a[len(i,j,k,l)]);
                    if(l-1>=0)
                        d[i][j][k][l]=max(d[i][j][k][l],d[i][j][k][l-1]+a[len(i,j,k,l)]);
                }
    cout<<d[cnt[1]][cnt[2]][cnt[3]][cnt[4]];
    return 0;
}

inline int len(int a,int b,int c,int d)
{
    return a*1+b*2+c*3+d*4+1;
}
