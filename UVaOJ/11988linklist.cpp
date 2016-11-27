#include<iostream>
#include<cstring>
using namespace std; 
struct Node{
	char ch;
	Node *next;
};
Node *head,*tail,*cur;
void init(){
	tail=cur=head=new Node();
}
void insert(char ch){
	Node *n=new Node();
	n->next=cur->next;
	cur->next=n;
	n->ch=ch;
	if(n->next==NULL) tail=n;
	cur=cur->next;
}
void del(){
	for(Node *now=head;now;){
		Node *x=now->next;
		delete now;
		now=x;
	}
}
int main(){
	char s[100011];
	while(cin.getline(s,100010,'\n')){
		init();
		int len=strlen(s);
		for(int i=0;i<len;i++){
			if(s[i]=='[') cur=head;
			else if(s[i]==']') cur=tail;
			else insert(s[i]);
		}
		for(Node *now=head->next;now;now=now->next)
			cout<<now->ch;
		cout<<endl;
		del();
	}
	return 0;
}
