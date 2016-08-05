#include <iostream>
#include <map>
#include <vector>
using namespace std;
int n,m,k,v;
map<int,vector<int> > x;
int main(){
	while(cin>>n>>m){
		int tmp;
		for(int i=0;i<n;i++){
			cin>>tmp;
			if(!x.count(tmp)) x[tmp]=vector<int>();
			x[tmp].push_back(i+1);
		}
		for(int i=0;i<m;i++){
			cin>>k>>v;
			if(x.find(v)==x.end() || x[v].size()<k) cout<<"0"<<endl;
			else cout<<x[v][k-1]<<endl;
		}
	}
	return 0;
}
