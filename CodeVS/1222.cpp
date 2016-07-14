#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::memset;
using std::freopen;

struct AdjEdge {
	int v, next;
};
int cnt = 0, n, e = 1, lnk[2000], vis[2000], head[2000];
bool flag,del[2100][2100];
AdjEdge a[10010];

inline void addnode(int u, int v) {
	a[e].v = v; a[e].next = head[u]; head[u] = e; e++;
}

inline void init() {
	cnt = 0;
	memset(lnk, -1, sizeof(lnk));
}

bool KM(int);

int main() {
	freopen("1222.in","r",stdin);
	cin >> n;
	int x, y;
	init();
	while (cin >> x >> y, x && y)
		del[x][y + n] = true;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (!del[i][j + n])
				addnode(i, j + n);
	for (int i = 1; i <= n; i++){
		memset(vis,false,sizeof(vis));
		if (lnk[i] == -1)
			if (KM(i))
				cnt++;
	}
	if (cnt < n) {
		cout << "none" << endl;
		return true;
	}
	//cout<<"CNT "<<cnt<<endl;
	for (int i = 1; i <= n; i++)
		for (int j = n + 1; j <= 2 * n; j++)
			if (!del[i][j]) {
				init();
				//cout<<"[DEBUG]#57\t"<<i<<' '<<j<<endl;
				del[i][j] = true;
				for (int k = 1; k <= n; k++){
					memset(vis,false,sizeof(vis));
					if (lnk[k] == -1)
						if (KM(k)){
							//cout<<"[DEBUG]#63 \t+1 "<<i<<' '<<j<<' '<<k<<endl;
							cnt++;
						}
				}
				//cout<<"[DEBUG]#67 \tcnt "<<cnt<<endl;
				if (cnt < n){
					cout<<i<<' '<<j-n<<endl;
					flag=true;
				}
				del[i][j] = false;
			}
	if (!flag)
		cout << "none" << endl;
	return 0;
}
bool KM(int u) {
	for (int i = head[u]; i != 0; i = a[i].next) {
		int v = a[i].v;
		//cout<<"[DEBUG]#81 \t "<<u<<' '<<v<<endl;
		if (!del[u][v]) {
			//cout<<"[DEBUG]#83 \t connected:"<<u<<' '<<v<<endl;
			if (vis[v])
				continue;
			vis[v] = true;
			//cout<<"[DEBUG]#89 \t lnk[v]: "<<lnk[v]<<endl;
			if (lnk[v] == -1 || KM(lnk[v])) {
				lnk[v] = u;
				lnk[u] = v;
				//cout<<"[DEBUG]#89 \t connected: "<<u<<' '<<v<<endl;
				//cout<<"[DEBUG]#90 \t lnk[v]: "<<lnk[v]<<endl;
				return true;
			}
		}
	}
	return false;
}
