#include <iostream>
#include "SparseTable.cpp"
#include <vector>
using namespace std;
int main(){
	int n1,n2;
	vector<int> vec1;vector<double> vec2;
	cin>>n1;
	while(n1--){
		int t;cin>>t;
		vec1.push_back(t);
	}
	cin>>n2;
	while(n2--){
		double t;cin>>t;
		vec2.push_back(t);
	}
	SparseTable<int> st1(vec1);SparseTable<double> st2(vec2);
	int t,l,r;
	while(cin>>t>>l>>r){
		if(t==1)
			cout<<st1.rangemin(l,r)<<endl;
		else
			cout<<st2.rangemin(l,r)<<endl;
	}
	return 0;
}
