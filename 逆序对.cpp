//To Be Done
#include<iostream>
int n,ansout,a[10010],tmp[10010];
using namespace std;
void mergesort(int x,int y){
    if(y-x==1) return;
    int m=x+(y-x)/2;
    int p=x,q=m,i=0;
    //
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    mergesort(0,n);
    return 0;
}
