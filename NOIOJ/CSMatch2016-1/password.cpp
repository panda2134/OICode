#include<cstdio>
#include<cstring>
using namespace std; 
inline void changePass(char *pass){
	while(*pass){
		if(*pass>='A' && *pass<='Z') *pass+=32;
		else if(*pass>='a' && *pass<='z') *pass-=32;
		pass++;
	}
}
int main(){
	int n;bool isEmpty=true;
	char email[55],username[55],password[55],curEmail[55];
	scanf("%s",email);
	scanf("%d",&n);
	while(n--){
		scanf("%s%s%s",username,password,curEmail);
		if(strcmp(email,curEmail)==0){
			isEmpty=false;
			changePass(password);
			printf("%s %s\n",username,password);
		}
	}
	if(isEmpty) printf("empty\n");
	return 0;
}
