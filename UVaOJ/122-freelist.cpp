#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std;
struct Node{
	bool init;
	int n;
	Node *left,*right;
	Node(){init=false;n=0;left=right=NULL;}
};
Node *root;
Node node[2048];
char now[2048];
queue<Node*> freepool;
inline void cut_string(char* now,char* now1,char* now2){
	int len1=strchr(now,',')-now-1,len2=strlen(now)-len1-3;
	memcpy(now1,now+1,len1);
	memcpy(now2,now+len1+2,len2);
	now1[len1]='\0';now2[len2]='\0';
}
void init(){
	for(int i=0;i<2048;i++)
		freepool.push(node+i);
}
Node* getnode(){
	Node* u=freepool.front();freepool.pop();
	u->init=false;
	return u;
}
void deletenode(Node* u){
	freepool.push(u);
} 
void renew_tree(Node* k){
	if(k==NULL) return;
	Node *l=k->left,*r=k->right;
	deletenode(k);
	renew_tree(l);
	renew_tree(r);
}
bool check_tree(Node* k){
	if(k==NULL) return true;
	return k->init && check_tree(k->left) && check_tree(k->right);
}
inline void print_tree(){
	vector<int> ans;
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* p=q.front();q.pop();
		if(p!=NULL){
			ans.push_back(p->n);
			q.push(p->left);q.push(p->right);
		}
	}
	//�����Ŀ��Ȼ����ĩ�ո񣡣��������� 
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i]);
		if(i==ans.size()-1) printf("\n");
		else printf(" ");
	}
}
int main(){
	init();
	root=getnode();
	while(~scanf("%s",now)){
		if(now[1]==')'){
			if(!check_tree(root))printf("not complete\n");
			else print_tree();
			renew_tree(root);root=getnode();
			continue;
		}
		char now1[2048],now2[2048];
		cut_string(now,now1,now2);
		int no=atoi(now1);
		Node* k=root;
		for(int i=0;i<strlen(now2);i++){
			if(now2[i]=='L'){
				if(k->left==NULL) k->left=getnode();
				k=k->left;
			}else{
				if(k->right==NULL) k->right=getnode();
				k=k->right;
			}
		} 
		if(k->init){
			printf("not complete\n");
			renew_tree(root);root=getnode();
			char buf[2000];
			while(true){
				scanf("%s",buf);
				if(buf[0]=='(' && buf[1]==')') break;
			}
		}else{
			k->init=true;
			k->n=no;
		}
	}
	return 0;
} 
