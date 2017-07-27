#include <bits/stdc++.h>
using namespace std;
struct BigInteger {
	static const int MOD = 10000;
	static const int WIDTH = 4;
	static const int MAXL = 1000;
	int v[MAXL+10],sz;
	void Clear() {
		while(sz>1 && v[sz-1]==0) sz--;
	}
	BigInteger(){
		sz=0;v[sz++]=0;
	}
	BigInteger operator=(const string& str){
		sz=0;
		int len=str.length()/WIDTH + (bool)str.length()%WIDTH;
		for(int i=1;i<=len;i++){//1|2345|6789
			int end=str.length()-(i-1)*WIDTH;
			int start=max(0,(int)str.length()-i*WIDTH);
			v[sz++]=atoi(str.substr(start,end-start).c_str());
		}
		Clear();
		return *this;
	}
	BigInteger operator=(unsigned long long x){
		sz=0;
		do{
			v[sz++]=x%MOD;
			x/=MOD;
		}while(x!=0);
		Clear();
		return *this;
	}
	BigInteger operator=(const char *str){
		return *this=string(str);
	}
	BigInteger(const string& str){
		*this=str;
	}
	BigInteger(unsigned long long x){
		*this=x;
	}
	BigInteger(const char *str){
		*this=str;
	}
	
	BigInteger operator+(const BigInteger& b){
		BigInteger c;
		c.sz=0;
		for(int i=0,g=0;;i++){
			int x=g;
			if(g==0 && i>=sz && i>=b.sz) break;
			if(i<sz) x+=v[i];
			if(i<b.sz) x+=b.v[i];
			c.v[c.sz++]=x%MOD;
			g=x/MOD;
		}
		c.Clear();
		return c;
	}
	
	BigInteger operator-(const BigInteger& b){
		BigInteger c;c.sz=0;
		for(int i=0,g=0;;i++){
			int x=g;
			if(g==0 && i>=sz && i>=b.sz) break;
			if(i<sz) x+=v[i];
			if(i<b.sz) x-=b.v[i];
			c.v[c.sz++]=(x+MOD)%MOD;
			g=x/MOD-(x<0);
		}
		c.Clear();
		return c;
	}
	
	
	BigInteger operator*(const BigInteger& b){
		static int tmp[MAXL+10][MAXL+10],pos[MAXL+10];
		//STATIC !!!!!!!!!!!!
		BigInteger c;c.sz=sz+b.sz;
		memset(c.v,0,sizeof(c.v));
		memset(tmp,0,sizeof(tmp));
		memset(pos,0,sizeof(pos));
		for(int i=0;i<b.sz;i++)
			for(int j=0,g=0;;j++){
				int x=g;
				if(g==0 && j>=sz) break;
				if(j<sz) x+=v[j]*b.v[i];
				g=x/MOD;
				tmp[i][pos[i]++]=x%MOD;
			}
		for(int i=0;i<b.sz;i++)
			for(int j=0;j<pos[i];j++)
				c.v[i+j]+=tmp[i][j];
		for(int i=0,g=0;;i++){
			int x=g;
			if(g==0 && i>=sz+b.sz) break;
			if(i<sz+b.sz) x+=c.v[i];
			g=x/MOD;
			c.v[i]=x%MOD;
		}
		c.Clear();
		return c;
	}
	friend istream& operator>>(istream& in,BigInteger& b){
		static char tmp[MAXL*WIDTH];
		if(!(in>>tmp)) return in;
		b=tmp;return in;
	}
	friend ostream& operator<<(ostream& out,const BigInteger& b){
		out<<b.v[b.sz-1];
		static char tmp[MAXL*WIDTH];
		for(int i=b.sz-2;i>=0;i--){
			sprintf(tmp,"%04d",b.v[i]);
			out<<tmp;
		}
		return out;
	}
	bool operator<(const BigInteger& b)const{
		if(sz<b.sz) return true;
		if(sz>b.sz) return false;
		for(int i=sz-1;i>=0;i--){
			if(v[i]>b.v[i]) return false;
			if(v[i]<b.v[i]) return true;
			if(v[i]==b.v[i]) continue;
		}
		return false;
	}
	bool operator>(const BigInteger& b)const{
		if(sz>b.sz) return true;
		if(sz<b.sz) return false;
		for(int i=sz-1;i>=0;i--){
			if(v[i]<b.v[i]) return false;
			if(v[i]>b.v[i]) return true;
			if(v[i]==b.v[i]) continue;
		}
		return false;
	}
	bool operator==(const BigInteger& b)const{
		return !(*this<b) && !(*this>b);
	}
};
int main(){
}
