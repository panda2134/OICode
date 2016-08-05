#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main(){
	stack<int> st;
	queue<int> q;
	priority_queue<int> pq;
	bool isSt=true,isQ=true,isPQ=true;
	int n;
	while(cin>>n){
		while(!st.empty()) st.pop();
		while(!q.empty()) q.pop();
		while(!pq.empty()) pq.pop();
		isSt=isQ=isPQ=true;
		for(int i=1;i<=n;i++){
			int cmd,val;
			cin>>cmd>>val;
			if(cmd==1){
				if(isSt)
					st.push(val);
				if(isQ)
					q.push(val);
				if(isPQ)
					pq.push(val);
			}else{
				if(st.empty()) isSt=false;
				isSt=st.top()==val && isSt;
				if(isSt) st.pop();
			
				if(q.empty()) isQ=false;
				isQ=q.front()==val && isQ;
				if(isQ) q.pop();
				
				if(pq.empty()) isPQ=false;
				isPQ=pq.top()==val && isPQ;
				if(isPQ) pq.pop();
			}
		}
		if(isSt && !isQ && !isPQ)	cout<<"stack"<<endl;
		else if(!isSt && isQ && !isPQ) cout<<"queue"<<endl;
		else if(!isSt && !isQ && isPQ) cout<<"priority queue"<<endl;
		else if(!isSt && !isQ && !isPQ) cout<<"impossible"<<endl;
		else cout<<"not sure"<<endl;
	}
	return 0;
}
