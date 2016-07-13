#include <iostream>
#include <cstring>
using namespace std;
int cnt, ans, lnk1[500], lnk2[500], n, m; //n->group m->student
bool f[500][500], vis[500];
bool KM(int u);
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		while (cin >> tmp, tmp)
			f[tmp][i] = true;
	}
	for (int i = 1; i <= m; i++) {
		memset(vis, false, sizeof(vis));
		if (lnk2[i] == 0 && KM(i))
			cnt++;
	}
	cout << cnt;
	return 0;
}
bool KM(int u) {
	for (int v = 1; v <= n; v++)
		if (!vis[v] && f[u][v]) {
			vis[v] = true;
			if (lnk1[v] == 0 || KM(lnk1[v])) {
				lnk1[v] = u;
				lnk2[u] = v;
				return true;
			}
		}
	return false;
}



