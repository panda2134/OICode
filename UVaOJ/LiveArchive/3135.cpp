#include <iostream>
#include <string>
#include <queue>
#include <functional>
using namespace std;
struct Event{
	int Q_num,Period,Time;
	bool operator>(const Event& e)const{
		return Time>e.Time || (Time==e.Time && Q_num>e.Q_num);
	}
};
int k;
priority_queue<Event,vector<Event>,greater<Event> > pq;
int main(){
	string cmd;
	while(cin>>cmd,cmd[0]!='#'){
		Event evt;
		cin>>evt.Q_num>>evt.Period;
		evt.Time=evt.Period;
		pq.push(evt);
	}
	cin>>k;
	for(int i=1;i<=k;i++){
		Event x=pq.top();pq.pop();
		cout<<x.Q_num<<endl;
		x.Time+=x.Period;
		pq.push(x);
	}
	return 0;
}
