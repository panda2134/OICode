#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct StuUni{
	int stu,uni;
};
int cnt, n, m, ki, lnk1[5101], lnk2[1101];
bool vis[5101], f[1101][5101], wantStudents[5101];
StuUni stu[5010];
bool Hungarian(int);
bool cmp(const StuUni & a,const StuUni & b){
	if(a.stu>b.stu)	return false;
	if(a.uni>b.uni) return false;
	return true;
}
int main() {
	freopen("2930.in", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp;
		cin >> ki;
		for (int j = 1; j <= ki; j++) {
			cin >> tmp;
			f[i][tmp] = true;
		}
	}
	cin >> m;
	for (int i = 1; i <= m; i++) {
		int tmp;
		cin >> tmp;
		wantStudents[tmp] = true;
	}
	for (int i = 1; i <= n; i++) {
		memset(vis, false, sizeof(vis));
		if (lnk2[i] == 0 && Hungarian(i))
			cnt++;
	}
	cout << cnt << endl;
	for (int i = 1; i <= n; i++)
		if (lnk2[i]){
			stu[i].stu=i;
			stu[i].uni=lnk2[i];
		}
	sort(stu+1,stu+1+n,cmp);
	for (int i = 1; i <= n; i++)
		if(stu[i].uni!=0)
			cout<<stu[i].stu<<' '<<stu[i].uni<<endl;
	return 0;
}
bool Hungarian(int u) {
	for (int v = 1; v <= 5000 ; v++)
		if (f[u][v] && wantStudents[v]) {
			if (vis[v]) continue;
			vis[v] = true;
			if (lnk1[v] == 0 || Hungarian(lnk1[v])) {
				lnk1[v] = u;
				lnk2[u] = v;
				return true;
			}
		}
	return false;
}