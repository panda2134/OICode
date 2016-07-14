#include<iostream>
#include<algorithm>
using namespace std;
struct Item{
	int v,p,q;
	Item *son1,*son2;
};
int n,m;
Item items[100];
int d[100][30010];
int main(){
	cin>>n>>m;
	int v,p,q;
	for(int i=1;i<=m;i++){
		cin>>v>>p>>q;
		if(!q){
			items[i].v=v;
			items[i].p=p;
			items[i].q=q;
			//cout<<"i="<<i<<","<<"main"<<endl;
		}else if(!items[q].son1){
			items[q].son1=new Item();
			items[q].son1->v=v;
			items[q].son1->p=p;
			items[q].son1->q=q;
			//cout<<"i="<<i<<","<<"sub1"<<endl;
		}else{
			items[q].son2=new Item();
			items[q].son2->v=v;
			items[q].son2->p=p;
			items[q].son2->q=q;
			//cout<<"i="<<i<<","<<"sub2"<<endl; 
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(items[i].v<=j)
				d[i][j]=max(d[i-1][j],d[i-1][j-items[i].v] + items[i].v*items[i].p);
			if(items[i].son1!=NULL && items[i].v!=0 && items[i].v+items[i].son1->v<=j)
				d[i][j]=max(d[i][j], d[i-1][j -items[i].v -items[i].son1->v] +items[i].v*items[i].p +items[i].son1->v * items[i].son1->p);
			if(items[i].son2!=NULL && items[i].v!=0 && items[i].v+items[i].son2->v<=j)
				d[i][j]=max(d[i][j], d[i-1][j -items[i].v -items[i].son2->v] +items[i].v*items[i].p +items[i].son2->v * items[i].son2->p);
			if(items[i].son1!=NULL && items[i].v!=0 && items[i].son2!=NULL && items[i].v+items[i].son1->v+items[i].son2->v<=j)
				d[i][j]=max(d[i][j], d[i-1][j -items[i].v -items[i].son1->v -items[i].son2->v] +items[i].v*items[i].p +items[i].son1->v*items[i].son1->p +items[i].son2->v*items[i].son2->p);
			d[i][j]=max(d[i][j],d[i-1][j]);
		}
	}
	cout<<d[m][n];
	return 0;
}
