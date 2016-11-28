#include<cstdio>
#include<cstring>
using namespace std;
struct Node{
	char ch;
	int next;
};
Node node[100010];
int head,tail,end,cur;
void init(){
	head=tail=end=cur=1;
	node[head].next=0;
}
void insert(char ch){
	end++;node[end].ch=ch;
	node[end].next=node[cur].next;
	node[cur].next=end;
	cur=node[cur].next;
	if(node[cur].next==0) tail=cur;
}
int main(){
	char s[100100];
	while(scanf("%s",s)==1){
		init();
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]=='[') cur=head;
			else if(s[i]==']') cur=tail;
			else insert(s[i]);
		}
		for(int i=node[head].next;i;i=node[i].next) printf("%c",node[i].ch);
		puts("");
	}
	return 0;
}
