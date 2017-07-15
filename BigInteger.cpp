#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
struct BigInteger{
	static const int MOD=100000000;
	static const int WIDTH=8;
	vector<int> v;
	void Clear(){
		while(v.back()==0 && v.size()>1) v.pop_back();
	}
	BigInteger(){v.push_back(0);}; 
	BigInteger(unsigned long long num){
		*this=num;
	}
	BigInteger(const char* str){
		*this=string(str);
	}
	BigInteger operator=(unsigned long long num){
		v.clear(); //important
		do{
			int x=num%MOD;
			num/=MOD;
			v.push_back(x);
		}while(num>0); //Push a zero when num==0
		Clear();
		return *this;
	}
	BigInteger operator=(const string & str){
		v.clear(); //important
		int x,len = (str.length()-1) / WIDTH + 1; //12345678|,12345678|9,1234567| check it by hand
		//see note
		for(int i=0;i<len;i++){
			int end=str.length()-i*WIDTH;
			int start=max(0,end-WIDTH);
			sscanf(str.substr(start,end-start).c_str(),"%d",&x);
			//substr(int start,int len)
			v.push_back(x); 
		}
		Clear();
		return *this;
	}
	BigInteger operator=(const char* str){
		*this=string(str);
	}
	friend ostream& operator<<(ostream& out,const BigInteger& x){
		out<<x.v.back(); //the zeros in the front CANNOT be printed
		for(int i=x.v.size()-2;i>=0;i--){
			char buf[20];
			sprintf(buf,"%08d",x.v[i]); //zeros cannot be omitted
			for(int j=0;j<strlen(buf);j++) out<<buf[j]; //NOT COUT!!!!!!!!!!!
		}
		return out;
	}
	friend istream& operator>>(istream& in,BigInteger& x){
		string s;
		if(!(in>>s)) return in;
		x=s;
		return in;
	}
	BigInteger operator+(const BigInteger& b) {
		BigInteger c;
		c.v.clear();
		for(int i=0,g=0;;i++){
			int x=g;
			if(g==0 && i>=v.size() && i>=b.v.size()) break;
			if(i<v.size()) x+=v[i];
			if(i<b.v.size()) x+=b.v[i];
			c.v.push_back(x%MOD);
			g=x/MOD;
		}
		this->Clear();
		return c;
	}
	BigInteger operator+=(BigInteger &b){
		return *this=*this+b;
	}
	BigInteger operator-(const BigInteger& b) {
		BigInteger c;
		c.v.clear();
		for(int i=0,g=0;;i++){
			int x=g;
			if(g==0 && i>=v.size() && i>=b.v.size()) break;
			if(i<v.size()) x+=v[i];
			if(i<b.v.size()) x-=b.v[i];
			c.v.push_back(x%MOD);
			g=x/MOD;
		}
		Clear();
		return c;
	}
}; 
int main(){
	char s1[1010],s2[1010];
	cin.getline(s1,1000,'\n');
	cin.getline(s2,1000,'\n');
	BigInteger x=s1,y=s2;
	cout<<x+y;
	return 0;
}
