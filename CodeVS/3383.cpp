#include <cstdio>
using namespace std;

int n;
int a[5000000];
int bucket[100001];

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",a+i);
    for(int i=0;i<n;i++)
        bucket[a[i]]++;
    for(int i=0;i<=100000;i++)
        for(int j=1;j<=bucket[i];j++)
            printf("%d ",i);
    return 0;
}

