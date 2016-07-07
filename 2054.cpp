#include<iostream>
using namespace std;
int v,n;
unsigned long long cnt[10001];
int coins[26];
int main(){
	cin>>v>>n;
	for(int i=1;i<=v;i++)
		cin>>coins[i];
	cnt[0]=1;
	for(int i=1;i<=v;i++)
		for(int j=1;j<=n;j++)
			if(j>=coins[i]){
				cnt[j]+=cnt[j-coins[i]];
				//cout<<i<<' '<<j<<' '<<cnt[j]<<' '<<coins[i]<<endl;
			}
	cout<<cnt[n];
	return 0;
}
