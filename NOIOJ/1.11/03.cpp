#include <iostream>
using namespace std;
struct Rectangle {
	long long x, y;
	long long w, h;
};
long long r, n, ans;
Rectangle rect[10010];
inline long long pd(long long x) {
	long long sum1 = 0, sum2 = 0;
	for (int i = 1; i <= n; i++) {
		Rectangle & rec = rect[i];
		long long x1 = rec.x,  x2 = rec.x + rec.w;
		if (x1 < x && x2 > x) {
			sum1+=(x-x1)*rec.h;sum2+=(x2-x)*rec.h;
		}else if(x2<=x)
			sum1+=rec.w*rec.h;
		else if(x1>=x)
			sum2+=rec.w*rec.h;
	}
	//cout<<"x="<<x<<",sum1="<<sum1<<",sum2="<<sum2<<endl;
	return sum1-sum2;
}
void work(long long i, long long j) {
	if (i == j){
		ans=i;
		return;
	}
	long long m = (i + j) / 2;
	if (pd(m)>=0)
		work(i, m);
	else
		work(m + 1, j);
}
int main() {
	cin >> r >> n;
	for (int i = 1; i <= n; i++) {
		Rectangle & rec = rect[i];
		cin >> rec.x >> rec.y >> rec.w >> rec.h;
	}
	work(1, r);
	//cout<<"ans="<<ans<<endl;
	long long k,pda=pd(ans);
	for(k=ans;pd(k)==pda && k<=r;k++);
	cout<<k-1;
	return 0;
}
