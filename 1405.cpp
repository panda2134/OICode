#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

struct Point{
    int x,y;
    double getDistanceTo(const Point &);
};

const int INT_MAX=0x7fffffff;
const double DOUBLE_MAX=10e20;

int n;
double m=DOUBLE_MAX,shortestDis[5000][5000],maxShortest[5000],matrix[5000][5000];
bool isConnected[5000][5000];
Point points[5000];

int main(){
    //INPUT
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>points[i].x>>points[i].y;
    char ch;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            cin>>ch;
            if(ch=='1')
                matrix[i][j]=points[i].getDistanceTo(points[j]);
            else
                matrix[i][j]=DOUBLE_MAX;
        }
    //Floyd Init
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(matrix[i][j]>=DOUBLE_MAX-1)
                isConnected[i][j]=false;
            else
                isConnected[i][j]=true;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            shortestDis[i][j]=matrix[i][j];
    //Floyd & Warshall
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j && j!=k && i!=k)
                    if(shortestDis[i][k]<DOUBLE_MAX-1 && shortestDis[k][j]<DOUBLE_MAX-1){
                        if(shortestDis[i][j]>shortestDis[i][k]+shortestDis[k][j])
                            shortestDis[i][j]=shortestDis[i][k]+shortestDis[k][j];
                        isConnected[i][j]=isConnected[i][j] || (isConnected[i][k] && isConnected[k][j]);
                    }
    //maxShortest
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(isConnected[i][j])
                maxShortest[i]=max(maxShortest[i],shortestDis[i][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i!=j && !isConnected[i][j])
                m=min(m,maxShortest[i]+maxShortest[j]+points[i].getDistanceTo(points[j]));
    for(int i=1;i<=n;i++)
        m=max(m,maxShortest[i]);
    printf("%.6lf",m);
    return 0;
}

double Point::getDistanceTo(const Point & p){
    int xDelta=this->x-p.x,yDelta=this->y-p.y;
    return sqrt(xDelta*xDelta+yDelta*yDelta);
}
