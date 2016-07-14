#include <iostream>
using namespace std;
int ans, l, n, m, a[60000];

bool check(int x) {
	int k = 0; ans = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] - a[k] < x) {
			ans++;
			i++;
		}
		k = i;
	}
	return ans < m;//TODO:fix it!!!
}
void work(int i, int j) {
	if (i == j){
		cout<<i;
		return;
	}
	int m = (i + j + 1) / 2;
	if (check(m))
		work(m,j);
	else
		work(i,m-1);
	}
int main() {
	cin >> l >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[n];
	work(1,n);
	return 0;
}
