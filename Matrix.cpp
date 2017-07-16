//函数输入参数要复制，数组要清零
#include<bits/stdc++.h>
#define MOD 1000000007
#define REP1(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef unsigned long long ULL;
const int N=2;
typedef int Mat[N+1][N+1];//!!!
ULL Nth;
Mat M1,M2,MT;
inline void Clear(Mat x) {
    memset(x,0,sizeof(Mat));   //x is a pointer,sizeof(x)=4
}
inline void Assign(Mat x,Mat y) {
    memcpy(x,y,sizeof(Mat));   //x=y
}
inline void Unit(Mat x) {
    REP1(i,N) x[i][i]=1;
}
inline void MatMul(Mat A1,Mat B1,Mat C) {
    Mat A,B;Assign(A,A1);Assign(B,B1);
    Clear(C);
    for(int i=1; i<=N; ++i)
        for(int k=1; k<=N; ++k)
            for(int j=1; j<=N; ++j) {
                ULL t=A[i][k];t*=B[k][j];//ULL t=A[i][k]*B[k][j] <-XXX
                C[i][j]+=t%MOD;C[i][j]%=MOD;
            }
}
inline void MatPow(Mat A1,ULL x,Mat C) {
    Mat A,T;Assign(A,A1);
    Clear(C);Unit(C);
    while(x) {
        if(x&1) {Assign(T,C);MatMul(A,T,C);}
        Assign(T,A);MatMul(T,T,A);x>>=1;//A=A*A;x>>=1;
    }
}
int main() {
    scanf("%lld",&Nth);
    M1[1][1]=M1[1][2]=1;
    M2[1][1]=M2[1][2]=M2[2][1]=1;
    MatPow(M2,Nth-1,M2);
    MatMul(M1,M2,MT);
    printf("%d\n",MT[1][2]);
    return 0;
}
