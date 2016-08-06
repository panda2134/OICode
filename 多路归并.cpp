#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

int a[100][1000];
int num,n[1000];
int cur[1000];
struct Pos{
	int arr,i;
	bool operator>(const Pos & p) const{
		return a[arr][i]>a[p.arr][p.i];
	}
};
vector<int> v;
priority_queue<Pos,vector<Pos>,greater<Pos> > pq;
int main(){
	cin>>num;
	for(int i=0;i<num;i++){
		cin>>n[i];
		for(int j=0;j<n[i];j++)
			cin>>a[i][j];
		Pos p;p.arr=i;p.i=0;
		pq.push(p);
	}
	while(!pq.empty()){
		Pos p=pq.top();pq.pop();
		v.push_back(a[p.arr][p.i]);
		if(++p.i<n[p.arr]) pq.push(p);
	}
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
	return 0;
}
/* Test Data:
	5
	
	6
	1 2 7 9 45 98
	8
	4  7 9 15 64 382 458 669
	2
	15 37
	3
	42 178 663
	1
	559
*/
