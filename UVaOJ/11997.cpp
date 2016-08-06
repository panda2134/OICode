#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
int k,a[800][800];
struct Element{
	int b,s;
	Element(){};
	Element(int b,int s){
		this->b=b;this->s=s;
	};
	bool operator>(const Element& e)const{
		return s>e.s;
	}
};

void merge(int *A,int *B,int *C,int n){
	priority_queue<Element,vector<Element>,greater<Element> > pq;
	for(int i=0;i<n;i++)
		pq.push(Element(0,A[i]+B[0]));
	for(int i=0;i<n;i++){
		Element x=pq.top();pq.pop();
		C[i]=x.s;
		if(x.b+1<n){
			x.s=x.s-B[x.b]+B[x.b+1];
			x.b++;
			pq.push(x);
		}
	}
}
int main(){
	while(cin>>k){
		memset(a,0,sizeof(a));
		for(int i=0;i<k;i++){
			for(int j=0;j<k;j++) cin>>a[i][j];
			sort(a[i],a[i]+k);
			if(i!=0) merge(a[0],a[i],a[0],k);
		}
		for(int i=0;i<k;i++)
			cout<<a[0][i]<<(i==k-1?'\n':' ');
	}
	return 0;
}
