#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
template<typename T>
class SparseTable{
	private:
		int n;
		T d[10000][10];
	public:
		SparseTable(const vector<T> & vec){
			n=vec.size();
			for(int i=0;i<n;i++) d[i][0]=vec[i];
			for(int j=1;(1<<j)<=n;j++)
				for(int i=0;i+(1<<j)-1<n;i++)
					d[i][j]=min(d[i][j-1],d[i+(1<<(j-1))][j-1]);
		}
		T rangemin(int l,int r){
			assert(l>=0);assert(r<n);assert(l<=r);
			int j;
			for(j=0;(1<<(j+1))<=r-l+1;j++);
			return min(d[l][j],d[r-(1<<j)+1][j]);
		}
};
