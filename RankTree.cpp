//文艺平衡树
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <queue>
#define SIZE(x) ((x)?(x)->sz:0)
using namespace std;
struct Node{
    int v,r,sz,cnt;
    Node *ch[2];
    int cmp(int x){
        if(x==v) return -1;
        else return x>v;
    }
    void Init(int x){
        v=x;r=rand();sz=cnt=1;
        ch[0]=ch[1]=NULL;
    }
    Node(){ Init(0); }
    Node(int x){ Init(x); }
};
namespace MemAlloc{
    const int MEMSIZE = 65536;
    queue<Node*> Q;
    void inline GetMem(){
        for(int i=1;i<=MEMSIZE;i++) Q.push((Node*)malloc(sizeof(Node)));
    }
    Node* NewNode(int x){
        if(Q.empty()) GetMem();
        Node* ret=Q.front();Q.pop();
        ret->Init(x); return ret;
    }
    void DelNode(Node* o){ Q.push(o); }
};
int N,opt,x,t;
Node *root,*cur;
void maintain(Node* &o){
    o->sz=SIZE(o->ch[0])+SIZE(o->ch[1])+o->cnt;
}
inline void rotate(Node* &o,int d){
    Node *k=o->ch[d^1];
    o->ch[d^1]=k->ch[d];
    k->ch[d]=o;
    maintain(o);
    maintain(k);
    o=k;
}
void insert(Node* &o,int x){
    if(o==NULL) {
        o=MemAlloc::NewNode(x); return;
    }
    int d=o->cmp(x);
    if(d==-1){
        o->sz++;o->cnt++;
    } else {
        insert(o->ch[d],x);maintain(o);
        if(o->ch[d]->r < o->r) rotate(o,d^1);
    }
}
Node* find(Node* o,int x){
    if(o==NULL) return NULL;
    int d=o->cmp(x);
    if(d==-1) return o;
    else return find(o->ch[d],x);
}
void delnode(Node* &o,int x){
    assert(o!=NULL);//in delnode
    int d=o->cmp(x);
    if(d==-1) {    
        if(o->cnt > 1) {
            o->sz--;o->cnt--;
        } else {    
            if(o->ch[0]==NULL) {
                Node* rhs=o->ch[1];
                MemAlloc::DelNode(o);o=rhs;
            } else if(o->ch[1]==NULL) {
                Node* lhs=o->ch[0];
                MemAlloc::DelNode(o);o=lhs;
            } else {
                int d1=(o->ch[0]->r > o->ch[1]->r);
                rotate(o,d1);delnode(o->ch[d1],x);
            }
        }
    } else
        delnode(o->ch[d],x);
    if(o!=NULL) maintain(o);//!!!
}
int Kth(Node* &o,int k){ //the Kth-smallest
    if(o==NULL || k<=0 || k>SIZE(o)) return -1;
    else if(k>SIZE(o->ch[0]) && k<=SIZE(o->ch[0])+o->cnt) return o->v;
    else if(k<=SIZE(o->ch[0])) return Kth(o->ch[0],k);
    else return Kth(o->ch[1], k-(SIZE(o->ch[0])+o->cnt) );
}
int getRank(Node* &o,int x){
    int d=o->cmp(x);
    if(d==-1) return SIZE(o->ch[0])+1;
    else return getRank(o->ch[d],x)+d*(SIZE(o->ch[0])+o->cnt);
}

inline int readint(){
    int f=1,r=0;char c=getchar();
    while(c<'0' || c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0' && c<='9'){r=r*10+c-'0';c=getchar();}
    return f*r;
}
int main(){
    srand(time(0));
    N=readint();
    while(N--) {
        opt=readint();x=readint();
        switch(opt) {
            case 1:
                insert(root,x);
                break;
            case 2:
                delnode(root,x);
                break;
            case 3:
                insert(root,x);
                printf("%d\n",getRank(root,x));
                delnode(root,x);
                break;
            case 4:
                printf("%d\n",Kth(root,x));
                break;
            case 5:
                insert(root,x);
                t=getRank(root,x);
                printf("%d\n",Kth(root,t-1));
                delnode(root,x);
                break;
            case 6:
                insert(root,x);
                t=getRank(root,x);
                cur=find(root,x);
                t+=cur->cnt;
                printf("%d\n",Kth(root,t));
                delnode(root,x);
                break;
        }
    }
}
