#include <iostream>
#include <stack>
#include <cstring> 
#include <vector>
#define CLR(x) memset(x,0,sizeof(x))
using namespace std;
int n,B[2010],D[2010];
vector<int> son[1010];
int main(){
	while(cin>>n){
		for(int i=1;i<=n;i++) son[i].clear();
		CLR(B);CLR(D);
		for(int i=1;i<=n;i++){
			int tmp;cin>>tmp;B[tmp]=i;
		}
		for(int i=1;i<=n;i++) cin>>D[i];
		stack<int> st;st.push(D[1]);
		for(int i=2;i<=n;i++){
			int x=D[i-1],y=D[i];
			if(B[y]>B[x]+1) {
				st.push(y);son[x].push_back(y);
			}
			while(B[y]<B[x]){
				st.pop();x=st.top();
			}
			
			if(B[y]==B[x]+1){
				if(y>x && st.size()>1) { //NOTICE!!! if st.top() is root,then we CANNOT pop it!!!
					st.pop();son[st.top()].push_back(y);st.push(y);
				}else{
					st.push(y);son[x].push_back(y);
				}
			}
		}
		for(int i=1;i<=n;i++){
			cout<<i<<": ";
			for(int j=0;j<son[i].size();j++){
				cout<<son[i][j]<<(j==son[i].size()-1?'\0':' ');
			}
			cout<<endl; 
		}
	}
	return 0;
}
