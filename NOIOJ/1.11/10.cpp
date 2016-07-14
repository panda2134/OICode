#include <iostream>
#include <cstdio>
using namespace std;
int ans, l, n, m, a[60000];

bool check(int x) {
	int k = 0; ans = 0;
	//cout<<"x:"<<x<<endl;
	//cout<<"ans i k"<<endl;
	for (int i = 1; i <= n+1; i++) {
		//cout<<ans<<"   "<<i<<' '<<k<<endl;
		if (a[i] - a[k] < x) {
			ans++;
			//cout<<ans<<endl;
			//cout<<"a[i],a[k] "<<a[i]<<" "<<a[k]<<endl;
			//if(ans>m)
			//	return false;
		} else
			k = i;
	}
	
	//cout<<"ans:"<<ans<<endl;
	return ans <= m;
}
void work(int i, int j) {
	//cout<<"i&j "<<i<<' '<<j<<endl;
	if (i == j) {
		cout << i;
		return;
	}
	int m = (i + j + 1) / 2;
	if (check(m))
		work(m, j);
	else
		work(i, m - 1);
}
int main() {
	//freopen("10.in","r",stdin);
	cin >> l >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[n+1]=l;
	work(1, l);
	return 0;
}
