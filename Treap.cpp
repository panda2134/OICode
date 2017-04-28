#include<iostream>
#include<ctime>
#include<set>
#include<cstdlib>
#include<cassert>
using namespace std;
struct Node {
	int v,r;
	Node *ch[2];
	int cmp(int x) {
		if(x==v) return -1;
		else return x>v;
	}
	Node(int x) {
		ch[0]=ch[1]=NULL;
		r=rand();
		v=x;
	}
};
void rotate(Node* &o,int d) {
	Node* k=o->ch[d^1];
	o->ch[d^1]=k->ch[d];
	k->ch[d]=o;
	o=k;//!!!!!
}
void insert(Node* &o,int x) { //1->ok,0->failed
	if(o==NULL)o=new Node(x);
	else {
		int d=o->cmp(x);insert(o->ch[d],x);
		if(o->ch[d]->r > o->r)rotate(o,d^1);
	}
}
void remove(Node* &o,int x) { //1->ok,0->failed
	int d1=o->cmp(x);
	if(d1==-1) {
		if(o->ch[0]==NULL) o=o->ch[1];
		else if(o->ch[1]==NULL) o=o->ch[0];
		else {
			int d2=(o->ch[0]->r > o->ch[1]->r);
			rotate(o,d2);
			remove(o->ch[d2],x);
		}
	} else remove(o->ch[d1],x);
}
bool find(Node* &o,int x) {
	if(o==NULL) return false;
	int d=o->cmp(x);
	if(d==-1) return true;
	else return find(o->ch[d],x);
}
Node* root=NULL;

int main() {
	
	return 0;
}
