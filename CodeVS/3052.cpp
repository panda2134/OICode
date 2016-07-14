#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct Edge {
	int v, next;
};
const int dx[] = { -1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int e = 1, cnt, m, n, k, lnk[6001], head[6001];
bool map[6000][6000], vis[6001];
Edge a[6001];
inline void addnode(int u, int v) {
	a[e].v = v;
	a[e].next = head[u];
	head[u] = e;
	e++;
}

inline int mapping(int x, int y) {
	return (x - 1) * n + y;
}

inline void Init() {
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			map[i][j] = true;
}

bool Hungarian(int);

int main() {
	freopen("3052.in", "r", stdin);
	cin >> m >> n >> k;
	Init();
	int x, y;
	for (int i = 1; i <= k; i++) {
		cin >> x >> y;
		map[x][y] = false;
	}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (map[i][j])
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k], ny = j + dy[k];
					if (map[nx][ny]) 
						addnode(mapping(i, j), mapping(nx, ny));
				}
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (map[i][j]) {
				memset(vis,false,sizeof(vis));
				if (lnk[mapping(i, j)] == 0 && Hungarian(mapping(i, j)))
					cnt++;
			}
	cout << cnt;
	return 0;
}
bool Hungarian(int u) {
	for (int p = head[u]; p != 0; p = a[p].next) {
		int v = a[p].v;
		if (vis[v])	continue;
		vis[v] = true;
		if (lnk[v] == 0 || Hungarian(lnk[v])) {
			lnk[v] = u;
			lnk[u] = v;
			return true;
		}
	}
	return false;
}
