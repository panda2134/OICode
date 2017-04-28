#include<cstdio>
using namespace std;
struct Treap{
	struct Node{
		int v,r;
		Node *ch[2];
		int cmp(int x){
			if(x==v) return -1;
			else return x>v;
		}
	};
	Node* root;
	Treap(){root=NULL};
	void rotate(Node* &o,int d){
		Node* k=o->ch[d^1];o->ch[d^1]=k->ch[d];k->ch[d]=o;o=k;//!!!!!
	}
};
int main(){
	
	return 0;
}
