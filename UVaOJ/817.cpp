#include<cstdio>
#include<cstring>
#include<cassert>
#include<string>
#include<map>
#include<cstdlib>
#include<cctype>
#include<stack>
#define ADD(x) (x=='+')
#define SUB(x) (x=='-')
#define MUL(x) (x=='*')
#define NIL(x) (x=='\0')
#define FileIn freopen("debug.in","r",stdin)
#define FileOut freopen("debug.out","w",stdout)
#ifdef DEBUG
#define DebugInt(info,x) do{printf("[Debug]"info);printf(": %d\n",x);}while(0)
#define DebugStr(info,x) do{printf("[Debug]"info);printf(": \"%s\"\n",x);}while(0)
#else
#define DebugInt(info,x) do{}while(0)
#define DebugStr(info,x) do{}while(0)
#endif
using namespace std;
const char o[4]="+-*";
bool ok=false;
map<string,bool> vis;
char input[20];
int cz=1;
stack<int> ans;
stack<char> op;
bool getline(char* str) {
	int i=0,c=getchar();
	for(; c!='\n'&&c!=EOF; c=getchar(),i++) str[i]=c;
	str[i]='\0';
	return !(c==EOF&&i==0);
}
void insert(char* str,int x,char c) {//O(n)
	int l=strlen(str);
	for(int i=l; i>=x; i--)str[i+1]=str[i];
	str[x]=c;
}
void remove(char *str,int x) {//O(n)
	int len=strlen(str);
	for(int i=x; i<=len-1; i++) str[i]=str[i+1];
}
inline void getNum(int& p1,int & p2) {
	p2=ans.top();
	ans.pop();
	p1=ans.top();
	ans.pop();
}
inline void doUpdate() {
	while(!op.empty()&&MUL(op.top())) {
		int p1,p2;
		getNum(p1,p2);
		ans.push(p1*p2);
		op.pop();
	}
}
void clean() {
	while(!op.empty()) op.pop();
	while(!ans.empty()) ans.pop();
}
inline int resolve() {
	if(op.empty()) {
		int t=ans.top();
		ans.pop();
		return t;
	} else {
		int opn=op.top();
		op.pop();
		int t2=ans.top();
		ans.pop();
		int t1=resolve();
		if(ADD(opn)) return (t1+t2);
		if(SUB(opn)) return (t1-t2);
		if(MUL(opn)) return (t1*t2);
	}
}
//NOTE: in DFS we should guarantee that a operator is not before or after another!!!
bool eval(char* str) { //O(n)
	int len=strlen(str);
	int cur=0;
	bool first=true;
	for(int i=0; i<=len; i++) {
		if(!isdigit(str[i])) {
			ans.push(cur);
			cur=0;
			if(ADD(str[i])) {
				doUpdate();
				op.push('+');
			} else if(SUB(str[i])) {
				doUpdate();
				op.push('-');
			} else if(MUL(str[i])) {
				op.push('*');
			} else if(NIL(str[i])) {
				doUpdate();
			}
			first=true;
		} else {
			if(cur==0 && !first) {
				clean();
				return false;
			}
			cur=cur*10+str[i]-'0';
			first=false;
		}
	}
	ans.push(resolve());
	bool ret=(ans.top()==2000);
	clean();
	return ret;
}
void solveit(char* str,int x) {
	DebugStr("Str",str);
	
	if(vis[str]) return;
	vis[str]=true;
	int len=strlen(str);
	if(eval(str)){printf("  %s=\n",str);ok=true;}
	if(x>=len) return;
	
	char bs[20];memcpy(bs,str,sizeof(char)*(len+1));
	for(int i=x;i<len;i++){
		for(int j=0;j<3;j++){
			insert(str,i,o[j]);
			solveit(str,i+2);
			memcpy(str,bs,sizeof(char)*(len+1));
		}
	}
}
int main() {
	//FileIn;
	//FileOut;
	while(getline(input)) {
		if(input[0]=='=') break;
		int len=strlen(input);
		input[len-1]='\0';
		printf("Problem %d\n",cz++);
		
		if(len>4)solveit(input,1);
		if(!ok) printf("  IMPOSSIBLE\n");
		ok=false;
		vis.clear();
	}
	return 0;
}
