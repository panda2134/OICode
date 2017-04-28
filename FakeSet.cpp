//set<int> implemented using treap
#include<iostream>
#include<ctime>
#include<set>
#include<cstdlib>
#include<cassert>
using namespace std;

const int MAXNI=50000000;
const int MAXNQ=50000000;
const int MAXNR=50000000;

class Treap {
	private:
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
			Node() {
				Node(0);
			}
		};
		void rotate(Node* &o,int d) {
			Node* k=o->ch[d^1];
			o->ch[d^1]=k->ch[d];
			k->ch[d]=o;
			o=k;//!!!!!
		}
		bool _insert(Node* &o,int x) { //1->ok,0->failed
			if(o==NULL) {
				o=new Node(x);
				return true;
			} else {
				int d=o->cmp(x);
				if(d==-1) return false;
				bool ret=_insert(o->ch[d],x);
				if(o->ch[d]->r > o->r)rotate(o,d^1);
				return ret;
			}
		}
		bool _remove(Node* &o,int x) { //1->ok,0->failed
			if(o==NULL) return false;
			int d1=o->cmp(x);
			if(d1==-1) {
				if(o->ch[0]==NULL) {
					o=o->ch[1];
					return true;
				} else if(o->ch[1]==NULL) {
					o=o->ch[0];
					return true;
				} else {
					int d2=(o->ch[0]->r > o->ch[1]->r);
					rotate(o,d2);
					_remove(o->ch[d2],x);
					return true;
				}
			} else {
				return _remove(o->ch[d1],x);
			}
		}
		bool _find(Node* &o,int x) {
			if(o==NULL) return false;
			int d=o->cmp(x);
			if(d==-1) return true;
			else return _find(o->ch[d],x);
		}
		Node* root;
	public:
		Treap() {
			root=NULL;
			srand(20170428);
		};

		bool insert(int x) {
			return _insert(root,x);
		}
		bool remove(int x) {
			return _remove(root,x);
		}
		bool find(int x) {
			return _find(root,x);
		}
};
void profile() {
	Treap t;
	set<int> st;
	clock_t t1=0,t2=0,xt=0;
	for(int i=1; i<=MAXNI; i++) {
		int v=rand();
		xt=clock();
		t.insert(v);
		xt=clock()-xt;
		t1+=xt;//
		xt=clock();
		st.insert(v);
		xt=clock()-xt;
		t2+=xt;
	}
	for(int i=1; i<=MAXNQ; i++) {
		int v=rand();
		xt=clock();
		t.find(v);
		xt=clock()-xt;
		t1+=xt;
		xt=clock();
		st.find(v);
		xt=clock()-xt;
		t2+=xt;
		assert(t.find(v)==(st.find(v)!=st.end()));
	}
	for(int i=1; i<=MAXNR; i++) {
		int v=rand();
		xt=clock();
		t.remove(v);
		xt=clock()-xt;
		t1+=xt;
		xt=clock();
		if(st.count(v)) st.erase(v);
		xt=clock()-xt;
		t2+=xt;
	}
	cout<<t1<<' '<<t2<<endl;
}
int main() {
	profile();
	return 0;
}
